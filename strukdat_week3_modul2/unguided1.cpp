#include <iostream>
using namespace std;

const int SIZE = 3;

// Prosedur untuk menampilkan matriks 3x3
void tampilMatriks(int matriks[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }
}

// Prosedur penjumlahan matriks
void jumlahMatriks(int A[SIZE][SIZE], int B[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Prosedur pengurangan matriks
void kurangMatriks(int A[SIZE][SIZE], int B[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Prosedur perkalian matriks
void kaliMatriks(int A[SIZE][SIZE], int B[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                hasil[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int matriksA[SIZE][SIZE] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };

    int matriksB[SIZE][SIZE] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };

    int hasil[SIZE][SIZE];
    int pilihan;

    do {
        cout << "\nMenu Program Matriks\n";
        cout << "1. Penjumlahan matriks\n";
        cout << "2. Pengurangan matriks\n";
        cout << "3. Perkalian matriks\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                jumlahMatriks(matriksA, matriksB, hasil);
                cout << "Hasil Penjumlahan Matriks A + B:\n";
                tampilMatriks(hasil);
                break;
            case 2:
                kurangMatriks(matriksA, matriksB, hasil);
                cout << "Hasil Pengurangan Matriks A - B:\n";
                tampilMatriks(hasil);
                break;
            case 3:
                kaliMatriks(matriksA, matriksB, hasil);
                cout << "Hasil Perkalian Matriks A x B:\n";
                tampilMatriks(hasil);
                break;
            case 4:
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 4);

    return 0;
}