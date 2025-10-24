# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Felix Pedrosa Valentino - 103112400056</p>

## Dasar Teori
Struktur data adalah metode terorganisir untuk menyimpan dan mengatur data dalam komputer sehingga dapat diakses dan dimodifikasi secara efisien [1]. Salah satu struktur data fundamental yang bersifat linear dan dinamis adalah Linked List (Senarai Berantai). Berbeda dengan Array yang memiliki ukuran statis dan alokasi memori berdekatan, linked list menggunakan pointer untuk menghubungkan elemen-elemennya, yang disebut node. Setiap node dialokasikan secara dinamis di memori dan tidak harus berada di lokasi yang berurutan [2]. Singly Linked List (SLL) adalah bentuk linked list di mana setiap node hanya memiliki satu pointer (biasanya disebut next), yang menunjuk ke node berikutnya dalam urutan. Node terakhir dalam SLL akan memiliki pointer next yang menunjuk ke NULL, menandakan akhir dari senarai [3].

Implementasi SLL dalam bahasa C++ umumnya menggunakan struct atau class untuk merepresentasikan sebuah node. Struktur node ini minimal terdiri dari dua bagian: sebuah variabel untuk menyimpan data (misalnya, int data) dan sebuah pointer yang menunjuk ke tipe node itu sendiri (misalnya, Node* next). Seluruh struktur SLL dikelola oleh satu pointer utama yang disebut head, yang menyimpan alamat dari node pertama. Jika head bernilai NULL (atau nullptr dalam C++ modern), ini menandakan bahwa list tersebut dalam keadaan kosong [4]. Alokasi memori dinamis untuk node baru dilakukan menggunakan operator new, dan pelepasan memori dilakukan menggunakan operator delete [2].

Singly Linked List (Bagian Kedua) sering kali berfokus pada operasi manipulasi dan utilitas yang lebih kompleks, terutama operasi pencarian (searching) [1, 3]. Operasi ini sangat penting untuk mengelola siklus hidup data di dalam list. Operasi pencarian (searching) pada SLL dilakukan secara sekuensial (linear). Proses dimulai dari head. Sebuah pointer temporer digunakan untuk melintasi (traverse) list, berpindah dari satu node ke node berikutnya melalui pointer next. Pada setiap node, data node tersebut dibandingkan dengan data yang dicari. Jika data ditemukan, proses berhenti (dan biasanya mengembalikan pointer ke node tersebut atau status true). Jika pointer temporer mencapai NULL (akhir list) sebelum data ditemukan, berarti data tersebut tidak ada dalam list [3].

## Guided 

### 1. Guided 1 

listBuah.h 
```C++
// Header guard digunakan untuk mencegah file header yang sama

#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias dataBuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

// semua function & prosedur yang akan dipakai
// Materi modul 4 
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
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

// materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

#endif
``` 

listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

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

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
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
    if (Prev != Nil) {
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
        cout << "Node pertama berhasil terhapus!" << endl;
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
        cout << "Node terakhir berhasil terhapus!" << endl;
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
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
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
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
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
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

main.cpp  
```C++
#include "listBuah.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    //  A - C - D - B - E 

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

Program ini mengimplementasikan struktur data linked list untuk mengelola data buah, yang terdiri dari nama, jumlah, dan harga, menggunakan bahasa C++ dengan pemisahan file header (listBuah.h), implementasi (listBuah.cpp), dan main (main.cpp). Struktur buah menyimpan data buah, node sebagai elemen linked list dengan pointer next, dan linkedlist sebagai wadah dengan pointer first. Operasi dasar meliputi pembuatan list kosong, alokasi dan dealokasi node, serta insert (first, after, last), delete (first, last, after), print list, hitung jumlah node, dan penghapusan seluruh list. Tambahan fitur update untuk mengubah data node pertama, terakhir, atau setelah node tertentu. Di fungsi main, program membuat linked list kosong, mengalokasikan lima node buah (Jeruk, Apel, Pir, Semangka, Durian), menyisipkannya secara bertahap sehingga urutan menjadi Jeruk-Pir-Semangka-Apel-Durian, mencetak isi list dan jumlah node, lalu melakukan update pada node pertama, terakhir, dan setelah Semangka, sebelum mencetak hasil akhir. 

### 2. Guided 2 (linear) 

```C++
#include<iostream>
using namespace std;

//Definisi node
struct Node { //memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk pencarian linear
Node* linearSearch(Node* head, int key) {
    Node* current = head; //mulai dari node pertama
    while (current != nullptr) { //traverse sampai akhir list
        if (current->data == key) return current; // jika data ketemu
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //tidak ditemukan
}

//prosedur untuk menambahkan node
void append(Node*& head, int value){ // parameter head adalah referensi ke pointer head  // value adalah data yang mau dimasukkin
    Node* newNode = new Node{value, nullptr}; // membuat pointer baru 
    if(!head)head = newNode; //jika head null, head diisi node baru 
    else{
        Node* temp = head; //mulai dari head
        while(temp->next)temp = temp->next; //pindah ke node berikutnya sampai ketemu node terakhir
        temp->next = newNode; //node terakhir dihubungkan ke node baru
    }
}

int main() {
    Node* head = nullptr; //inisialisasi head list masih kosong 
    append(head, 10); append(head, 20); append(head, 30); // menambah node 

    Node* result = linearSearch(head, 20); // result ini pointer untuk mencari node dengan data 20 
    cout << (result ? "Found" : "Not Found") << endl; // condition ? value_if_true : value_if_false

    return 0;
}
```

Program ini mengimplementasikan struktur data linked list untuk penyimpanan data linier dengan kemampuan pencarian linear. Struktur Node terdiri dari data integer dan pointer ke node berikutnya. Fungsi append digunakan untuk menambahkan node baru ke akhir linked list dengan cara menyusuri dari head hingga node terakhir dan menghubungkannya. Fungsi linearSearch melakukan pencarian nilai kunci secara berurutan mulai dari node pertama hingga akhir linked list, mengembalikan pointer ke node jika ditemukan atau nullptr jika tidak. Di fungsi main, linked list diinisialisasi kosong, kemudian ditambahkan node dengan nilai 10, 20, dan 30, lalu dilakukan pencarian nilai 20 menggunakan linear search, dengan hasil pencarian dicetak sebagai "Found" atau "Not Found". 

### 3. Guided 3 (binary) 

```C++
#include<iostream>
using namespace std;

//Definisi node
struct Node { //memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//prosedur untuk menambahkan node
void append(Node*& head, int value){ // Node* ini pointer (kembalian) 
    Node* newNode = new Node{value, nullptr}; // membuat pointer baru 
    if(!head)head = newNode; //jika head null, head diisi node baru 
    else{
        Node* temp = head; //mulai dari head
        while(temp->next)temp = temp->next; //pindah ke node berikutnya sampai ketemu node terakhir
        temp->next = newNode; //node terakhir dihubungkan ke node baru
    }
}

Node* binarySearch(Node* head, int key) {  // Node* ini pointer (kembalian)  // head ini pointer ke node pertama  // key ini data yang dicari
    int size = 0; // var size diisi 0
    for (Node* current = head; current; current = current->next) size++; // current adalah pointer yangg digunakan untuk menyusuri linked list
    Node *start = head; // start adalah pointer yang menunjuk ke node pertama
    Node *end = nullptr; 
    while (size > 0) { // selama masih ada elemen > 0
        int mid =  size / 2; // bagi size jadi 2
        Node* midNode = start;
        for (int i = 0; i < mid; i++) midNode = midNode->next; // pindah ke node tengah
        if (midNode->data == key) return midNode; // Jika ditemukan data yang cocok, kembalikan ke node
        if (midNode->data < key) {  // Jika data midNode lebih kecil dari key, kita cari di bagian kanan
            start = midNode->next; // Mulai pencarian dari node setelah midNode
        } else { //jika data midNode lebih besar dari key, kita cari di bagian kiri
            end = midNode; // batasi pencarian ke bagian kiri 
        }
        size -= mid;  //kita mengurangi size dengan mid
    }
    return nullptr; // Jika key tidak ditemukan
}

int main() {
    Node* head = nullptr; //inisialisasi linked list kosong 
    append(head, 10); append(head, 20); append(head, 30); append(head, 40); append(head, 50); // menambah node 

    // mencari data 40 menggunakan binary search 
    Node* result = binarySearch(head, 40); 
    cout << (result ? "Found" : "Not Found") << endl; // menampilkan hasil pencarian

    return 0;
}
```

Program ini mengimplementasikan penggunaan struktur data linked list untuk penyimpanan data linier dengan kemampuan pencarian biner. Struktur Node terdiri dari data integer dan pointer ke node berikutnya. Fungsi append digunakan untuk menambahkan node baru ke akhir linked list dengan cara menyusuri dari head hingga node terakhir dan menghubungkannya. Fungsi binarySearch melakukan pencarian nilai kunci dalam linked list yang diasumsikan terurut, dengan menghitung ukuran list terlebih dahulu, lalu membagi rentang pencarian secara iteratif hingga menemukan nilai yang cocok atau menyimpulkan tidak ditemukan. Di fungsi main, linked list diinisialisasi kosong, kemudian ditambahkan node dengan nilai 10, 20, 30, 40, dan 50, lalu dilakukan pencarian nilai 40 menggunakan binary search, dengan hasil pencarian dicetak sebagai "Found" atau "Not Found". 

## Unguided 

### 1. Soal Unguided 1 
Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan binary search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir

Petunjuk Tugas 1:
- Gunakan struktur Node dengan data integer dan pointer next
- Implementasikan fungsi append() untuk menambah node
- Implementasikan fungsi binarySearch() yang mengembalikan pointer ke node yang ditemukan
- Data dalam linked list harus terurut (ascending) untuk binary search bekerja dengan benar
- Tampilkan langkah-langkah pencarian dan posisi tengah setiap iterasi
- Program utama harus membuat linked list dengan minimal 5 elemen dan melakukan pencarian

```C++
#include <iostream>
#include <iomanip>
using namespace std;

// Definisi node
struct Node {
    int data;       // Data integer
    Node* next;     // Pointer ke node berikutnya
};

// Prosedur untuk menambahkan node di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};  // Membuat node baru
    
    if (!head) {
        // Jika linked list kosong, node baru menjadi head
        head = newNode;
    } else {
        // Traverse ke node terakhir
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        // Hubungkan node terakhir dengan node baru
        temp->next = newNode;
    }
}

// Prosedur untuk menampilkan visualisasi linked list
void visualizeList(Node* head) {
    cout << "Linked List yang dibuat: ";
    Node* current = head;
    
    while (current) {
        cout << current->data;
        if (current->next) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

// Fungsi Binary Search pada Linked List dengan visualisasi detail
Node* binarySearch(Node* head, int key) {
    // Menghitung jumlah elemen dalam linked list
    int size = 0;
    for (Node* current = head; current; current = current->next) {
        size++;
    }
    
    // Jika linked list kosong
    if (size == 0) {
        cout << "Linked list kosong!" << endl;
        return nullptr;
    }
    
    cout << "\nProses Pencarian:" << endl;
    
    // Variabel untuk menyimpan range pencarian
    int left = 0;           // Indeks kiri
    int right = size - 1;   // Indeks kanan
    int iterasi = 1;        // Counter iterasi
    
    // Binary Search Algorithm
    while (left <= right) {
        // Hitung indeks tengah
        int mid = left + (right - left) / 2;
        
        // Traverse ke node di posisi mid
        Node* midNode = head;
        for (int i = 0; i < mid; i++) {
            midNode = midNode->next;
        }
        
        // Tampilkan detail iterasi
        cout << "Iterasi " << iterasi << ": Mid = " << mid 
             << " (indeks tengah)";
        
        // Cek apakah data ditemukan
        if (midNode->data == key) {
            cout << " - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key 
                 << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << midNode << endl;
            cout << "Data node: " << midNode->data << endl;
            
            // Tampilkan node berikutnya
            if (midNode->next != nullptr) {
                cout << "Node berikutnya: " << midNode->next->data << endl;
            } else {
                cout << "Node berikutnya: NULL (ini adalah node terakhir)" << endl;
            }
            
            return midNode;
        }
        // Jika key lebih kecil dari midNode, cari di bagian kiri
        else if (key < midNode->data) {
            cout << " -> Cari di bagian kiri" << endl;
            right = mid - 1;
        }
        // Jika key lebih besar dari midNode, cari di bagian kanan
        else {
            cout << " -> Cari di bagian kanan" << endl;
            left = mid + 1;
        }
        
        iterasi++;
    }
    
    // Data tidak ditemukan
    cout << "Tidak ada elemen tersisa" << endl;
    cout << "\nHasil: Nilai " << key 
         << " TIDAK DITEMUKAN dalam linked list!" << endl;
    
    return nullptr;
}

// Fungsi untuk membersihkan memori linked list
void deleteList(Node*& head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;  // Inisialisasi linked list kosong
    
    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    
    // Membuat linked list dengan minimal 5 elemen (terurut ascending)
    // Data harus terurut untuk binary search bekerja dengan benar
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    
    // Visualisasi linked list
    visualizeList(head);
    
    // TEST CASE 1: Mencari nilai yang ada (40)
    cout << "Mencari nilai: 40" << endl;
    Node* result1 = binarySearch(head, 40);
    
    cout << "\n" << string(60, '=') << endl;
    
    // TEST CASE 2: Mencari nilai yang tidak ada (25)
    cout << "\nMencari nilai: 25" << endl;
    Node* result2 = binarySearch(head, 25);
    
    // Membersihkan memori
    deleteList(head);
    
    return 0;
}
```
### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week6_modul5/output-unguided1_tugas1-modul5.png)

Program ini merupakan penerapan binary search pada linked list di bahasa C++, yang mendemonstrasikan proses pencarian nilai dalam struktur data linked list secara efisien dengan asumsi data terurut secara ascending, disertai visualisasi detail langkah-langkah pencarian. Kode dimulai dengan definisi struct Node yang terdiri dari data integer dan pointer ke node berikutnya, diikuti oleh prosedur append untuk menambahkan node baru di akhir linked list. Fungsi visualizeList digunakan untuk menampilkan representasi visual linked list dalam format "data -> data -> ... -> NULL". Fungsi utama binarySearch menghitung ukuran linked list terlebih dahulu, lalu melakukan pencarian biner dengan menentukan indeks kiri dan kanan, menghitung indeks tengah, serta menelusuri ke node tersebut untuk membandingkan dengan nilai kunci, sambil menampilkan detail iterasi, arah pencarian (kiri atau kanan), dan hasil akhir termasuk alamat node serta node berikutnya jika ditemukan. Fungsi deleteList bertugas membersihkan memori dengan menghapus semua node. Dalam fungsi main, program membuat linked list terurut dengan enam elemen (10, 20, 30, 40, 50, 60), menampilkannya, lalu menjalankan dua test case: pencarian nilai yang ada (40) dan yang tidak ada (25), sebelum membersihkan memori. Output program menunjukkan proses iteratif binary search secara interaktif, menjadikannya alat pembelajaran untuk memahami algoritma binary search pada linked list meskipun kurang efisien dibandingkan array karena perlu traverse berulang.

### 2. Soal Unguided 2 
Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu. Program harus mampu: 
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan linear search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir

Petunjuk Tugas 2:
- Gunakan struktur Node dengan data integer dan pointer next
- Implementasikan fungsi append() untuk menambah node
- Implementasikan fungsi linearSearch () yang mengembalikan pointer ke node yang ditemukan
- Data dalam linked list tidak perlu terurut untuk linear search
- Tampilkan setiap langkah pencarian dan node yang sedang diperiksa
- Program utama harus membuat linked list dengan minimal 3 elemen dan melakukan pencarian 

```C++
#include <iostream>
#include <iomanip>
using namespace std;

// Definisi node
struct Node {
    int data;       // Data integer
    Node* next;     // Pointer ke node berikutnya
};

// Prosedur untuk menambahkan node di akhir linked list
void append(Node*& head, int value) {
    // Membuat node baru dengan data value dan next = nullptr
    Node* newNode = new Node{value, nullptr};
    
    if (!head) {
        // Jika linked list kosong, node baru menjadi head
        head = newNode;
    } else {
        // Traverse ke node terakhir
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        // Hubungkan node terakhir dengan node baru
        temp->next = newNode;
    }
}

// Prosedur untuk menampilkan visualisasi linked list
void visualizeList(Node* head) {
    cout << "Linked List yang dibuat: ";
    Node* current = head;
    
    while (current) {
        cout << current->data;
        if (current->next) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

// Fungsi Linear Search pada Linked List dengan visualisasi detail
Node* linearSearch(Node* head, int key) {
    // Jika linked list kosong
    if (head == nullptr) {
        cout << "Linked list kosong!" << endl;
        return nullptr;
    }
    
    cout << "\nProses Pencarian:" << endl;
    
    Node* current = head;   // Pointer untuk traverse linked list
    int nodeNumber = 1;     // Counter nomor node
    
    // Traverse linked list dari awal sampai akhir
    while (current != nullptr) {
        // Tampilkan node yang sedang diperiksa
        cout << "Memeriksa node " << nodeNumber << ": " 
             << current->data;
        
        // Cek apakah data pada node current sama dengan key
        if (current->data == key) {
            // Data ditemukan
            cout << " (SAMA) - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key 
                 << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << current << endl;
            cout << "Data node: " << current->data << endl;
            
            // Tampilkan node berikutnya jika ada
            if (current->next != nullptr) {
                cout << "Node berikutnya: " << current->next->data << endl;
            } else {
                cout << "Node berikutnya: NULL (ini adalah node terakhir)" << endl;
            }
            
            return current;
        } else {
            // Data tidak sama, lanjut ke node berikutnya
            cout << " (tidak sama)" << endl;
        }
        
        // Pindah ke node berikutnya
        current = current->next;
        nodeNumber++;
    }
    
    // Jika sampai di sini, berarti data tidak ditemukan
    cout << "Tidak ada node lagi yang tersisa" << endl;
    cout << "\nHasil: Nilai " << key 
         << " TIDAK DITEMUKAN dalam linked list!" << endl;
    
    return nullptr;
}

// Fungsi untuk membersihkan memori linked list
void deleteList(Node*& head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;  // Inisialisasi linked list kosong
    
    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;
    
    // Membuat linked list dengan minimal 3 elemen
    // Data tidak perlu terurut untuk linear search
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    
    // Visualisasi linked list
    visualizeList(head);
    
    // TEST CASE 1: Mencari nilai yang ada (30)
    cout << "Mencari nilai: 30" << endl;
    Node* result1 = linearSearch(head, 30);
    
    cout << "\n" << string(60, '=') << endl;
    
    // TEST CASE 2: Mencari nilai yang tidak ada (25)
    cout << "\nMencari nilai: 25" << endl;
    Node* result2 = linearSearch(head, 25);
    
    // Membersihkan memori
    deleteList(head);
    
    return 0;
}
```
### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week6_modul5/output-unguided2_tugas2-modul5.png)

Program ini merupakan penerapan linear search pada linked list menggunakan bahasa C++, dengan tujuan untuk menunjukkan langkah-langkah proses pencarian nilai dalam struktur data linked list secara rinci dengan visualisasi yang jelas. Kode diawali dengan definisi struct Node yang mencakup data integer dan pointer ke node berikutnya, dilanjutkan dengan prosedur append untuk menambahkan node baru di bagian akhir linked list. Fungsi visualizeList digunakan untuk menunjukkan representasi visual dari linked list dalam format "data -> data ->. . . -> NULL". Fungsi utama linearSearch melakukan pencarian secara linear dengan memeriksa setiap node dari head hingga akhir, menampilkan proses pemeriksaan node satu per satu, serta memberikan hasil apakah nilai berhasil ditemukan atau tidak, termasuk informasi seperti alamat node dan node selanjutnya. Fungsi deleteList berfungsi untuk membersihkan memori dengan menghapus semua node yang ada. Di dalam fungsi main, program membuat linked list dengan lima elemen (10, 20, 30, 40, 50), menampilkannya, kemudian menjalankan dua test case: pencarian untuk nilai yang ada (30) dan yang tidak ada (25), sebelum melakukan pembersihan memori. Output dari program menunjukkan langkah-langkah pencarian secara interaktif, menjadikannya alat pembelajaran untuk memahami algoritma linear search pada linked list.

## Kesimpulan
Singly Linked List (SLL) merupakan salah satu struktur data linear yang dinamis, yang fundamentalnya berbeda dari array karena sifat alokasi memorinya yang tidak berdekatan dan penggunaan pointer untuk menghubungkan elemen-elemennya, yang disebut node. Dalam implementasinya di C++, setiap node (biasanya berupa struct atau class) terdiri dari komponen data dan sebuah pointer next yang menunjuk ke node selanjutnya, di mana node terakhir menunjuk ke NULL sebagai penanda akhir list. Keseluruhan struktur ini dikelola oleh pointer head yang menunjuk node pertama, dan menggunakan operator new serta delete untuk manajemen memori dinamis. Fokus lanjutan pada SLL, seperti pada bagian kedua ini, menekankan pada operasi manipulasi data yang esensial, terutama operasi pencarian (searching). Proses pencarian pada SLL dilakukan secara sekuensial (linear), dimulai dari head dan melintasi (traverse) list node demi node dengan mengikuti pointer next hingga data yang dicari ditemukan atau akhir list (NULL) tercapai. 

## Referensi
[1] T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, Introduction to Algorithms, 3rd ed. Cambridge, MA: MIT Press, 2009. 
<br>
[2] D. S. Malik, Data Structures Using C++, 2nd ed. Boston, MA: Cengage Learning, 2010.
<br>
[3] R. Lafore, Data Structures & Algorithms in C++, 4th ed. Indianapolis, IN: Sams Publishing, 2002.
<br>
[4] M. A. Weiss, Data Structures and Algorithm Analysis in C++, 4th ed. Harlow, UK: Pearson, 2014. 