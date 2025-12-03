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