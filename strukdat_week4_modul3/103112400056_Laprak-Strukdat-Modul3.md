# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Felix Pedrosa Valentino - 103112400056</p>

## Dasar Teori
Abstract Data Type (ADT) atau Tipe Data Abstrak merupakan salah satu konsep dasar dalam ilmu komputer yang berfungsi untuk mendefinisikan suatu tipe data berdasarkan perilaku dan operasinya tanpa memerhatikan bagaimana data tersebut diimplementasikan [1]. Dalam konteks pemrograman, ADT berperan penting untuk memisahkan antara apa yang dilakukan oleh suatu struktur data dan bagaimana cara melakukannya. Hal ini memungkinkan programmer untuk fokus pada logika penggunaan data tanpa perlu memikirkan detail teknis penyimpanannya [2].

Dalam bahasa C++, konsep ADT sering diimplementasikan menggunakan class atau struct, yang berfungsi sebagai wadah untuk mengenkapsulasi data (atribut) dan operasi (fungsi) dalam satu kesatuan [3]. Dengan menggunakan prinsip encapsulation dan abstraction, programmer dapat melindungi data dari akses langsung dan hanya mengizinkan interaksi melalui metode tertentu. Contohnya, struktur data seperti Stack, Queue, dan List merupakan bentuk implementasi nyata dari ADT. Operasi dasar seperti push(), pop(), enqueue(), atau dequeue() didefinisikan dalam antarmuka ADT, sedangkan detail penyimpanan data (misalnya menggunakan array atau linked list) disembunyikan dari pengguna [4].

Penerapan ADT dalam C++ juga erat kaitannya dengan prinsip Object-Oriented Programming (OOP), terutama dalam hal modularitas dan reusability kode. Dengan mendefinisikan ADT, suatu program dapat dibuat lebih terstruktur, mudah dikembangkan, serta efisien dalam penggunaan kembali kode di proyek lain [5]. Selain itu, penggunaan ADT membantu mengurangi tingkat kompleksitas program besar dengan cara membaginya menjadi beberapa bagian kecil yang saling berinteraksi melalui antarmuka yang jelas dan terstandarisasi.

## Guided 

### 1. Guided 1 (mahasiswa)

mahasiswa.h
```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

// Definisi Tipe (Struct)
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

// Deklarasi Primitif (Fungsi)
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```

mahasiswa.cpp
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

// Realisasi dari Fungsi inputMhs 
void inputMhs(mahasiswa &m) {
    cout << "Input NIM: ";
    cin >> m.nim;
    cout << "Input Nilai 1: ";
    cin >> m.nilai1;
    cout << "Input Nilai 2: ";
    cin >> m.nilai2;
}

// Realisasi dari Fungsi rata2
float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
```

main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata-rata nilai adalah: " << rata2(mhs) << endl;
    system("pause");
    
    return 0;
}
```

Program ini berfungsi untuk mengelola data mahasiswa menggunakan struktur terpisah dalam file header dan implementasi. File mahasiswa.h mendefinisikan struct mahasiswa yang berisi NIM (array karakter) serta dua nilai ujian (integer), beserta deklarasi fungsi inputMhs untuk menerima input data dan rata2 untuk menghitung rata-rata nilai. File mahasiswa.cpp merealisasikan fungsi-fungsi tersebut, di mana inputMhs membaca NIM dan kedua nilai melalui konsol, sementara rata2 mengembalikan hasil rata-rata sebagai float. Pada file main.cpp, program mendeklarasikan variabel mahasiswa, memanggil prosedur input, menampilkan rata-rata nilai ke layar, dan menjeda eksekusi menggunakan system("pause") sebelum keluar, sehingga memungkinkan pengguna melihat hasil secara interaktif.

### 2. Guided 2 (Struct)

```C++
// guided 2 

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m) {
    cout << "Masukkan nama mahasiswa : ";
    cin >> m.nama;
    cout << "Masukkan nilai 1 : ";
    cin >> m.nilai1;
    cout << "Masukkan nilai 2 : ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return float (m.nilai1 + m.nilai2) / 2;
}

int main() {
    mahasiswa mhs;   // pemanggilan struct (ADT)
    inputMhs(mhs);   // pemanggilan prosedur 
    cout << "Rata-rata : " << rata2(mhs) << endl;  // pemanggilan function 
    return 0;
}
```
Program ini berfungsi untuk mengelola data mahasiswa secara terstruktur menggunakan Abstract Data Type (ADT). Program mendefinisikan struktur mahasiswa yang mencakup atribut nama (string) serta dua nilai ujian (float). Fungsi inputMhs bertugas menerima input dari pengguna untuk mengisi data mahasiswa melalui konsol, sementara fungsi rata2 menghitung dan mengembalikan nilai rata-rata dari kedua nilai tersebut. Di fungsi utama main, program mendeklarasikan variabel mahasiswa, memanggil prosedur input, kemudian menampilkan hasil rata-rata secara langsung ke layar, sehingga menghasilkan output ringkas berupa rata-rata nilai mahasiswa yang dimasukkan.

## Unguided 

### 1. Soal Unguided 1
Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
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
```
### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week4_modul3/output-unguided1-modul3.png)

Program ini berfungsi untuk mengelola data mahasiswa menggunakan array struct dengan kapasitas maksimal 10 entri, di mana struct Mahasiswa menyimpan nama dan NIM sebagai string, serta nilai UTS, UAS, tugas, dan nilai akhir sebagai float. Fungsi hitungNilaiAkhir menghitung nilai akhir berdasarkan rumus 0.3UTS + 0.4UAS + 0.3*tugas. Di fungsi main, program meminta input jumlah mahasiswa dan memvalidasinya agar berada antara 1 hingga 10; selanjutnya, melalui loop for, mengumpulkan data setiap mahasiswa dengan getline untuk nama (mendukung spasi) dan cin untuk field lain, membersihkan buffer input menggunakan cin.ignore() untuk menghindari masalah, serta menghitung nilai akhir secara otomatis. Output ditampilkan dalam bentuk tabel rapi menggunakan iomanip untuk alignment kiri, lebar kolom tetap, presisi desimal dua tempat pada nilai float, dan garis pemisah, sehingga memudahkan pembacaan daftar data mahasiswa secara terstruktur.

### 2. Soal Unguided 2
Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":
Type pelajaran <
    namamapel: string
    kodeMapel: string
>
function create_pelajaran ( namapel: string,
    kodepel: string) → pelajaran
procedure tampil_pelajaran (input pel: pelajaran )

Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp"
Cobalah hasil implementasi ADT pada file "main.cpp"

pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

// Definisi tipe data pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// Fungsi dan prosedur
pelajaran create_pelajaran(string namaPel, string kodePel);
void tampil_pelajaran(pelajaran pel);

#endif
```

pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

// Implementasi fungsi untuk membuat data pelajaran
pelajaran create_pelajaran(string namaPel, string kodePel) {
    pelajaran p;
    p.namaMapel = namaPel;
    p.kodeMapel = kodePel;
    return p;
}

// Implementasi prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

mainpelajaran.cpp
```C++
#include <iostream>
#include <string>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaPel = "Struktur Data";
    string kodePel = "STD";

    pelajaran pel = create_pelajaran(namaPel, kodePel);
    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week4_modul3/output-unguided2-modul3.png)

Program ini berfungsi untuk mengelola data pelajaran secara terstruktur menggunakan file header dan implementasi terpisah. File pelajaran.h mendefinisikan struct pelajaran yang berisi nama mata pelajaran dan kode mata pelajaran (keduanya string), beserta deklarasi fungsi create_pelajaran untuk membuat objek pelajaran dan prosedur tampil_pelajaran untuk menampilkan data. File pelajaran.cpp merealisasikan fungsi create_pelajaran yang menginisialisasi struct dengan parameter nama dan kode yang diberikan, serta prosedur tampil_pelajaran yang mencetak nama pelajaran dan kode (disebut sebagai "nilai") ke konsol. Pada file mainpelajaran.cpp, program mendeklarasikan variabel string untuk nama ("Struktur Data") dan kode ("STD"), membuat objek pelajaran melalui pemanggilan create_pelajaran, kemudian menampilkan data tersebut menggunakan tampil_pelajaran, sehingga menghasilkan output sederhana berupa informasi pelajaran yang telah dibuat.

### 3. Soal Unguided 3
Buatlah program dengan ketentuan : 
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
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
```
### Output Unguided 3 :

![Screenshot Output Unguided 3_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week4_modul3/output-unguided3-modul3.png)

Program ini mmendemonstrasikan manipulasi array dua dimensi dan pointer integer. Program ini membuat dua array 2D dengan ukuran 3x3 (arr1 dan arr2) yang diisi dengan nilai awal, serta dua pointer (p1 dan p2) yang mengarah ke variabel integer x dan y. Fungsi tampilkanArray digunakan untuk menampilkan isi array 2D dengan rapi menggunakan loop bersarang. Fungsi tukarArray berfungsi untuk menukar elemen pada posisi tertentu (i, j) antara dua array dengan menggunakan variabel sementara. Sementara itu, fungsi tukarPointer melakukan pertukaran nilai yang ditunjuk oleh dua pointer dengan cara dereferensi. Di dalam fungsi main, program menunjukkan isi kedua array sebelum dan setelah menukar elemen di posisi (1,1), lalu mendemonstrasikan pertukaran nilai pointer sebelum dan setelah pemanggilan fungsi, sehingga menjelaskan konsep passing by reference dan manipulasi data yang efisien.

## Kesimpulan
Secara keseluruhan, Abstract Data Type (ADT) merupakan fondasi esensial dalam pemrograman struktur data yang memungkinkan abstraksi perilaku data melalui operasi standar tanpa mengungkap detail implementasi, sehingga memisahkan logika fungsional dari aspek teknis penyimpanan. Di bahasa C++, ADT diwujudkan secara optimal melalui class dan struct yang mendukung enkapsulasi, memungkinkan pengelolaan data seperti Stack, Queue, dan List dengan operasi dasar seperti push(), pop(), enqueue(), serta dequeue() yang disembunyikan dari pengguna eksternal. Integrasi ADT dengan prinsip Object-Oriented Programming (OOP) tidak hanya meningkatkan modularitas dan reusability kode, tetapi juga mengurangi kompleksitas program besar dengan membagi sistem menjadi komponen terstruktur yang berinteraksi melalui antarmuka jelas, sehingga memfasilitasi pengembangan perangkat lunak yang lebih efisien, mudah dipelihara, dan scalable.

## Referensi
[1] Dale, N., & McMillan, C. (2017). Data Structures: A Pseudocode Approach with C++. Jones & Bartlett Learning.
<br>
[2] Malik, D. S. (2018). Data Structures Using C++. Cengage Learning.
<br>
[3] Budd, T. A. (2012). An Introduction to Object-Oriented Programming. Addison-Wesley.
<br>
[4] Makalah Abstrak Data Type. (n.d.). Retrieved from https://id.scribd.com/document/683914578/Makalah-Abstrak-Data-Type
<br>
[5] Lafore, R. (2002). Object-Oriented Programming in C++ (4th Edition). Sams Publishing.