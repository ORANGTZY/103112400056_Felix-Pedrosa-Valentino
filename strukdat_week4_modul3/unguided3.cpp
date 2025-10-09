#include <iostream>
using namespace std;

// Fungsi untuk menampilkan isi array 2D integer
void tampilkanArray(int arr[][3], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Fungsi untuk menukarkan isi dari 2 array 2D pada posisi tertentu (i, j)
void tukarArray(int arr1[][3], int arr2[][3], int i, int j) {
    int temp = arr1[i][j];
    arr1[i][j] = arr2[i][j];
    arr2[i][j] = temp;
}

// Fungsi untuk menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer
void tukarPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // 2 buah array 2D integer berukuran 3x3
    int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr2[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};

    // 2 buah pointer integer
    int x = 100;
    int y = 200;
    int *p1 = &x;
    int *p2 = &y;

    // Demonstrasi tampilkan array
    cout << "Isi Array 1 sebelum tukar:" << endl;
    tampilkanArray(arr1, 3, 3);
    cout << "Isi Array 2 sebelum tukar:" << endl;
    tampilkanArray(arr2, 3, 3);

    // Tukar elemen pada posisi (1,1) antara arr1 dan arr2
    int posI = 1, posJ = 1;
    tukarArray(arr1, arr2, posI, posJ);

    cout << "Isi Array 1 setelah tukar posisi (" << posI << "," << posJ << "):" << endl;
    tampilkanArray(arr1, 3, 3);
    cout << "Isi Array 2 setelah tukar posisi (" << posI << "," << posJ << "):" << endl;
    tampilkanArray(arr2, 3, 3);

    // Demonstrasi pointer
    cout << "Nilai sebelum tukar pointer: *p1 = " << *p1 << ", *p2 = " << *p2 << endl;
    tukarPointer(p1, p2);
    cout << "Nilai setelah tukar pointer: *p1 = " << *p1 << ", *p2 = " << *p2 << endl;

    return 0;
}