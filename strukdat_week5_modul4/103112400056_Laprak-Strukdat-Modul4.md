# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Felix Pedrosa Valentino - 103112400056</p>

## Dasar Teori
Singly Linked List adalah salah satu jenis struktur data dinamis yang digunakan untuk menampung sekumpulan data secara berurutan, di mana setiap elemen atau node saling terhubung melalui pointer [1]. Berbeda dengan array yang memiliki ukuran tetap, linked list bersifat lebih adaptif karena memungkinkan penambahan atau penghapusan elemen tanpa harus menggeser elemen lain di dalam memori. Hal ini menjadikan linked list lebih hemat dalam penggunaan memori, terutama ketika ukuran data tidak dapat diketahui sebelumnya [2].

Pada Singly Linked List, setiap node terdiri dari dua komponen utama, yaitu data field yang menyimpan nilai atau informasi dan pointer field (sering disebut next) yang menunjuk ke node selanjutnya [3]. Elemen pertama dalam daftar dikenal sebagai head, sementara elemen terakhir memiliki pointer dengan nilai NULL yang menandakan akhir dari daftar tersebut. Karena arah pointer hanya satu arah (dari depan ke belakang), proses pencarian data hanya dapat dilakukan dari head menuju tail [4].

Pengaplikasian Singly Linked List dalam bahasa C++ umumnya dilakukan dengan memanfaatkan struct atau class untuk merepresentasikan node dan fungsi-fungsi untuk menjalankan operasi-operasi dasar seperti pembuatan list, penambahan data di awal atau di akhir, penghapusan data, serta penelusuran list [5].

## Guided 

### 1. Guided 1

list.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

Program ini berfungsi untuk mengelola data mahasiswa, yang mencakup nama, NIM, dan umur. File header list.h mendefinisikan struktur data seperti node dan linked list, serta deklarasi fungsi-fungsi dasar seperti pemeriksaan list kosong, alokasi node, penyisipan node (di awal, setelah node tertentu, atau di akhir), dan pencetakan isi list. File list.cpp menyediakan implementasi lengkap dari fungsi-fungsi tersebut, memastikan operasi manajemen memori dan manipulasi list berjalan dengan benar. Di main.cpp, program utama membuat sebuah linked list kosong, mengalokasikan beberapa node mahasiswa, menyisipkan mereka ke dalam list menggunakan fungsi insert yang sesuai, dan akhirnya mencetak seluruh isi list untuk menampilkan data yang telah ditambahkan. Secara keseluruhan, program ini mendemonstrasikan penggunaan linked list untuk penyimpanan dan pengelolaan data struktural secara efisien. 

### 2. Guided 2

list.h
```C++
// list.h

//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

list.cpp
```C++
// list.cpp

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```

main.cpp
```C++
// main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

Program ini berfungsi untuk mengelola data mahasiswa, yang mencakup nama, NIM, dan umur. File header list.h mendefinisikan struktur data seperti node dan linked list, serta deklarasi fungsi untuk operasi dasar seperti pemeriksaan list kosong, alokasi node, penyisipan node (di awal, setelah node tertentu, atau di akhir), penghapusan node (dari awal, akhir, atau setelah node tertentu), penghitungan jumlah node, penghapusan seluruh list, dan pencetakan isi list. File list.cpp menyediakan implementasi dari fungsi-fungsi tersebut, memastikan pengelolaan memori dan manipulasi list berjalan efisien. Di main.cpp, program utama membuat sebuah linked list kosong, menambahkan beberapa node mahasiswa, mencetak isi list dan jumlah node, kemudian melakukan penghapusan node tertentu serta penghapusan seluruh list, sambil menampilkan hasil pada setiap tahap untuk mendemonstrasikan fungsionalitas secara keseluruhan.

## Unguided 

### 1. Soal Unguided 1 
Buatlah ADT Singly Linked list sebagai berikut di dalam file "Singlylist.h" 
Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file "Singlylist.cpp" 
Kemudian buat program utama didalam file "main.cpp" dengan implementasi sebagai berikut: 

Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

// Deklarasi fungsi dan prosedur
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif
```

Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
    } else {
        P->next = L.First;
        L.First = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
```

main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```

### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week5_modul4/output-unguided1-modul4.png) 

Program ini terdiri atas tiga file, yaitu Singlylist.h, Singlylist.cpp, dan main.cpp. Pada file Singlylist.h didefinisikan struktur data ElmList yang merepresentasikan simpul (node) dengan dua elemen utama, yaitu info untuk menyimpan data bertipe integer dan next sebagai pointer ke elemen berikutnya. Selain itu, didefinisikan juga struktur List yang memiliki pointer First sebagai penunjuk elemen pertama dalam list. File Singlylist.cpp berisi implementasi fungsi dan prosedur seperti createList untuk membuat list kosong, alokasi untuk membuat elemen baru, dealokasi untuk menghapus elemen, insertFirst untuk menambahkan elemen di awal list, serta printInfo untuk menampilkan seluruh isi list. Sementara itu, file main.cpp berfungsi sebagai program utama yang menguji semua operasi tersebut dengan membuat beberapa elemen baru dan menambahkannya ke dalam list menggunakan prosedur insertFirst. Hasil akhir dari program ini adalah tampilan data pada list secara berurutan dari depan ke belakang, yaitu 9 12 8 0 2, yang menunjukkan urutan simpul dalam singly linked list.

### 2. Soal Unguided 2 
Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList(). 

Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

// Deklarasi fungsi dan prosedur
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertLast(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteList(List &L);
int nbList(List L);
void printInfo(List L);

#endif
```

Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
    } else {
        address Q = L.First;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        P = L.First;
        L.First = L.First->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First != Nil) {
        if (L.First->next == Nil) {
            P = L.First;
            L.First = Nil;
        } else {
            address Q = L.First;
            while (Q->next->next != Nil) {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = Nil;
        }
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
```

main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    address Pdel, Prec;

    createList(L);

    // Membuat list 9 -> 12 -> 8 -> 0 -> 2
    insertLast(L, alokasi(9));
    insertLast(L, alokasi(12));
    insertLast(L, alokasi(8));
    insertLast(L, alokasi(0));
    insertLast(L, alokasi(2));

    // Hapus node 9 menggunakan deleteFirst()
    deleteFirst(L, Pdel);
    dealokasi(Pdel);

    // Hapus node 2 menggunakan deleteLast()
    deleteLast(L, Pdel);
    dealokasi(Pdel);

    // Hapus node 8 menggunakan deleteAfter()
    Prec = L.First;       // Prec menunjuk ke node 12
    deleteAfter(L, Prec, Pdel);
    dealokasi(Pdel);

    // Tampilkan sisa list
    printInfo(L);

    // Tampilkan jumlah node
    cout << "Jumlah node : " << nbList(L) << endl << endl;

    // Hapus seluruh list
    deleteList(L);

    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
``` 

### Output Unguided 2 :

![Screenshot Output Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week5_modul4/output-unguided2-modul4.png) 

Program ini terdiri dari tiga file utama, yaitu Singlylist.h, Singlylist.cpp, dan main.cpp. File Singlylist.h berfungsi sebagai header file yang berisi deklarasi struktur data ElmList dan List, serta prototipe fungsi dan prosedur untuk mengelola linked list seperti pembuatan list, alokasi dan dealokasi node, penambahan dan penghapusan elemen, serta pencetakan isi list. File Singlylist.cpp berisi definisi dari fungsi dan prosedur tersebut, di mana setiap operasi pada list diimplementasikan, seperti insertLast() untuk menambahkan elemen di akhir list, deleteFirst(), deleteLast(), dan deleteAfter() untuk menghapus elemen dari posisi tertentu, serta deleteList() untuk menghapus seluruh node dalam list. Pada main.cpp, program utama membuat sebuah list berisi data 9 → 12 → 8 → 0 → 2, kemudian melakukan operasi penghapusan elemen menggunakan tiga prosedur penghapusan berbeda dan menampilkan hasil akhir list beserta jumlah node yang tersisa. Setelah seluruh operasi selesai, list dihapus sepenuhnya untuk mengosongkan memori. 

## Kesimpulan
Singly Linked List hadir sebagai struktur data dinamis yang efisien untuk menyimpan dan mengelola data secara berurutan, dengan keunggulan adaptif dibandingkan array karena memungkinkan penambahan atau penghapusan elemen tanpa menggeser data lain, sehingga lebih hemat memori terutama untuk ukuran data yang tidak tetap. Setiap node dalam list ini terdiri dari field data untuk menyimpan informasi dan field pointer untuk menghubungkan ke node selanjutnya, dengan head sebagai titik awal dan pointer NULL pada elemen terakhir untuk menandai akhir. Meskipun navigasi hanya berlangsung satu arah dari head ke tail, hal ini membuatnya sederhana dan ringan untuk operasi dasar seperti pencarian berurutan. 

## Referensi
[1] Munir, R. (2019). Algoritma dan Struktur Data. Bandung: Informatika. 
<br>
[2] Wirth, N. (2017). Algorithms + Data Structures = Programs. Prentice Hall.
<br>
[3] Malik, D. S. (2018). Data Structures Using C++. Cengage Learning.
<br>
[4] Goodrich, M. T., Tamassia, R., & Mount, D. M. (2011). Data Structures and Algorithms in C++. John Wiley & Sons.
<br>
[5] Sedgewick, R., & Wayne, K. (2014). Algorithms (4th Edition). Addison-Wesley. 
