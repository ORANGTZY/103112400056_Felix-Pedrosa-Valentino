#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <iostream>
#include <string>

using namespace std;

const int MAX = 5;

// Struct Paket
struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang; // dalam kg
    string Tujuan;
};

// Struct QueueEkspedisi (Array Implementation)
struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};

// Prototipe Fungsi & Prosedur
bool isEmpty(QueueEkspedisi &Q);
bool isFull(QueueEkspedisi &Q);
void createQueue(QueueEkspedisi &Q);

// Enqueue dengan input manual
void enQueue(QueueEkspedisi &Q);

// Overload Enqueue untuk input otomatis
void enQueue(QueueEkspedisi &Q, Paket pBaru);

void deQueue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi &Q);

// Bagian B: Hitung Total Biaya
long TotalBiayaPengiriman(QueueEkspedisi &Q);

#endif