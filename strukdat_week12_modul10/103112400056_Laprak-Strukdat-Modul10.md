# <h1 align="center">Laporan Praktikum Modul 10 - Tree (Bagian Pertama)</h1>
<p align="center">Felix Pedrosa Valentino - 103112400056</p>

## Dasar Teori
Tree (pohon) merupakan salah satu bentuk struktur data non-linier yang menggambarkan hubungan yang bersifat hierarkis (hubungan one-to-many) antara elemen-elemennya. Berbeda dengan struktur data linier seperti array atau linked list di mana data disusun secara berurutan, Tree mengorganisir data dalam bentuk simpul (node) yang saling terhubung menyerupai struktur pohon terbalik dengan akar (root) berada di bagian paling atas [1]. Struktur ini sangat efisien untuk operasi pencarian dan pengurutan data dalam skala besar karena mengurangi kompleksitas waktu dibandingkan struktur linier. Dalam ilmu komputer, Tree sering digunakan untuk merepresentasikan struktur direktori file, struktur HTML dalam pemrograman web, hingga algoritma routing jaringan [2].

Sebuah Tree terdiri dari elemen dasar yang disebut node (simpul) dan edge (garis penghubung). Node paling atas yang tidak memiliki induk disebut sebagai Root, sedangkan node yang tidak memiliki anak (child) disebut sebagai Leaf atau daun. Setiap node dapat memiliki node lain sebagai anak, dan node yang memiliki induk yang sama disebut sebagai Sibling. Selain itu, terdapat istilah Subtree, yang merupakan bagian dari Tree yang terdiri dari sebuah node beserta seluruh keturunannya [3]. Konsep kedalaman (depth) dan ketinggian (height) juga penting dalam analisis Tree; kedalaman adalah jarak node dari root, sedangkan ketinggian adalah jarak terpanjang dari node tersebut ke leaf terjauh.

Dalam implementasi praktikum ini, jenis Tree yang menjadi fokus utama adalah Binary Tree (Pohon Biner). Binary Tree adalah sebuah Tree di mana setiap node maksimal hanya memiliki dua orang anak, yang secara spesifik disebut sebagai Left Child (Anak Kiri) dan Right Child (Anak Kanan). Struktur ini memungkinkan definisi rekursif di mana setiap anak dari sebuah node juga merupakan akar dari sebuah binary subtree [4]. Terdapat beberapa variasi khusus dari Binary Tree, seperti Full Binary Tree (setiap node memiliki 0 atau 2 anak) dan Complete Binary Tree (semua level terisi penuh kecuali mungkin level terakhir yang terisi dari kiri).

Implementasi Binary Tree dalam bahasa pemrograman C++ umumnya dilakukan menggunakan struct atau class yang memanfaatkan konsep pointer dan memori dinamis. Sebuah node dalam C++ biasanya direpresentasikan sebagai sebuah struct yang memiliki tiga komponen utama: satu variabel untuk menyimpan data (misalnya bertipe integer atau char), pointer left yang menunjuk ke node anak kiri, dan pointer right yang menunjuk ke node anak kanan [5]. Jika sebuah child tidak ada, maka pointer tersebut akan diisi dengan nilai NULL atau nullptr. Penggunaan pointer ini memungkinkan struktur Tree untuk tumbuh secara dinamis sesuai dengan jumlah data yang dimasukkan selama program berjalan.

## Guided 

### 1. Guided 1

```C++
#include<iostream>

using namespace std;

int pangkat_2(int x){
    if(x == 0){ // basis
        return 1;
    } else if (x > 0){ // rekurens
        return 2 * pangkat_2(x - 1);
    }
}

int main(){
    cout << "=== REKURSIF PANGKAT 2 ===" << endl;
    
    int x;
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << endl;
    cout << "2 pangkat " << x << " adalah : " << pangkat_2(x);

    return 0;
}
```

Berikut adalah deskripsi program tersebut dalam format paragraf:Program ini merupakan implementasi sederhana dalam bahasa C++ untuk menghitung hasil perpangkatan bilangan 2 dengan menggunakan metode rekursif. Program mendefinisikan sebuah fungsi bernama pangkat_2 yang menerima parameter bilangan bulat $x$, di mana fungsi ini bekerja berdasarkan dua kondisi logika: base case (basis) yang mengembalikan nilai 1 jika $x$ bernilai 0, dan recursive step (langkah rekursif) yang mengembalikan hasil perkalian 2 dengan pemanggilan kembali fungsi tersebut untuk nilai $x-1$ jika input lebih besar dari 0. Pada fungsi utama (main), program meminta pengguna memasukkan nilai eksponen $x$, kemudian memanggil fungsi rekursif tersebut untuk melakukan perhitungan dan menampilkan hasil akhirnya ke layar konsol.

### 2. Guided 2

BST1.h
```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>

using namespace std;

typedef int infotype; // alias infotype untuk data integer
typedef struct Node *address; // alias address sebagai pointer ke struct Node (Node*)

struct Node {
    infotype info; // info data yang disimpan (integer) 
    address left; // pointer left 
    address right; // pointer right
}; 

// isEmpty & createTree
bool isEmpty(address root); // function untuk mengecek apakah BST kosong atau tidak
void createTree(address &root); // function untuk membuat BST nya (root di-set sebagai NULL)

// alokasi & insert
address newNode(infotype x); // function untuk memasukkan data (infotype) ke dalam node
address insertNode(address root, infotype x); // function untuk memasukkan node ke dalam BST

// Traversal
void preOrder(address root); // function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
void inOrder(address root); // function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
void postOrder(address root); // function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)

// Utilities
int countNodes(address root); // function untuk menghitung size atau ukuran atau jumlah node yang ada di dalam tree
int treeDepth(address root); // function untuk menghitung height atau kedalaman atau level tree

#endif
``` 

BST1.cpp
```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```

main.cpp
```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```

Program ini merupakan implementasi modular struktur data Binary Search Tree (BST) dalam bahasa C++ yang memisahkan deklarasi, logika fungsi, dan eksekusi utama ke dalam file BST1.h, BST1.cpp, dan main.cpp. Program mendefinisikan tipe data abstrak berupa struct Node yang memanfaatkan pointer dan alokasi memori dinamis untuk menyimpan data integer serta menghubungkannya dengan child kiri dan kanan. Fungsionalitas utama mencakup operasi insertNode yang menyusun data secara otomatis berdasarkan aturan BST (nilai lebih kecil dari root ditempatkan di kiri, dan yang lebih besar di kanan), serta tiga metode traversal rekursif (PreOrder, InOrder, PostOrder) untuk menelusuri dan menampilkan isi pohon. Selain itu, program dilengkapi dengan utilitas countNodes untuk menghitung total simpul dan treeDepth untuk mengukur kedalaman pohon. Pada fungsi main, program mendemonstrasikan pembentukan pohon dengan menyisipkan serangkaian angka (dimulai dari 20 sebagai root), kemudian menampilkan hasil penelusuran urutan data serta statistik jumlah node dan kedalaman pohon tersebut ke layar. 

### 3. Guided 3

BST2.h
```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>

using namespace std;

typedef int infotype; // alias infotype untuk data integer
typedef struct Node *address; // alias address sebagai pointer ke struct Node (Node*)

struct Node {
    infotype info; // info data yang disimpan (integer) 
    address left; // pointer left 
    address right; // pointer right
}; 

// isEmpty & createTree
bool isEmpty(address root); // function untuk mengecek apakah BST kosong atau tidak
void createTree(address &root); // function untuk membuat BST nya (root di-set sebagai NULL)

// alokasi & insert
address newNode(infotype x); // function untuk memasukkan data (infotype) ke dalam node
address insertNode(address root, infotype x); // function untuk memasukkan node ke dalam BST

// Traversal
void preOrder(address root); // function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
void inOrder(address root); // function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
void postOrder(address root); // function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)

// Utilities
int countNodes(address root); // function untuk menghitung size atau ukuran atau jumlah node yang ada di dalam tree
int treeDepth(address root); // function untuk menghitung height atau kedalaman atau level tree

//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x); //function untuk melakukan searching data tertentu

//mostleft & mostright
address mostLeft(address root); // function untuk menampilkan mostleft atau node paling kiri
address mostRight(address root); // function untuk menampilkan mostleft atau node paling kanan

//delete
bool deleteNode(address &root, infotype x); 
void deleteTree(address &root); //prosedur untuk menghapus BST (menghapus seluruh node BST)

#endif
``` 

BST2.cpp
```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```

main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```

Program ini merupakan pengembangan lanjutan dari implementasi Binary Search Tree (BST) guided sebelumnya yang disusun secara modular dalam file BST2.h, BST2.cpp, dan main.cpp. Fokus utama pengembangan pada program ini adalah penambahan fitur manipulasi data yang lebih kompleks, meliputi fungsi pencarian (searchByData) yang tidak hanya melacak keberadaan nilai tetapi juga menampilkan informasi relasional node (seperti parent, sibling, dan child), serta fungsi mostLeft dan mostRight untuk mengidentifikasi nilai minimum dan maksimum dalam pohon. Selain itu, program ini mengimplementasikan logika penghapusan data (deleteNode) yang menangani tiga skenario kritis: penghapusan leaf node, node dengan satu anak, dan node dengan dua anak yang diselesaikan menggunakan teknik penggantian nilai dengan successor (nilai terkecil di subtree kanan). Pada eksekusi utama, program mendemonstrasikan siklus lengkap penggunaan BST, mulai dari penyisipan data, validasi pencarian, operasi penghapusan node dinamis berdasarkan input pengguna, hingga prosedur deleteTree yang membersihkan seluruh struktur pohon dari memori secara rekursif.

## Unguided 

### 1. Soal Unguided 1 
![Screenshot Soal Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week12_modul10/SoalUnguided1-Modul10.png)

bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#define Nil NULL

using namespace std;

// Definisi tipe data
typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

// Prototype Fungsi & Prosedur Dasar
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

#endif
```

bstree.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else if (root->info == x) {
        return root;
    } else {
        if (x < root->info) {
            return findNode(x, root->left);
        } else {
            return findNode(x, root->right);
        }
    }
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}
```

main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); // Angka 6 duplikat akan diabaikan oleh logika insert standar
    insertNode(root, 7);

    printInorder(root);
    cout << endl;
    
    return 0;
}
```

### Output Unguided 1 :

![Screenshot Output Unguided 3_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week12_modul10/output-unguided1-modul10.png)

Program ini merupakan implementasi modular struktur data Binary Search Tree (BST) dalam bahasa C++ yang memisahkan definisi ADT, logika implementasi, dan eksekusi utama ke dalam file bstree.h, bstree.cpp, dan main.cpp. Program mendefinisikan struktur Node yang memanfaatkan pointer dan alokasi memori dinamis untuk menyimpan data integer. Fungsionalitas utamanya mencakup fungsi alokasi untuk pembentukan node baru, fungsi findNode untuk pencarian, serta prosedur insertNode yang menyisipkan data secara rekursif sesuai aturan BST (nilai lebih kecil di kiri, lebih besar di kanan) sekaligus mengabaikan input duplikat. Untuk visualisasi, program menggunakan prosedur printInorder yang menelusuri pohon dari kiri ke kanan (terurut secara menaik/ascending) dan mencetak setiap elemen dengan pemisah tanda strip (" - "). Pada fungsi main, program mendemonstrasikan penyisipan serangkaian angka dan menampilkan hasil pengurutannya ke layar. 

### 2. Soal Unguided 2 
![Screenshot Soal Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week12_modul10/SoalUnguided2-Modul10.png)

bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#define Nil NULL

using namespace std;

// Definisi tipe data
typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

// Prototype Fungsi & Prosedur Dasar
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

// Fungsi Statistik
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
// Menggunakan parameter 'start' sesuai request soal gambar, default biasanya 0
int hitungKedalaman(address root, int start); 

#endif
```

bstree.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else if (root->info == x) {
        return root;
    } else {
        if (x < root->info) {
            return findNode(x, root->left);
        } else {
            return findNode(x, root->right);
        }
    }
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
}

int hitungTotalInfo(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
    }
}

// Implementasi rekursif untuk kedalaman (max depth)
int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start; // Mengembalikan level terakhir yang dicapai
    } else {
        int leftDepth = hitungKedalaman(root->left, start + 1);
        int rightDepth = hitungKedalaman(root->right, start + 1);
        
        if (leftDepth > rightDepth) return leftDepth;
        else return rightDepth;
    }
}
```

main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    address root = Nil;

    // Insert data
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    printInorder(root);
    cout << "\n";

    // Pemanggilan fungsi statistik
    cout << "kedalaman   : " << hitungKedalaman(root, 0) << endl; 
    cout << "jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "total       : " << hitungTotalInfo(root) << endl;

    return 0;
}
```

### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week12_modul10/output-unguided2-modul10.png)

Program ini merupakan implementasi modular struktur data Binary Search Tree (BST) lanjutan dari dari unguided sebelumnya dalam bahasa C++ yang memisahkan deklarasi ADT, logika fungsi, dan eksekusi utama ke dalam file bstree.h, bstree.cpp, dan main.cpp. Program mendefinisikan struct Node berbasis pointer untuk membentuk struktur pohon dinamis, di mana data disisipkan melalui prosedur insertNode yang secara otomatis menempatkan nilai sesuai aturan BST (lebih kecil di kiri, lebih besar di kanan) dan mengabaikan input duplikat. Selain fitur penelusuran data (traversal) menggunakan metode InOrder yang dimodifikasi dengan pemisah tanda strip (" - "), program ini diperkaya dengan fungsi statistik rekursif untuk menghitung jumlah simpul (hitungJumlahNode), menjumlahkan seluruh nilai data (hitungTotalInfo), serta mengukur kedalaman maksimum pohon (hitungKedalaman). Pada fungsi main, serangkaian data integer diinputkan untuk membentuk pohon, yang kemudian diikuti oleh tampilan hasil pengurutan data serta laporan statistik terkait properti pohon tersebut ke layar. 

### 3. Soal Unguided 3 
![Screenshot Soal Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week12_modul10/SoalUnguided3-Modul10.png)

bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#define Nil NULL

using namespace std;

// Definisi tipe data
typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

// Prototype Fungsi & Prosedur Dasar
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

// Fungsi Statistik
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
// Menggunakan parameter 'start' sesuai request soal gambar, default biasanya 0
int hitungKedalaman(address root, int start); 

void printPreorder(address root);
void printPostorder(address root);

#endif
```

bstree.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else if (root->info == x) {
        return root;
    } else {
        if (x < root->info) {
            return findNode(x, root->left);
        } else {
            return findNode(x, root->right);
        }
    }
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
}

int hitungTotalInfo(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
    }
}

// Implementasi rekursif untuk kedalaman (max depth)
int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start; // Mengembalikan level terakhir yang dicapai
    } else {
        int leftDepth = hitungKedalaman(root->left, start + 1);
        int rightDepth = hitungKedalaman(root->right, start + 1);
        
        if (leftDepth > rightDepth) return leftDepth;
        else return rightDepth;
    }
}

void printPreorder(address root) {
    if (root != Nil) {
        cout << root->info << " ";      // Cetak Akar
        printPreorder(root->left);      // Kunjungi Kiri
        printPreorder(root->right);     // Kunjungi Kanan
    }
}

void printPostorder(address root) {
    if (root != Nil) {
        printPostorder(root->left);     // Kunjungi Kiri
        printPostorder(root->right);    // Kunjungi Kanan
        cout << root->info << " ";      // Cetak Akar
    }
}
```

main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    address root = Nil;

    // Insert data
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 3);

    cout << "PreOrder    : ";
    printPreorder(root);
    cout << endl;

    cout << "PostOrder   : ";
    printPostorder(root);
    cout << endl;

    return 0;
}
```

### Output Unguided 3 :

![Screenshot Output Unguided 3_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week12_modul10/output-unguided3-modul10.png)

Program ini merupakan implementasi modular struktur data Binary Search Tree (BST) dalam bahasa C++ yang membagi kode menjadi deklarasi ADT (bstree.h), implementasi logika (bstree.cpp), dan eksekusi utama (main.cpp). Program mendefinisikan struct Node yang memanfaatkan alokasi memori dinamis dan pointer untuk membentuk hierarki data, serta menyediakan fungsi lengkap untuk manipulasi pohon, termasuk penyisipan data (insertNode), pencarian, perhitungan statistik (jumlah node, total nilai, dan kedalaman), serta tiga jenis penelusuran (traversal). Pada eksekusi utamanya, program secara spesifik membangun pohon dengan menyisipkan serangkaian bilangan bulat (dimulai dari 6 sebagai root, diikuti 4, 7, 2, 5, 1, dan 3) dan menampilkan hasil penelusuran struktur pohon tersebut menggunakan metode PreOrder (cetak akar di awal) dan PostOrder (cetak akar di akhir) ke layar.

## Kesimpulan
Tree merupakan struktur data non-linier yang vital dalam ilmu komputer karena kemampuannya merepresentasikan data secara hierarkis dan efisien untuk operasi pencarian maupun pengurutan dibandingkan struktur linier. Struktur ini terbangun dari elemen-elemen dasar seperti root, node, dan leaf yang memiliki properti kedalaman serta ketinggian tertentu. Fokus utama pada Binary Tree (Pohon Biner) menekankan pada aturan bahwa setiap node maksimal hanya memiliki dua anak, yang memungkinkan penerapan logika rekursif serta variasi struktur seperti Full dan Complete Binary Tree.

## Referensi
[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
<br>
[2] Malik, D. S. (2010). Data Structures Using C++ (2nd ed.). Cengage Learning.
<br>
[3] Lipschutz, S. (2014). Schaum's Outline of Data Structures with C (1st ed.). McGraw-Hill Education.
<br>
[4] Weiss, M. A. (2014). Data Structures and Algorithm Analysis in C++ (4th ed.). Pearson.
<br>
[5] GeeksforGeeks. (2024). Binary Tree Data Structure. 