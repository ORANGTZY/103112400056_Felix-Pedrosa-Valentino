#include "QueuePengiriman.h"

// Helper untuk membuat struct Paket dengan cepat
Paket buatPaket(string resi, string nama, int berat, string tujuan) {
    Paket p;
    p.KodeResi = resi;
    p.NamaPengirim = nama;
    p.BeratBarang = berat;
    p.Tujuan = tujuan;
    return p;
}

int main() {
    QueueEkspedisi Q;
    int pilihan;
    
    // 1) Buat queue kosong
    createQueue(Q);

    // --- EKSEKUSI SKENARIO SOAL SECARA OTOMATIS ---
    cout << "--- INISIALISASI DATA SOAL (OTOMATIS) ---" << endl;
    
    // 3) Input data paket
    enQueue(Q, buatPaket("123456", "Hutao", 14, "Sumeru"));
    enQueue(Q, buatPaket("234567", "Ayaka", 10, "Fontaine"));
    enQueue(Q, buatPaket("345678", "Bennet", 7, "Natlan"));
    enQueue(Q, buatPaket("456789", "Furina", 16, "Liyue"));
    enQueue(Q, buatPaket("567890", "Nefer", 6, "Inazuma"));

    // 4) Tampilkan queue yang sudah diinput
    cout << "\n[Instruksi 4] Tampilan Awal:" << endl;
    viewQueue(Q);

    // 5) Lakukan deQueue sebanyak 1x
    cout << "\n[Instruksi 5] Melakukan Dequeue 1x..." << endl;
    deQueue(Q); // Hutao harusnya keluar

    // 6) Tampilkan queue setelah deQueue
    cout << "\n[Instruksi 6] Tampilan Setelah Dequeue:" << endl;
    viewQueue(Q);
    
    cout << "\n----------------------------------------" << endl;
    cout << "Masuk ke Menu Interaktif (Loop)" << endl;
    cout << "----------------------------------------" << endl;

    // 2) Menu Loop
    do {
        cout << "\n--- Komaniya Ekspress ---" << endl;
        cout << "1. Input Data Paket (Manual)" << endl;
        cout << "2. Hapus Data Paket (Dequeue)" << endl;
        cout << "3. Tampilkan queue paket" << endl;
        cout << "4. Hitung Total Biaya Pengiriman (Bagian B)" << endl;
        cout << "0. Exit" << endl;
        cout << "Pilihan anda : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                enQueue(Q);
                break;
            case 2:
                deQueue(Q);
                break;
            case 3:
                viewQueue(Q);
                break;
            case 4:
                cout << "Total Biaya Pengiriman: Rp " << TotalBiayaPengiriman(Q) << endl;
                break;
            case 0:
                cout << "Keluar program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}