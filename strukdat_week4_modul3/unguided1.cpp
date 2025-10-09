#include <iostream>
#include <string>
#include <iomanip>  // Untuk pengaturan output

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

// Fungsi untuk menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    const int MAX_MAHASISWA = 10;
    Mahasiswa mhs[MAX_MAHASISWA];
    int jumlahMhs;

    // Input jumlah mahasiswa
    cout << "Masukkan jumlah mahasiswa (maksimal 10): ";
    cin >> jumlahMhs;
    cin.ignore();  // Membersihkan buffer untuk input string berikutnya

    if (jumlahMhs > MAX_MAHASISWA || jumlahMhs < 1) {
        cout << "Jumlah mahasiswa tidak valid. Program dihentikan." << endl;
        return 1;
    }

    // Input data mahasiswa
    for (int i = 0; i < jumlahMhs; i++) {
        cout << "\n--- Data Mahasiswa ke-" << (i + 1) << " ---" << endl;
        cout << "Nama: ";
        getline(cin, mhs[i].nama);  // Menggunakan getline untuk nama lengkap
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cin.ignore();  // Membersihkan buffer
        cout << "Nilai UTS: ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS: ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;
        cin.ignore();  // Membersihkan buffer

        // Hitung nilai akhir menggunakan fungsi
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    // Output data mahasiswa yang disimpan
    cout << "\n--- Daftar Data Mahasiswa ---" << endl;
    cout << left << setw(20) << "Nama" << setw(15) << "NIM" 
         << setw(10) << "UTS" << setw(10) << "UAS" << setw(10) << "Tugas" 
         << setw(12) << "Nilai Akhir" << endl;
    cout << string(77, '-') << endl;

    for (int i = 0; i < jumlahMhs; i++) {
        cout << left << setw(20) << mhs[i].nama 
             << setw(15) << mhs[i].nim 
             << setw(10) << fixed << setprecision(2) << mhs[i].uts
             << setw(10) << fixed << setprecision(2) << mhs[i].uas
             << setw(10) << fixed << setprecision(2) << mhs[i].tugas
             << setw(12) << fixed << setprecision(2) << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}