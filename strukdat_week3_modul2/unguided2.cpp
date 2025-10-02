#include <iostream>
using namespace std;

int main() {
    // 1) Deklarasi variabel
    int panjang = 10;
    int lebar = 5;
    int luas = 0;
    int keliling = 0;

    // 2) Deklarasi pointer yang menunjuk ke panjang dan lebar
    int* ptrPanjang = &panjang;
    int* ptrLebar = &lebar;

    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang : " << panjang << endl;
    cout << "Lebar : " << lebar << endl << endl;

    // 3) Hitung luas dan keliling menggunakan pointer
    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang : " << luas << endl;
    cout << "Keliling Persegi Panjang : " << keliling << endl << endl;

    // 5) Ubah nilai panjang dan lebar melalui pointer
    *ptrPanjang = 12;
    *ptrLebar = 6;

    cout << "--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru : " << panjang << endl;
    cout << "Lebar Baru : " << lebar << endl;

    // Hitung ulang luas dan keliling dengan nilai baru
    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "Luas Baru : " << luas << endl;
    cout << "Keliling Baru : " << keliling << endl;

    return 0;
}