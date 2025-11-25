#include "StackMahasiswa.h"

// Helper function untuk membuat data mahasiswa dengan cepat di main
Mahasiswa buatMhs(string nama, string nim, float t, float ut, float ua) {
    Mahasiswa m;
    m.Nama = nama; m.NIM = nim; m.NilaiTugas = t; m.NilaiUTS = ut; m.NilaiUAS = ua;
    return m;
}

int main() {
    StackMahasiswa stackMhs;

    // 1) Buat stack kosong
    createStack(stackMhs);

    // 2) Input data mahasiswa 
    Push(stackMhs, buatMhs("Venti", "11111", 75.7, 82.1, 65.5));
    Push(stackMhs, buatMhs("Xiao", "22222", 87.4, 88.9, 81.9));
    Push(stackMhs, buatMhs("Kazuha", "33333", 92.3, 88.8, 82.4));
    Push(stackMhs, buatMhs("Wanderer", "44444", 95.5, 85.5, 90.5));
    Push(stackMhs, buatMhs("Lynette", "55555", 77.7, 65.4, 79.9));
    Push(stackMhs, buatMhs("Chasca", "66666", 99.9, 93.6, 87.3));

    // 3) Tampilkan stack yang sudah diinput
    cout << "\n[Step 3] Stack Awal:" << endl;
    View(stackMhs);

    // 4) Lakukan pop sebanyak 1x
    cout << "\n[Step 4] Melakukan Pop..." << endl;
    Pop(stackMhs); // Chasca akan terhapus

    // 5) Tampilkan stack setelah pop
    cout << "\n[Step 5] Stack setelah Pop:" << endl;
    View(stackMhs);

    // 6) Lakukan update data pada posisi ke 3
    cout << "\n[Step 6] Silahkan masukkan data update untuk Posisi 3 (Heizou, 77777, 99.9, 88.8, 77.7):" << endl;
    // Panggil fungsi Update.
    // Posisi 3 (Index 2) saat ini adalah Kazuha.
    Update(stackMhs, 3); 

    // 7) Tampilkan stack setelah update
    cout << "\n[Step 7] Stack setelah Update:" << endl;
    View(stackMhs);

    // 8) Searching data NilaiAkhir range 85.5 - 95.5
    // Rumus: 20% Tugas + 40% UTS + 40% UAS
    cout << "\n[Step 8] Searching..." << endl;
    SearchNilaiAkhir(stackMhs, 85.5, 95.5);

    // Bagian B: Tampilkan Nilai Akhir Terbesar
    MaxNilaiAkhir(stackMhs);

    return 0;
}