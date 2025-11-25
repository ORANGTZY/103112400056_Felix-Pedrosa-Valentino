#include "StackMahasiswa.h"

// Cek apakah stack kosong
bool isEmpty(StackMahasiswa &S) {
    return S.Top == -1;
}

// Cek apakah stack penuh
bool isFull(StackMahasiswa &S) {
    return S.Top == MAX - 1;
}

// Membuat stack baru (inisialisasi Top)
void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

// Procedure Push (Input Manual via Terminal)
void Push(StackMahasiswa &S) {
    if (isFull(S)) {
        cout << "Stack Penuh! Tidak bisa push data." << endl;
    } else {
        S.Top++;
        cout << "Masukkan Nama: "; cin >> S.dataMahasiswa[S.Top].Nama;
        cout << "Masukkan NIM: "; cin >> S.dataMahasiswa[S.Top].NIM;
        cout << "Nilai Tugas: "; cin >> S.dataMahasiswa[S.Top].NilaiTugas;
        cout << "Nilai UTS: "; cin >> S.dataMahasiswa[S.Top].NilaiUTS;
        cout << "Nilai UAS: "; cin >> S.dataMahasiswa[S.Top].NilaiUAS;
        cout << "Data berhasil ditambahkan." << endl;
    }
}

// Procedure Push Overload (Untuk input dinamis/otomatis di Main)
void Push(StackMahasiswa &S, Mahasiswa mhsBaru) {
    if (isFull(S)) {
        cout << "Stack Penuh! Tidak bisa push " << mhsBaru.Nama << endl;
    } else {
        S.Top++;
        S.dataMahasiswa[S.Top] = mhsBaru;
        // cout << "Push: " << mhsBaru.Nama << " berhasil." << endl;
    }
}

// Procedure Pop (Menghapus elemen teratas)
void Pop(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong! Tidak bisa pop." << endl;
    } else {
        cout << "Pop data: " << S.dataMahasiswa[S.Top].Nama << " telah dihapus." << endl;
        S.Top--;
    }
}

// Procedure Update (Mengubah data pada posisi tertentu)
// Asumsi: input data update dilakukan di dalam fungsi (input manual)
void Update(StackMahasiswa &S, int posisi) {
    // Konversi posisi manusia (1,2,3) ke index array (0,1,2)
    int index = posisi - 1; 

    if (index > S.Top || index < 0) {
        cout << "Posisi tidak valid atau data tidak ada." << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << " (" << S.dataMahasiswa[index].Nama << "):" << endl;
    cout << "Nama Baru: "; cin >> S.dataMahasiswa[index].Nama;
    cout << "NIM Baru: "; cin >> S.dataMahasiswa[index].NIM;
    cout << "Nilai Tugas Baru: "; cin >> S.dataMahasiswa[index].NilaiTugas;
    cout << "Nilai UTS Baru: "; cin >> S.dataMahasiswa[index].NilaiUTS;
    cout << "Nilai UAS Baru: "; cin >> S.dataMahasiswa[index].NilaiUAS;
    cout << "Data berhasil diupdate." << endl;
}

// Procedure View (Menampilkan isi stack dari Atas ke Bawah)
void View(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong." << endl;
    } else {
        cout << "=== Isi Stack (Top to Bottom) ===" << endl;
        for (int i = S.Top; i >= 0; i--) {
            cout << "Posisi " << (i+1) << ". " << S.dataMahasiswa[i].Nama 
                 << " (" << S.dataMahasiswa[i].NIM << ")" << endl;
        }
        cout << "================================" << endl;
    }
}

// Fungsi Hitung Nilai Akhir (Helper)
float hitungNilaiAkhir(float tugas, float uts, float uas) {
    return (0.2 * tugas) + (0.4 * uts) + (0.4 * uas);
}

// Procedure SearchNilaiAkhir (Mencari berdasarkan range nilai akhir)
void SearchNilaiAkhir(StackMahasiswa &S, float min, float max) {
    cout << "\n=== Hasil Search Nilai Akhir (" << min << " - " << max << ") ===" << endl;
    bool found = false;
    for (int i = S.Top; i >= 0; i--) {
        float na = hitungNilaiAkhir(S.dataMahasiswa[i].NilaiTugas, 
                                    S.dataMahasiswa[i].NilaiUTS, 
                                    S.dataMahasiswa[i].NilaiUAS);
        
        if (na >= min && na <= max) {
            cout << "Ditemukan pada posisi ke-" << (i+1) << ": " 
                 << S.dataMahasiswa[i].Nama << " (NA: " << na << ")" << endl;
            found = true;
        }
    }
    if (!found) cout << "Tidak ada data dalam range tersebut." << endl;
}

// Bagian B: Procedure MaxNilaiAkhir
void MaxNilaiAkhir(StackMahasiswa &S) {
    if (isEmpty(S)) return;

    float maxVal = -1;
    int maxIdx = -1;

    for (int i = 0; i <= S.Top; i++) {
        float na = hitungNilaiAkhir(S.dataMahasiswa[i].NilaiTugas, 
                                    S.dataMahasiswa[i].NilaiUTS, 
                                    S.dataMahasiswa[i].NilaiUAS);
        if (na > maxVal) {
            maxVal = na;
            maxIdx = i;
        }
    }

    cout << "\n=== Mahasiswa Nilai Akhir Tertinggi ===" << endl;
    cout << "Nama: " << S.dataMahasiswa[maxIdx].Nama << endl;
    cout << "NIM: " << S.dataMahasiswa[maxIdx].NIM << endl;
    cout << "Nilai Akhir: " << maxVal << endl;
    cout << "Berada di posisi ke-" << (maxIdx + 1) << endl; 
}