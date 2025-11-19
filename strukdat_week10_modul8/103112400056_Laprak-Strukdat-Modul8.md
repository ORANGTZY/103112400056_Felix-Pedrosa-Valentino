# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Felix Pedrosa Valentino - 103112400056</p>

## Dasar Teori
Queue (antrean) merupakan salah satu bentuk struktur data linier yang fundamental dalam ilmu komputer. Prinsip kerja utama dari queue adalah FIFO (First In, First Out) [1]. Prinsip ini menetapkan bahwa elemen yang pertama kali dimasukkan ke dalam antrean (input) akan menjadi elemen yang pertama kali dikeluarkan (output) [2]. Konsep ini analog dengan antrean di kehidupan nyata, seperti antrean pembelian tiket, di mana individu yang datang pertama akan dilayani terlebih dahulu [3]. Dalam implementasinya, queue memerlukan dua penanda (pointer) utama: Head (atau Front) yang menunjuk ke elemen terdepan (elemen yang siap dihapus), dan Tail (atau Rear) yang menunjuk ke elemen terakhir (posisi di mana elemen baru akan ditambahkan) [4].

Operasi dasar yang umum dilakukan pada queue meliputi dua proses utama. Pertama adalah enQueue, yaitu operasi untuk menambahkan elemen baru ke bagian akhir antrean (Tail). Saat elemen baru ditambahkan, pointer Tail akan diperbarui untuk menunjuk ke elemen baru tersebut [1]. Operasi kedua adalah deQueue, yaitu operasi untuk menghapus atau mengeluarkan elemen dari bagian depan antrean (Head). Ketika operasi deQueue dilakukan, pointer Head akan berpindah menunjuk ke elemen berikutnya dalam antrean [3]. Selain itu, terdapat operasi pendukung seperti isEmpty() untuk memverifikasi apakah antrean sedang kosong (Head menunjuk ke Nil/NULL) dan isFull() untuk mengecek kapasitas, meskipun isFull() lebih sering digunakan pada implementasi berbasis array [2].

Dalam bahasa C++, queue dapat diimplementasikan menggunakan dua pendekatan utama: array (statis) atau linked list (dinamis) [5]. Implementasi menggunakan linked list (senarai berantai) menawarkan fleksibilitas yang lebih besar karena alokasi memori bersifat dinamis, sehingga ukuran antrean dapat bertambah atau berkurang sesuai kebutuhan selama program berjalan. Dalam pendekatan ini, setiap elemen (disebut node) dalam linked list akan berisi data dan sebuah pointer (next) yang menunjuk ke node di belakangnya. Struktur queue itu sendiri cukup menyimpan dua pointer utama, yaitu head dan tail. Penggunaan pointer head dan tail ini memungkinkan operasi enQueue (menambah di akhir) dan deQueue (menghapus di awal) dapat dieksekusi dengan sangat efisien dalam waktu konstan atau O(1) [4].

## Guided 

### 1. Guided 1

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif
```

queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```

main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;
    
    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah deQueue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);
    
    return 0;
}
```

Program ini merupakan implementasi struktur data antrian (queue) menggunakan linked list dalam bahasa pemrograman C++. Pada file header queue.h, didefinisikan struktur node yang menyimpan data integer (dataAngka) dan pointer ke node berikutnya (next), serta struktur queue dengan pointer head dan tail untuk menunjukkan awal dan akhir antrian. File queue.cpp berisi implementasi berbagai fungsi operasi queue, seperti isEmpty untuk memeriksa apakah queue kosong, createQueue untuk inisialisasi queue, alokasi untuk membuat node baru, dealokasi untuk menghapus node, enQueue untuk menambahkan elemen di akhir queue, deQueue untuk menghapus elemen dari depan queue, updateQueue untuk mengubah data pada posisi tertentu, viewQueue untuk menampilkan isi queue, dan searchData untuk mencari data dalam queue. Di file main.cpp, program utama mendemonstrasikan penggunaan queue dengan membuat queue kosong, mengalokasikan lima node dengan nilai 1 hingga 5, menambahkannya ke queue menggunakan enQueue, menampilkan isi queue, menghapus dua elemen menggunakan deQueue, mengupdate data pada posisi tertentu, menampilkan queue setelah update, serta mencari data tertentu dalam queue.

### 2. Guided 2

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_h

#define MAX_QUEUE 5

struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);

bool isEmpty(Queue Q);

bool isFull(Queue Q);

void enqueue(Queue &Q, int x);

int dequeue(Queue &Q);

void printInfo(Queue Q);
#endif
```

queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```

main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

// Fungsi utama program
int main() {
    Queue Q;

    createQueue(Q);
    printInfo(Q);
    
    cout << "\n Enqueue 3 Elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    
    cout << "\n Dequeue 1 Elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);
    
    cout << "\n Enqueue 1 Elemen" << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\n Dequeue 2 Elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```

Program ini merupakan implementasi struktur data antrian (queue) menggunakan array circular dalam bahasa pemrograman C++, dengan kapasitas maksimal 5 elemen. Pada file header queue.h, didefinisikan struktur Queue yang terdiri dari array info untuk menyimpan data integer, serta variabel head, tail, dan count untuk mengelola posisi awal, akhir, dan jumlah elemen. File queue.cpp berisi implementasi fungsi-fungsi operasi queue, seperti createQueue untuk inisialisasi queue kosong, isEmpty dan isFull untuk memeriksa kondisi queue, enqueue untuk menambahkan elemen di akhir queue dengan penanganan circular, dequeue untuk menghapus dan mengembalikan elemen dari awal queue, serta printInfo untuk menampilkan isi queue secara berurutan. Di file main.cpp, program utama mendemonstrasikan penggunaan queue dengan membuat queue kosong, menambahkan tiga elemen (5, 2, 7) menggunakan enqueue, menampilkan isi queue, menghapus satu elemen menggunakan dequeue, menambahkan satu elemen lagi (4), lalu menghapus dua elemen, dengan output yang menunjukkan perubahan isi queue.

## Unguided 

### 1. Soal Unguided 1 
![Screenshot Soal Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week10_modul8/SoalUnguided1-Modul8.png)

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        x = Q.info[Q.head];
        
        // Jika hanya ada 1 elemen
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            // Geser semua elemen ke kiri
            for (int i = Q.head; i < Q.tail; i++) {
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail--;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << " " << Q.head << " - " << Q.tail << "   | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i];
            if (i < Q.tail) {
                cout << " ";
            }
        }
    }
    cout << endl;
}
```

main.cpp
```C++
#include "queue.h"

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);
    cout << "----------------------" << endl;
    cout << " H - T   | Queue Info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
```

### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week10_modul8/output-unguided1-modul8.png)

Program ini merupakan implementasi dari struktur data antrian (queue) menggunakan array statis dalam bahasa C++. Antrian didefinisikan melalui struct Queue yang terdiri dari array info berukuran 5 untuk menyimpan elemen bertipe int, serta indeks head dan tail untuk menandai posisi awal dan akhir antrian. Fungsi createQueue menginisialisasi antrian kosong dengan head dan tail bernilai -1. Fungsi isEmptyQueue memeriksa apakah antrian kosong, sedangkan isFullQueue memeriksa apakah antrian penuh (tail mencapai indeks 4). Operasi enqueue menambahkan elemen ke akhir antrian jika belum penuh, dan dequeue menghapus elemen dari awal antrian dengan menggeser elemen-elemen ke kiri jika diperlukan, mengembalikan nilai elemen yang dihapus atau -1 jika kosong. Fungsi printInfo menampilkan status head, tail, dan isi antrian. Program utama dalam main.cpp mendemonstrasikan penggunaan antrian dengan serangkaian operasi enqueue dan dequeue, serta mencetak status antrian setelah setiap operasi untuk menunjukkan perilaku FIFO (First In, First Out).

### 2. Soal Unguided 2 
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
queue Alternatif 2 (head bergerak, tail bergerak).

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        x = Q.info[Q.head];
        
        // Jika hanya ada 1 elemen
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            // Head bergerak ke kanan (Alternatif 2)
            Q.head++;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << " " << Q.head << " - " << Q.tail << "   | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i];
            if (i < Q.tail) {
                cout << " ";
            }
        }
    }
    cout << endl;
}
```

main.cpp
```C++
#include "queue.h"

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);
    cout << "----------------------" << endl;
    cout << " H - T   | Queue Info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
```

### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week10_modul8/output-unguided2-modul8.png)

Program ini merupakan implementasi dari struktur data antrian (queue) menggunakan array statis dalam bahasa C++. Antrian didefinisikan melalui struct Queue yang terdiri dari array info berukuran 5 untuk menyimpan elemen bertipe int, serta indeks head dan tail untuk menandai posisi awal dan akhir antrian. Fungsi createQueue menginisialisasi antrian kosong dengan head dan tail bernilai -1. Fungsi isEmptyQueue memeriksa apakah antrian kosong, sedangkan isFullQueue memeriksa apakah antrian penuh (tail mencapai indeks 4). Operasi enqueue menambahkan elemen ke akhir antrian jika belum penuh, dan dequeue menghapus elemen dari awal antrian dengan menambah indeks head jika antrian tidak kosong, mengembalikan nilai elemen yang dihapus atau -1 jika kosong. Fungsi printInfo menampilkan status head, tail, dan isi antrian. Program utama dalam main.cpp mendemonstrasikan penggunaan antrian dengan serangkaian operasi enqueue dan dequeue, serta mencetak status antrian setelah setiap operasi untuk menunjukkan perilaku FIFO (First In, First Out).

### 3. Soal Unguided 3 
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
queue Alternatif 3 (head dan tail berputar).

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == Q.tail);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % 5 == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        Q.info[Q.tail] = x;
        Q.tail = (Q.tail + 1) % 5;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        x = Q.info[Q.head];
        Q.head = (Q.head + 1) % 5;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << " " << Q.head << " - " << Q.tail << "   | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;
        while (i != Q.tail) {
            cout << Q.info[i];
            i = (i + 1) % 5;
            if (i != Q.tail) {
                cout << " ";
            }
        }
    }
    cout << endl;
}
```

main.cpp
```C++
#include "queue.h"

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);
    cout << "----------------------" << endl;
    cout << " H - T   | Queue Info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
```

### Output Unguided 3 :

![Screenshot Output Unguided 3_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week10_modul8/output-unguided3-modul8.png)

Program ini merupakan implementasi struktur data antrian melingkar (circular queue) menggunakan array statis berukuran 5 dalam bahasa C++. Antrian didefinisikan melalui struct Queue yang terdiri dari array info untuk menyimpan elemen bertipe int, serta indeks head dan tail yang menggunakan operasi modulo 5 untuk menangani sifat melingkar. Fungsi createQueue menginisialisasi antrian kosong dengan head dan tail bernilai 0. Fungsi isEmptyQueue memeriksa apakah antrian kosong (head sama dengan tail), sedangkan isFullQueue memeriksa apakah antrian penuh ((tail + 1) % 5 sama dengan head). Operasi enqueue menambahkan elemen ke posisi tail dan menggeser tail secara melingkar jika belum penuh, dan dequeue menghapus elemen dari head dengan menggeser head secara melingkar jika tidak kosong, mengembalikan nilai elemen atau -1 jika kosong. Fungsi printInfo menampilkan status head, tail, dan isi antrian menggunakan loop melingkar. Program utama dalam main.cpp mendemonstrasikan penggunaan antrian dengan serangkaian operasi enqueue dan dequeue, serta mencetak status antrian setelah setiap operasi untuk menunjukkan perilaku FIFO (First In, First Out) dengan efisiensi ruang yang lebih baik melalui pendekatan melingkar.

## Kesimpulan
Queue adalah struktur data linier fundamental yang beroperasi berdasarkan prinsip FIFO (First In, First Out), di mana elemen pertama yang ditambahkan juga merupakan elemen pertama yang akan dihapus. Fungsionalitas inti ini dicapai melalui dua operasi utama: enQueue (menambah elemen ke Tail atau bagian akhir) dan deQueue (menghapus elemen dari Head atau bagian depan), yang dikelola menggunakan dua pointer penanda tersebut. Dalam implementasinya di C++, penggunaan linked list (senarai berantai) menawarkan keunggulan signifikan dibandingkan array statis, terutama karena alokasi memorinya yang dinamis. Dengan memanfaatkan pointer head dan tail secara efektif, implementasi linked list memungkinkan operasi enQueue dan deQueue dieksekusi secara sangat efisien dengan kompleksitas waktu konstan (O(1)).

## Referensi
[1] Malik, D. S. (2018). Data Structures Using C++ (Third Edition). Boston, MA: Cengage Learning.
<br>
[2] Lafore, R. (2002). Data Structures & Algorithms in C++. Indianapolis, IN: Sams Publishing.
<br>
[3] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (Third Edition). Cambridge, MA: MIT Press.
<br>
[4] Sedgewick, R., & Wayne, K. (2011). Algorithms (Fourth Edition). Upper Saddle River, NJ: Addison-Wesley Professional.
<br>
[5] Sukrisno. (2017). Algoritma dan Struktur Data Menggunakan C++. Yogyakarta: Penerbit Andi.