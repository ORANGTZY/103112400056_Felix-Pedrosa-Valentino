#include <iostream>
using namespace std;

const char* satuan[] = {"", "satu", "dua", "tiga", "empat", "lima",
                        "enam", "tujuh", "delapan", "sembilan"};

const char* belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas",
                         "empat belas", "lima belas", "enam belas",
                         "tujuh belas", "delapan belas", "sembilan belas"};

const char* puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh",
                         "lima puluh", "enam puluh", "tujuh puluh",
                         "delapan puluh", "sembilan puluh"};

void angkaKeTulisan(int n) {
    if (n == 0) {
        cout << "nol";
    } else if (n == 100) {
        cout << "seratus";
    } else if (n < 10) {
        cout << satuan[n];
    } else if (n < 20) {
        cout << belasan[n - 10];
    } else {
        int p = n / 10;
        int s = n % 10;
        cout << puluhan[p];
        if (s != 0) {
            cout << " " << satuan[s];
        }
    }
}

int main() {
    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar jangkauan!" << endl;
    } else {
        cout << angka << " : ";
        angkaKeTulisan(angka);
        cout << endl;
    }

    return 0;
}
