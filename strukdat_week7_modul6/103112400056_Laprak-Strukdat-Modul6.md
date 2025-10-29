# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA) </h1>
<p align="center">Felix Pedrosa Valentino - 103112400056</p>

## Dasar Teori 
Doubly Linked List atau linked list berantai ganda merupakan salah satu struktur data linear yang terdiri dari sekumpulan node yang saling terhubung secara berurutan [1]. Berbeda dengan Single Linked List yang hanya memiliki satu pointer penunjuk ke node berikutnya, Doubly Linked List memiliki dua pointer pada setiap node, yaitu pointer next yang menunjuk ke node selanjutnya dan pointer prev yang menunjuk ke node sebelumnya [2]. Struktur data ini memungkinkan traversal atau penelusuran data dapat dilakukan secara dua arah, baik dari depan ke belakang maupun dari belakang ke depan, sehingga memberikan fleksibilitas yang lebih besar dalam manipulasi data [3]. 

Setiap node dalam Doubly Linked List memiliki tiga komponen utama, yaitu data yang menyimpan informasi atau nilai, pointer next yang berisi alamat memori dari node berikutnya dalam linked list, dan pointer prev yang berisi alamat memori dari node sebelumnya [1]. Node pertama dalam linked list disebut sebagai head, di mana pointer prev dari head menunjuk ke NULL karena tidak ada node sebelumnya [2]. Sedangkan node terakhir disebut tail, dengan pointer next yang menunjuk ke NULL karena tidak ada node sesudahnya [4]. Struktur ini membentuk rantai dua arah yang memfasilitasi operasi penyisipan dan penghapusan node dengan lebih efisien dibandingkan dengan struktur data array [3]. 

Implementasi Doubly Linked List dalam bahasa pemrograman C++ dapat dilakukan dengan mendefinisikan sebuah class atau struct untuk merepresentasikan node [5]. Setiap node dideklarasikan dengan tipe data tertentu untuk menyimpan informasi, serta dua pointer bertipe node untuk menunjuk ke node sebelumnya dan node berikutnya [1]. Penggunaan pointer dalam C++ memungkinkan alokasi memori secara dinamis menggunakan operator new, sehingga ukuran linked list dapat berubah-ubah sesuai kebutuhan selama runtime program [4]. Hal ini menjadi salah satu keunggulan utama linked list dibandingkan dengan array yang memiliki ukuran tetap [2]. 

Operasi-operasi dasar yang dapat dilakukan pada Doubly Linked List meliputi insertion atau penyisipan node, deletion atau penghapusan node, searching atau pencarian data, dan traversal atau penelusuran seluruh elemen [3]. Operasi insertion dapat dilakukan pada tiga posisi, yaitu di awal linked list dengan mengubah head, di akhir linked list dengan mengubah tail, atau di tengah linked list pada posisi tertentu dengan mengatur ulang pointer prev dan next dari node-node yang berdekatan [5]. Operasi deletion juga dapat dilakukan pada ketiga posisi tersebut dengan cara membebaskan memori yang dialokasikan untuk node yang akan dihapus menggunakan operator delete, kemudian mengatur ulang pointer dari node-node tetangganya agar tetap terhubung [1]. 

Kompleksitas waktu untuk operasi-operasi pada Doubly Linked List memiliki karakteristik yang berbeda-beda tergantung pada jenis operasinya [4]. Operasi insertion dan deletion pada posisi awal atau akhir linked list memiliki kompleksitas waktu O(1) karena dapat dilakukan secara langsung melalui pointer head atau tail [3]. Namun, untuk operasi insertion dan deletion pada posisi tengah, serta operasi searching, memiliki kompleksitas waktu O(n) karena memerlukan traversal dari awal hingga menemukan posisi atau data yang dicari [2]. Meskipun demikian, Doubly Linked List tetap lebih efisien dibandingkan Single Linked List dalam hal penghapusan node karena tidak perlu mencari node sebelumnya, karena sudah tersedia melalui pointer prev [5]. 

Kelebihan utama dari Doubly Linked List adalah kemampuannya untuk melakukan traversal dua arah dengan mudah, yang sangat berguna dalam implementasi struktur data seperti browser history, undo-redo functionality, atau music playlist [1]. Selain itu, operasi penghapusan node lebih efisien karena dapat langsung mengakses node sebelumnya tanpa harus melakukan traversal dari awal [3]. Doubly Linked List juga memudahkan implementasi operasi reverse atau pembalikan urutan elemen karena setiap node sudah memiliki referensi ke node sebelumnya [4]. Namun, struktur data ini juga memiliki kekurangan, yaitu memerlukan memori tambahan untuk menyimpan pointer prev pada setiap node, sehingga konsumsi memori lebih besar dibandingkan Single Linked List [2]. Selain itu, kompleksitas implementasi juga lebih tinggi karena harus mengatur dua pointer pada setiap operasi, yang meningkatkan kemungkinan terjadinya kesalahan dalam pemrograman [5]. 

## Guided 

### 1. Guided 1

listMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

listMakanan.cpp 
```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List) == true){ 
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}
```

main.cpp 
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
} 
```

Program ini merupakan implementasi doubly linked list dalam bahasa C++ untuk mengelola data makanan, di mana setiap node menyimpan informasi berupa nama, jenis, harga, dan rating makanan. Struktur program terdiri dari tiga file utama: header file (listMakanan.h) yang mendefinisikan struktur data seperti struct makanan, node, dan linkedlist; file implementasi (listMakanan.cpp) yang berisi fungsi-fungsi operasional seperti alokasi dan dealokasi node, penyisipan (insertFirst, insertLast, insertAfter, insertBefore), pencetakan list (printList), serta pembaruan data (updateFirst, updateLast, updateAfter, updateBefore); dan file utama (main.cpp) yang mendemonstrasikan penggunaan list dengan membuat objek linkedlist, mengalokasikan lima node makanan (seperti Nasi Rames, Ayam Geprek, dll.), melakukan penyisipan secara berurutan untuk membentuk urutan D-A-C-E-B, mencetak isi list, kemudian melakukan pembaruan pada node pertama, terakhir, sebelum C, dan setelah C, sebelum mencetak hasil akhir. 

### 2. Guided 2

Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif 
```

Doublylist.cpp 
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```

main.cpp 
```C++
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);

    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}
```

Program ini merupakan implementasi doubly linked list dalam bahasa C++ untuk mengelola data kendaraan, di mana setiap elemen list menyimpan informasi nomor polisi, warna, dan tahun pembuatan kendaraan. Struktur program terdiri dari tiga file utama: header file (Doublylist.h) yang mendefinisikan struktur data seperti struct kendaraan, ElmList, dan List; file implementasi (Doublylist.cpp) yang berisi fungsi-fungsi operasional termasuk pembuatan list kosong (CreateList), alokasi dan dealokasi elemen (alokasi dan dealokasi), penyisipan di akhir list (insertLast), pencarian elemen berdasarkan nomor polisi (findElm), penghapusan elemen berdasarkan nomor polisi (deleteByNopol) dengan penanganan berbagai kasus (elemen tunggal, pertama, terakhir, atau tengah), serta pencetakan isi list (printInfo); dan file utama (main.cpp) yang mendemonstrasikan penggunaan list dengan membuat objek List, menambahkan tiga kendaraan (D001, D003, D004), mencetak data awal, mencari kendaraan dengan nopol D001, menghapus kendaraan dengan nopol D003, mencetak data setelah penghapusan, kemudian menghapus elemen pertama (D001), dan mencetak hasil akhir. 

## Unguided 

### 1. Soal Unguided 1 
Buatlah ADT Doubly Linked list sebagai berikut didalam file “Doublylist.h”: 
 ```C++
Type infotype: kendaraan <
 nopol :string
 warna :string
 thnBuat:integer
 >
 Type address :pointer to ElmList
 Type ElmList <
 info:infotype
 next:address
 prev:address
 >
 Type List <
 First :address
 Last:address
 >
 procedure CreateList( input/output L: List)
 function alokasi( x : infotype ) → address
 procedure dealokasi( input/output P : address )
 procedure printInfo( input L :List )
 procedure insertLast( input/output L :List, input P : address)
```
Buatlah implementasi ADT Doubly Linked list pada file “Doublylist.cpp” dan coba hasil implementasi ADT pada file “main.cpp”.

Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan {
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};

// Tipe list
struct List {
    address first;
    address last;
};

// Prototypes
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);

// Fungsi untuk soal nomor 2
address findElm(List L, string nopol);

// Prosedur untuk soal nomor 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```

Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "Nomor Polisi : " << P->info.nopol << endl;
            cout << "Warna        : " << P->info.warna << endl;
            cout << "Tahun        : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}

// SOAL NOMOR 2: Fungsi untuk mencari elemen berdasarkan nomor polisi
address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// SOAL NOMOR 3: Prosedur deleteFirst
void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.first;
        L.first = P->next;
        (L.first)->prev = Nil;
        P->next = Nil;
    }
}

// SOAL NOMOR 3: Prosedur deleteLast
void deleteLast(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.last;
        L.last = P->prev;
        (L.last)->next = Nil;
        P->prev = Nil;
    }
}

// SOAL NOMOR 3: Prosedur deleteAfter
void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            (P->next)->prev = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    } else {
        P = Nil;
    }
}
```

main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    
    // ===== SOAL NOMOR 1: Input Data Kendaraan dari Pengguna =====
    int n;
    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;
    
    int i = 0;
    while (i < n) {
        infotype data;
        cout << "\nKendaraan ke-" << (i+1) << endl;
        cout << "Nomor Polisi: ";
        cin >> data.nopol;
        cout << "Warna: ";
        cin >> data.warna;
        cout << "Tahun: ";
        cin >> data.thnBuat;
        
        // Cek apakah nomor polisi sudah terdaftar
        address cek = L.first;
        bool sudahAda = false;
        
        while (cek != Nil) {
            if (cek->info.nopol == data.nopol) {
                cout << "Nomor polisi " << data.nopol << " sudah terdaftar!" << endl;
                sudahAda = true;
                break;
            }
            if (cek->info.warna == data.warna) {
                cout << "Warna " << data.warna << " sudah terdaftar!" << endl;
                sudahAda = true;
                break;
            }
            if (cek->info.thnBuat == data.thnBuat) {
                cout << "Tahun " << data.thnBuat << " sudah terdaftar!" << endl;
                sudahAda = true;
                break;
            }
            cek = cek->next;
        }
        
        if (!sudahAda) {
            address P = alokasi(data);
            insertLast(L, P);
            i++; // Hanya increment jika data berhasil ditambahkan
        }
        // Jika sudah ada, loop akan mengulang input untuk kendaraan ke-i yang sama
    }
    
    cout << "\n=== DATA LIST KENDARAAN ===" << endl;
    printInfo(L);
    
    // ===== SOAL NOMOR 2: Mencari Elemen dengan Nomor Polisi =====
    string cariNopol;
    cout << "Masukkan Nomor Polisi yang dicari\t: ";
    cin >> cariNopol;
    cout << endl;
    
    address found = findElm(L, cariNopol);
    if (found != Nil) {
        cout << "Nomor Polisi\t: " << found->info.nopol << endl;
        cout << "Warna\t\t: " << found->info.warna << endl;
        cout << "Tahun\t\t: " << found->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << cariNopol << " tidak ditemukan." << endl;
    }
    
    // ===== SOAL NOMOR 3: Menghapus Data dengan Nomor Polisi =====
    string hapusNopol;
    cout << "\nMasukkan nomor polisi yang akan dihapus\t: ";
    cin >> hapusNopol;
    
    // Cari elemen yang akan dihapus
    address foundDelete = findElm(L, hapusNopol);
    
    if (foundDelete != Nil) {
        address P = Nil;
        
        // Tentukan posisi elemen yang akan dihapus
        if (foundDelete == L.first) {
            // Hapus elemen pertama
            deleteFirst(L, P);
        } else if (foundDelete == L.last) {
            // Hapus elemen terakhir
            deleteLast(L, P);
        } else {
            // Hapus elemen di tengah (setelah predecessor)
            address Prec = foundDelete->prev;
            deleteAfter(Prec, P);
        }
        
        if (P != Nil) {
            cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus." << endl;
            dealokasi(P);
        }
        
        cout << "\n=== DATA LIST SETELAH PENGHAPUSAN ===" << endl;
        printInfo(L);
    } else {
        cout << "\nData dengan nomor polisi " << hapusNopol << " tidak ditemukan." << endl;
    }
    
    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week7_modul6/output1-unguided1-modul6.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week7_modul6/output2-unguided1-modul6.png)

Program meminta pengguna untuk memasukkan jumlah kendaraan yang akan diinput, kemudian melakukan proses input data secara iteratif untuk setiap kendaraan yang meliputi nomor polisi, warna, dan tahun pembuatan. Sebelum data disimpan ke dalam list, program melakukan validasi untuk memastikan tidak ada duplikasi data dengan cara memeriksa apakah nomor polisi, warna, atau tahun yang diinput sudah terdaftar dalam list. Jika ditemukan data yang sudah terdaftar, program akan menampilkan pesan peringatan dan meminta pengguna untuk menginput ulang data tersebut tanpa menambah counter kendaraan. Data yang valid akan dialokasikan ke dalam node baru menggunakan fungsi alokasi, kemudian dimasukkan ke dalam doubly linked list menggunakan prosedur insertLast yang menambahkan elemen di akhir list. Setelah semua data berhasil diinput, program menampilkan seluruh isi list kendaraan yang telah tersimpan dengan format yang rapi menggunakan prosedur printInfo. 

### 2. Soal Unguided 2 
Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address 

Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan {
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};

// Tipe list
struct List {
    address first;
    address last;
};

// Prototypes
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);

// Fungsi untuk soal nomor 2
address findElm(List L, string nopol);

// Prosedur untuk soal nomor 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```

Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "Nomor Polisi : " << P->info.nopol << endl;
            cout << "Warna        : " << P->info.warna << endl;
            cout << "Tahun        : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}

// SOAL NOMOR 2: Fungsi untuk mencari elemen berdasarkan nomor polisi
address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// SOAL NOMOR 3: Prosedur deleteFirst
void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.first;
        L.first = P->next;
        (L.first)->prev = Nil;
        P->next = Nil;
    }
}

// SOAL NOMOR 3: Prosedur deleteLast
void deleteLast(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.last;
        L.last = P->prev;
        (L.last)->next = Nil;
        P->prev = Nil;
    }
}

// SOAL NOMOR 3: Prosedur deleteAfter
void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            (P->next)->prev = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    } else {
        P = Nil;
    }
}
```

main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    
    // ===== SOAL NOMOR 1: Input Data Kendaraan dari Pengguna =====
    int n;
    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;
    
    int i = 0;
    while (i < n) {
        infotype data;
        cout << "\nKendaraan ke-" << (i+1) << endl;
        cout << "Nomor Polisi: ";
        cin >> data.nopol;
        cout << "Warna: ";
        cin >> data.warna;
        cout << "Tahun: ";
        cin >> data.thnBuat;
        
        // Cek apakah nomor polisi sudah terdaftar
        address cek = L.first;
        bool sudahAda = false;
        
        while (cek != Nil) {
            if (cek->info.nopol == data.nopol) {
                cout << "Nomor polisi " << data.nopol << " sudah terdaftar!" << endl;
                sudahAda = true;
                break;
            }
            if (cek->info.warna == data.warna) {
                cout << "Warna " << data.warna << " sudah terdaftar!" << endl;
                sudahAda = true;
                break;
            }
            if (cek->info.thnBuat == data.thnBuat) {
                cout << "Tahun " << data.thnBuat << " sudah terdaftar!" << endl;
                sudahAda = true;
                break;
            }
            cek = cek->next;
        }
        
        if (!sudahAda) {
            address P = alokasi(data);
            insertLast(L, P);
            i++; // Hanya increment jika data berhasil ditambahkan
        }
        // Jika sudah ada, loop akan mengulang input untuk kendaraan ke-i yang sama
    }
    
    cout << "\n=== DATA LIST KENDARAAN ===" << endl;
    printInfo(L);
    
    // ===== SOAL NOMOR 2: Mencari Elemen dengan Nomor Polisi =====
    string cariNopol;
    cout << "Masukkan Nomor Polisi yang dicari\t: ";
    cin >> cariNopol;
    cout << endl;
    
    address found = findElm(L, cariNopol);
    if (found != Nil) {
        cout << "Nomor Polisi\t: " << found->info.nopol << endl;
        cout << "Warna\t\t: " << found->info.warna << endl;
        cout << "Tahun\t\t: " << found->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << cariNopol << " tidak ditemukan." << endl;
    }
    
    // ===== SOAL NOMOR 3: Menghapus Data dengan Nomor Polisi =====
    string hapusNopol;
    cout << "\nMasukkan nomor polisi yang akan dihapus\t: ";
    cin >> hapusNopol;
    
    // Cari elemen yang akan dihapus
    address foundDelete = findElm(L, hapusNopol);
    
    if (foundDelete != Nil) {
        address P = Nil;
        
        // Tentukan posisi elemen yang akan dihapus
        if (foundDelete == L.first) {
            // Hapus elemen pertama
            deleteFirst(L, P);
        } else if (foundDelete == L.last) {
            // Hapus elemen terakhir
            deleteLast(L, P);
        } else {
            // Hapus elemen di tengah (setelah predecessor)
            address Prec = foundDelete->prev;
            deleteAfter(Prec, P);
        }
        
        if (P != Nil) {
            cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus." << endl;
            dealokasi(P);
        }
        
        cout << "\n=== DATA LIST SETELAH PENGHAPUSAN ===" << endl;
        printInfo(L);
    } else {
        cout << "\nData dengan nomor polisi " << hapusNopol << " tidak ditemukan." << endl;
    }
    
    return 0;
}
```

### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week7_modul6/output-unguided2-modul6.png)

Program meminta pengguna untuk memasukkan nomor polisi yang ingin dicari, kemudian menggunakan fungsi findElm untuk melakukan pencarian secara linear dengan melakukan traversal dari elemen pertama hingga akhir list. Fungsi ini membandingkan nomor polisi yang dicari dengan setiap nomor polisi yang ada di dalam list. Jika ditemukan kecocokan, fungsi akan mengembalikan alamat node yang berisi data tersebut, dan program menampilkan informasi lengkap kendaraan yang ditemukan meliputi nomor polisi, warna, dan tahun pembuatan dengan format output yang menggunakan tab untuk alignment yang rapi. Apabila nomor polisi yang dicari tidak ditemukan dalam list, fungsi akan mengembalikan nilai Nil dan program menampilkan pesan bahwa data tidak ditemukan. 

### 3. Soal Unguided 3 
 Hapus elemen dengan nomor polisi D003 dengan procedure delete.
- procedure deleteFirst( input/output L : List, P : address )
- procedure deleteLast( input/output L : List, P : address )
- procedure deleteAfter( input Prec : address, input/output P : address ) 

Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan {
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};

// Tipe list
struct List {
    address first;
    address last;
};

// Prototypes
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);

// Fungsi untuk soal nomor 2
address findElm(List L, string nopol);

// Prosedur untuk soal nomor 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```

Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "Nomor Polisi : " << P->info.nopol << endl;
            cout << "Warna        : " << P->info.warna << endl;
            cout << "Tahun        : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}

// SOAL NOMOR 2: Fungsi untuk mencari elemen berdasarkan nomor polisi
address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// SOAL NOMOR 3: Prosedur deleteFirst
void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.first;
        L.first = P->next;
        (L.first)->prev = Nil;
        P->next = Nil;
    }
}

// SOAL NOMOR 3: Prosedur deleteLast
void deleteLast(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.last;
        L.last = P->prev;
        (L.last)->next = Nil;
        P->prev = Nil;
    }
}

// SOAL NOMOR 3: Prosedur deleteAfter
void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            (P->next)->prev = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    } else {
        P = Nil;
    }
}
```

main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    
    // ===== SOAL NOMOR 1: Input Data Kendaraan dari Pengguna =====
    int n;
    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;
    
    int i = 0;
    while (i < n) {
        infotype data;
        cout << "\nKendaraan ke-" << (i+1) << endl;
        cout << "Nomor Polisi: ";
        cin >> data.nopol;
        cout << "Warna: ";
        cin >> data.warna;
        cout << "Tahun: ";
        cin >> data.thnBuat;
        
        // Cek apakah nomor polisi sudah terdaftar
        address cek = L.first;
        bool sudahAda = false;
        
        while (cek != Nil) {
            if (cek->info.nopol == data.nopol) {
                cout << "Nomor polisi " << data.nopol << " sudah terdaftar!" << endl;
                sudahAda = true;
                break;
            }
            if (cek->info.warna == data.warna) {
                cout << "Warna " << data.warna << " sudah terdaftar!" << endl;
                sudahAda = true;
                break;
            }
            if (cek->info.thnBuat == data.thnBuat) {
                cout << "Tahun " << data.thnBuat << " sudah terdaftar!" << endl;
                sudahAda = true;
                break;
            }
            cek = cek->next;
        }
        
        if (!sudahAda) {
            address P = alokasi(data);
            insertLast(L, P);
            i++; // Hanya increment jika data berhasil ditambahkan
        }
        // Jika sudah ada, loop akan mengulang input untuk kendaraan ke-i yang sama
    }
    
    cout << "\n=== DATA LIST KENDARAAN ===" << endl;
    printInfo(L);
    
    // ===== SOAL NOMOR 2: Mencari Elemen dengan Nomor Polisi =====
    string cariNopol;
    cout << "Masukkan Nomor Polisi yang dicari\t: ";
    cin >> cariNopol;
    cout << endl;
    
    address found = findElm(L, cariNopol);
    if (found != Nil) {
        cout << "Nomor Polisi\t: " << found->info.nopol << endl;
        cout << "Warna\t\t: " << found->info.warna << endl;
        cout << "Tahun\t\t: " << found->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << cariNopol << " tidak ditemukan." << endl;
    }
    
    // ===== SOAL NOMOR 3: Menghapus Data dengan Nomor Polisi =====
    string hapusNopol;
    cout << "\nMasukkan nomor polisi yang akan dihapus\t: ";
    cin >> hapusNopol;
    
    // Cari elemen yang akan dihapus
    address foundDelete = findElm(L, hapusNopol);
    
    if (foundDelete != Nil) {
        address P = Nil;
        
        // Tentukan posisi elemen yang akan dihapus
        if (foundDelete == L.first) {
            // Hapus elemen pertama
            deleteFirst(L, P);
        } else if (foundDelete == L.last) {
            // Hapus elemen terakhir
            deleteLast(L, P);
        } else {
            // Hapus elemen di tengah (setelah predecessor)
            address Prec = foundDelete->prev;
            deleteAfter(Prec, P);
        }
        
        if (P != Nil) {
            cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus." << endl;
            dealokasi(P);
        }
        
        cout << "\n=== DATA LIST SETELAH PENGHAPUSAN ===" << endl;
        printInfo(L);
    } else {
        cout << "\nData dengan nomor polisi " << hapusNopol << " tidak ditemukan." << endl;
    }
    
    return 0;
}
```

### Output Unguided 3 :

![Screenshot Output Unguided 3_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week7_modul6/output-unguided3-modul6.png)

Program meminta pengguna untuk memasukkan nomor polisi kendaraan yang akan dihapus, kemudian melakukan pencarian terlebih dahulu menggunakan fungsi findElm untuk menentukan apakah data tersebut ada dalam list. Jika data ditemukan, program mengidentifikasi posisi node dalam list apakah berada di posisi pertama, terakhir, atau di tengah, kemudian memanggil prosedur delete yang sesuai. Untuk elemen pertama digunakan prosedur deleteFirst yang mengupdate pointer first list, untuk elemen terakhir digunakan prosedur deleteLast yang mengupdate pointer last list, sedangkan untuk elemen di tengah digunakan prosedur deleteAfter yang menghubungkan node sebelum dan sesudah node yang dihapus. Setelah proses penghapusan berhasil, program menampilkan pesan konfirmasi bahwa data dengan nomor polisi tertentu telah berhasil dihapus, kemudian membebaskan memori node yang dihapus menggunakan prosedur dealokasi, dan terakhir menampilkan isi list setelah penghapusan untuk memverifikasi bahwa data telah benar-benar terhapus dari list. 

## Kesimpulan
Doubly Linked List merupakan struktur data linear yang memiliki keunggulan dalam fleksibilitas manipulasi data melalui kemampuan traversal dua arah, yang membedakannya dari Single Linked List yang hanya dapat ditelusuri satu arah. Struktur ini terdiri dari node-node yang memiliki tiga komponen utama yaitu data, pointer next, dan pointer prev, yang membentuk rantai berantai ganda dengan head di awal dan tail di akhir linked list. Implementasi dalam bahasa C++ dilakukan dengan mendefinisikan class atau struct untuk merepresentasikan node, serta memanfaatkan alokasi memori dinamis menggunakan operator new yang memungkinkan ukuran linked list berubah-ubah sesuai kebutuhan. Operasi-operasi dasar seperti insertion, deletion, searching, dan traversal dapat dilakukan dengan kompleksitas waktu yang bervariasi, di mana operasi pada posisi awal atau akhir memiliki kompleksitas O(1) sedangkan operasi pada posisi tengah dan searching memiliki kompleksitas O(n). Meskipun Doubly Linked List memerlukan memori lebih besar dan memiliki kompleksitas implementasi yang lebih tinggi dibandingkan Single Linked List, struktur data ini tetap menjadi pilihan yang efisien untuk aplikasi yang membutuhkan traversal dua arah dan operasi penghapusan yang cepat, seperti browser history, undo-redo functionality, dan music playlist.

## Referensi 
[1] Karumanchi, N. (2016). Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles (5th ed.). CareerMonk Publications. 
<br> 
[2] Drozdek, A. (2012). Data Structures and Algorithms in C++ (4th ed.). Cengage Learning. 
<br> 
[3] Sedgewick, R., & Wayne, K. (2011). Algorithms (4th ed.). Addison-Wesley Professional. 
<br> 
[4] Malik, D. S. (2010). Data Structures Using C++ (2nd ed.). Course Technology. 
<br> 
[5] Horowitz, E., Sahni, S., & Mehta, D. (2007). Fundamentals of Data Structures in C++ (2nd ed.). Silicon Press. 
