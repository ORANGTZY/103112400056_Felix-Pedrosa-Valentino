# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Felix Pedrosa Valentino - 103112400056</p>

## Dasar Teori

### A. Array<br/>
Array merupakan suatu struktur yang terdiri dari beberapa elemen yang memiliki tipe data yang sama. Elemen-elemen dalam array tersusun secara sekuensial di dalam memori komputer. Semua elemen di dalam array memiliki tipe yang sama. Array sangat sesuai untuk mengorganisasi sekumpulan data yang homogen di mana ukuran atau jumlah maksimum elemennya sudah dipastikan dari awal. Homogen berarti setiap elemen dalam sebuah array tertentu harus memiliki tipe data yang identik [1].

#### 1. Array Satu Dimensi 
Array satu dimensi tidak lain adalah kumpulan elemen-elemen identik yang tersusun dalam satu baris, tetapi isi dari elemen tersebut boleh berbeda.  Dapat disebut juga dengan istilah vektor yang menggambarkan data dalam suatu urutan
Deklarasi : Type_Data Nama_Variabel [index] 
Misalnya : int A[5];
#### 2.  Array Dua Dimensi 
Array dua dimensi yang sering digambarkan sebagai sebuah matriks merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama. Pendeklarasian array dua dimensi hampir sama dengan pendeklarasian array satu dimensi, kecuali bahwa array dua dimensi terdapat dua jumlah elemen array yang terdapat di dalam kurung siku dan keduanya boleh tidak sama.
Deklarasi : Type_Data Nama_Variabel [Index1] [index2]; 
Misal : int A[3][2];
#### 3. Array Berdimensi Banyak
Sebenarnya array banyak dimensi ini tidak terlalu sering dipakai seperti halnya array satu dimensi, dua dimensi, dan tiga dimensi. Array banyak dimensi ini pada dasarnya sama dengan array sebelimnya kecuali pada jumlah dimensinya.
Deklarasi : Type_Data Nama_Variabel [index1] [ndex2] [index3] [ndex4].....;
Misal : int A [3][4][2][5];

### B. Pointer<br/>
Pointer adalah Setiap variabel yang didefinisikan dalam program memiliki lokasi penyimpanan di RAM. Lokasi ini dimanfaatkan oleh komputer untuk menyimpan serta mengambil informasi [2]. 

#### 1. Data dan Memori 
Semua informasi yang digunakan oleh perangkat lunak disimpan dalam memori (RAM) komputer. Memori ini dapat diibaratkan sebagai sebuah array satu dimensi yang sangat besar. Sama seperti array, setiap sel memori memiliki "indeks" atau "alamat" yang unik, yang berguna untuk identifikasi yang biasa kita sebut "address"

Ketika suatu program dijalankan, Sistem Operasi (OS) akan menyediakan ruang memori untuk setiap variabel, objek, atau array yang kita ciptakan. Lokasi di mana memori dialokasikan bisa sangat bervariasi tergantung pada proses yang berjalan di masing-masing OS.
#### 2. Pointer dan Alamat
Variabel pointer merupakan dasar tipe variabel yang berisi integer dalam format heksadesimal. Pointer digunakan untuk menyimpan alamat memori variabel lain sehingga pointer dapat mengakses nilai dari variabel yang alamatnya ditunjuk.
Cara pendeklarasian variabel pointer adalah sebagai berikut:
type *nama_variabel;
#### 3. Pointer dan Array
Ada keterhubungan yang kuat antara array dan pointer. Banyak operasi yang bisa dilakukan dengan array juga bisa dilakukan dengan pointer. 
#### 4. Pointer dan String
a. String
String merupakan bentuk data yang sering digunakan dalam bahasa pemrograman untuk mengolah data teks atau kalimat. Dalam bahasa C++ pada dasarnya string merupakan kumpulan dari karakter atau array dari karakter.
b. Pointer dan String
Pointer, yang berfungsi sebagai variabel yang menyimpan alamat memori, berperan penting dalam memanipulasi memori secara efisien. Di sisi lain, string adalah larik karakter yang diakhiri dengan karakter null (\0), yang digunakan secara luas untuk menangani teks.

### C. Fungsi<br/>
Fungsi merupakan blok dari kode yang dirancang untuk melaksanakan tugas khusus dengan tujuan:
1. Program menjadi terstruktur, sehingga mudah dipahami dan mudah dikembangkan. Program dibagi menjadi beberapa modul yang kecil.
2. Dapat mengurangi pengulangan kode (duplikasi kode) sehingga menghemat ukuran program.
Pada umumnya fungsi memerlukan masukan yang dinamakan sebagai parameter. Masukan ini selanjutnya diolah oleh fungsi. Hasil akhir fungsi berupa sebuah nilai (nilai balik fungsi).

### D. Prosedur<br/>
Dalam bahasa pemrograman C++, prosedur adalah istilah yang sering digunakan untuk merujuk pada fungsi yang tidak mengembalikan nilai. Dalam istilah C++, prosedur ini dikenal sebagai fungsi void. Fungsi-fungsi ini melakukan tugas tertentu tetapi tidak memberikan nilai balik (return value) kepada pemanggilnya. Sebaliknya, fungsi yang mengembalikan nilai, seperti int atau double, memberikan hasil yang dapat digunakan lebih lanjut dalam program [3].

### E. Parameter Fungsi<br/>

#### 1. Parameter Formal dan Parameter Aktual
Parameter formal adalah variabel yang ada pada daftar paramerter ketika mendefinisikan fungsi. Pada fungsi maks3() contoh di atas, a, b dan merupakan parameter formal.
```C++
float perkalian (float x, float y) 
{ return (x*y); 
}
```
Pada contoh di atas x dan y adalah parameter formal.
Adapun parameter aktual adalah parameter (tidak selamanya menyatakan variabel) yang dipakai untuk memanggil fungsi.
X = perkalian(a, b);
Y perkalian (10,30);
#### 2. Cara melewatkan Parameter
a. Pemanggilan dengan Nilai (call by value)
Pada pemanggilan dengan nilai, nilai dari parameter aktual akan disalin kedalam parameter formal, jadi parameter aktual tidak akan berubah meskipun parameter formalnya berubah.
b. Pemanggilan dengan Pointer (call by pointer)
Pemanggilan dengan pointer merupakan cara untuk melewatkan alamat suatu variabel ke dalam suatu fungsi. Dengan cara ini dapat mengubah nilai dari variabel aktual yang dilewatkan ke dalam fungsi. Jadi cara ini dapat mengubah variabel yang ada diluar fungsi.

Cara penulisan :
```C++
tukar (int *px, int *py) { 
    int temp; 
    temp = *px; 
    *px = *py:
    *py = temp;
    ... ...
} 
```
Cara pemanggilan:
    tukar (&a, &b);
c. Pemanggilan dengan Referensi (Call by Reference)
Pemanggilan dengan referensi merupakan cara untuk melewatkan alamat suatu variabel kedalam suatu fungsi. Dengan cara ini dapat mengubah nilai dari variabel aktual yang dilewatkan ke dalam fungsi. Jadi cara ini dapat mengubah variabel yang ada diluar fungsi. Cara penulisan :
```C++
tukar (int &px, int &py) { 
    int temp; 
    temp = px; 
    px = py:
    py = temp;
    ... ...
} 
```
Cara pemanggilan:
    tukar (a, b);

## Guided 

### 1. Array 1 Dimensi

```C++
// guided 1 

#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j = 0;
    while(j < 5) {
        cout << "isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
Program ini memanfaatkan array untuk menyimpan data yang diinput oleh pengguna. Pertama-tama, program ini mendeklarasikan sebuah array yang memiliki kapasitas 5 elemen. Selanjutnya, dengan menggunakan perulangan for, pengguna diminta untuk memasukkan angka ke setiap indeks pada array. Setelah semua angka terinput, program akan menampilkan isi array tersebut dengan menggunakan perulangan while, yang mencetak baik indeks maupun nilai yang telah dimasukkan. Dengan cara ini, program ini menunjukkan langkah-langkah dalam proses input, penyimpanan, dan output data di dalam array secara teratur.

### 2. Array 2 Dimensi

```C++
// guided 2

#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    // penjumlahan matriks 2x2
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    // perkalian matriks 2x2
    for(int i = 0; i < 2; i++) {            // perulangan baris
        for(int j = 0; j < 2; j++) {        // perulangan kolom
            for(int k = 0; k < 2; k++) {    // perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
Program ini menjalankan operasi penjumlahan dan perkalian pada dua matriks berukuran 2x2. Pertama-tama, dua matriks didefinisikan, kemudian elemen yang berada pada posisi yang sama dijumlahkan untuk membentuk matriks baru. Selanjutnya, program melakukan perhitungan hasil perkalian matriks dengan memanfaatkan perulangan bersarang untuk mengalikan baris dan kolom. Hasil dari kedua operasi tersebut ditampilkan di output melalui fungsi tampilkanHasil.

### 3. Arr n Pointer

```C++
// guided 3

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10,20,30,40,50};
    int* ptr = arr; // Pointer yang menunjuk ke elemen pertama array

    // Mengakses elemen array menggunakan pointer
    for(int i = 0; i < 5; i++) {
        cout << "Elemen array ke-" << i + 1 << "Menggunakan pointer: " << *(ptr + i) << endl;
    }

    // Mengakses elemen array menggunakan indeks
    for(int i = 0; i < 5; i++) {
        cout << "Elemen array ke-" << i + 1 << "Menggunakan indeks: " << arr[i] << endl;
    }

    return 0;
}
```
Program ini menggambarkan cara untuk mengakses elemen dalam array dengan menggunakan pointer dan indeks. Pertama, sebuah array yang terdiri dari lima angka dibuat, kemudian pointer bernama ptr ditunjukkan ke elemen pertama dari array. Dengan menggunakan perulangan for, program ini menampilkan semua elemen dalam array melalui aritmetika pointer (ptr + i). Setelah itu, program menampilkan elemen yang sama dengan metode biasa menggunakan indeks array. Hasilnya, kedua cara tersebut menghasilkan nilai yang identik, sehingga program ini menunjukkan bahwa pointer bisa menjadi alternatif untuk mengakses elemen dalam array.

### 4. Fungsi Prosedur

```C++
// guided 6 

#include<iostream>
using namespace std;

int cariMax(int arr[], int ukuran){
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++){
        if (arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "Total penjumlahan: " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }
    cout << "Total perkalian: " << totalKali << endl;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "Masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Nilai terbesar dalam array: " << cariMax(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}
```
Program ini berfungsi untuk memproses data array melalui berbagai operasi dasar. Pertama-tama, pengguna diminta untuk memasukkan lima angka ke dalam array. Fungsi cariMAX berperan untuk menemukan dan menampilkan angka tertinggi di dalam array. Setelah itu, fungsi operasiAritmetika menghitung jumlah total dan hasil kali dari semua elemen dalam array, selanjutnya menampilkan hasil tersebut. 

## Unguided 

### 1. Soal Unguided 1
Diketahui 2 buah matriks 3x3 seperti dibawah ini :
matriksA = [17, 12, 22, 31, 6, 41, 15, 19, 36]
MatriksB = [11, 34, 7, 3, 25, 41, 5, 18, 33]

Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan; jumlah Matriks() untuk operasi penjumlahan, kurang Matriks() untuk pengurangan, dan kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case seperti berikut ini:
Menu Program Matriks
1. Penjumlahan matriks
2. Pengurangan matriks
3. Perkalian matriks
4. Keluar

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week3_modul2/output1-unguided1-modul2.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week3_modul2/output2-unguided1-modul2.png)

Program ini berfungsi untuk mengoperasikan dua objek matriks 3x3. Di dalam program, terdapat prosedur untuk menampilkan matriks ke layar, menjumlahkan dua matriks, mengurangkan dua matriks, serta mengalikan matriks tersebut. Dua matriks, yaitu matriks A dan B, telah didefinisikan langsung dalam program. Dengan menggunakan menu berbasis switch-case, pengguna dapat memilih jenis operasi yang ingin dilakukan, antara lain penjumlahan, pengurangan, atau perkalian. Hasil dari masing-masing operasi ditampilkan dalam format matriks berukuran 3x3.

### 2. Soal Unguided 2
Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer, seperti berikut:
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan luas (beri nilai 0).
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar yang menunjuk ke variabel lebar.
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas. Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar.
4) Cetak nilai luas ke layar.
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui pointer ptrPanjang dan ptrLebar.
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa nilainya telah berubah.

```C++
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
```
### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week3_modul2/output-unguided2-modul2.png)

Program ini menghitung luas dan keliling dari sebuah persegi panjang dengan memanfaatkan pointer untuk mengakses dan mengubah nilai dari variabel panjang dan lebar. Pertama, program ini mendeklarasikan beberapa variabel yaitu panjang, lebar, luas, dan keliling, serta pointer yang mengarah ke panjang dan lebar. Luas dan keliling dihitung dengan cara mendereferensikan pointer, dan kemudian hasilnya ditampilkan. Setelah itu, nilai dari panjang dan lebar diubah melalui pointer, dan program menghitung kembali serta menampilkan luas dan keliling berdasarkan nilai yang baru, sehingga menunjukkan bagaimana pointer dapat digunakan untuk mengubah dan mengakses data secara langsung.

## Kesimpulan
Pemrograman dalam C++ memiliki berbagai konsep fundamental yang saling berkaitan untuk mempermudah pengolahan data dan penyusunan program. Array berfungsi sebagai wadah untuk menyimpan sekumpulan data homogen dengan ukuran yang sudah ditentukan, baik dalam satu dimensi, dua dimensi, maupun lebih. Pointer digunakan untuk mengakses dan memanipulasi alamat memori, sehingga sangat berguna dalam efisiensi pengelolaan data, terutama saat bekerja dengan array dan string. Fungsi dan prosedur membantu membuat program lebih terstruktur, modular, serta mengurangi pengulangan kode. Selain itu, konsep parameter formal dan aktual, serta teknik pemanggilan fungsi dengan nilai, pointer, maupun referensi, memungkinkan fleksibilitas dalam pengolahan data. Dengan pemahaman yang baik terhadap array, pointer, fungsi, prosedur, dan parameter, pemrogram dapat menyusun program yang lebih efisien, mudah dipahami, dan mudah dikembangkan.

## Referensi
[1] Pratama, M. A. (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.
<br>
[2] Prasatya. (2024, 10 Desember). Belajar Pointer C++: Dasar-Dasar, Fungsi, dan Contoh Kode. CodePolitan.
<br>
[3] Modul 2 - Praktikum Struktur Data