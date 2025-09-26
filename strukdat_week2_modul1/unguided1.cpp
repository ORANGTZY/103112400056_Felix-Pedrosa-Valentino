#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "\nHasil Penjumlahan: " << a + b << endl;
    cout << "Hasil Pengurangan: " << a - b << endl;
    cout << "Hasil Perkalian  : " << a * b << endl;

    if (b != 0) {
        cout << "Hasil Pembagian : " << a / b << endl;
    } else {
        cout << "Pembagian tidak dapat dilakukan (pembagi nol)." << endl;
    }

    return 0;
}
