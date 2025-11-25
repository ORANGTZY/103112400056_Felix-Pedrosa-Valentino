#include "QueuePengiriman.h"

// Cek antrian kosong
bool isEmpty(QueueEkspedisi &Q) {
    return Q.Tail == -1;
}

// Cek antrian penuh
bool isFull(QueueEkspedisi &Q) {
    return Q.Tail == MAX - 1;
}

// Buat Queue Kosong
void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

// Prosedur Enqueue (Input Manual)
void enQueue(QueueEkspedisi &Q) {
    if (isFull(Q)) {
        cout << "Antrian Penuh! Tidak bisa menambah paket." << endl;
    } else {
        // Jika kosong, set Head ke 0
        if (isEmpty(Q)) {
            Q.Head = 0;
        }
        
        Q.Tail++; // Tail bergerak maju
        cout << "Masukkan Kode Resi: "; cin >> Q.dataPaket[Q.Tail].KodeResi;
        cout << "Nama Pengirim: "; cin >> Q.dataPaket[Q.Tail].NamaPengirim;
        cout << "Berat Barang (kg): "; cin >> Q.dataPaket[Q.Tail].BeratBarang;
        cout << "Tujuan: "; cin >> Q.dataPaket[Q.Tail].Tujuan;
        cout << "Paket berhasil masuk antrian." << endl;
    }
}

// Prosedur Enqueue (Input Otomatis untuk skenario Main)
void enQueue(QueueEkspedisi &Q, Paket pBaru) {
    if (isFull(Q)) {
        cout << "Antrian Penuh! Gagal input " << pBaru.NamaPengirim << endl;
    } else {
        if (isEmpty(Q)) {
            Q.Head = 0;
        }
        Q.Tail++;
        Q.dataPaket[Q.Tail] = pBaru;
        // cout << "Debug: Paket " << pBaru.NamaPengirim << " masuk." << endl;
    }
}

// Prosedur Dequeue (Head Diam - Shifting Element)
void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Antrian Kosong! Tidak ada yang bisa diambil." << endl;
    } else {
        cout << "Paket dengan resi " << Q.dataPaket[Q.Head].KodeResi 
             << " (" << Q.dataPaket[Q.Head].NamaPengirim << ") telah diproses/dihapus." << endl;

        // Geser semua elemen ke kiri (Shifting) agar Head tetap di index 0
        for (int i = 0; i < Q.Tail; i++) {
            Q.dataPaket[i] = Q.dataPaket[i + 1];
        }

        Q.Tail--; // Tail mundur

        // Jika setelah mundur Tail jadi -1, kembalikan Head ke -1 juga
        if (Q.Tail == -1) {
            Q.Head = -1;
        }
    }
}

// Prosedur View
void viewQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Antrian Kosong." << endl;
    } else {
        cout << "\n=== Daftar Antrian Paket Komaniya ===" << endl;
        for (int i = Q.Head; i <= Q.Tail; i++) {
            cout << i + 1 << ". Resi: " << Q.dataPaket[i].KodeResi 
                 << " | Pengirim: " << Q.dataPaket[i].NamaPengirim 
                 << " | Berat: " << Q.dataPaket[i].BeratBarang << "kg"
                 << " | Tujuan: " << Q.dataPaket[i].Tujuan << endl;
        }
        cout << "=====================================" << endl;
    }
}

// Bagian B: Fungsi Hitung Total Biaya
// Rumus: Berat * Rp 8250
long TotalBiayaPengiriman(QueueEkspedisi &Q) {
    long total = 0;
    if (!isEmpty(Q)) {
        for (int i = Q.Head; i <= Q.Tail; i++) {
            total += (Q.dataPaket[i].BeratBarang * 8250);
        }
    }
    return total;
}