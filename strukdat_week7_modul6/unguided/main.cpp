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