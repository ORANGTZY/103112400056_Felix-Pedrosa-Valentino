# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)</h1>
<p align="center">Felix Pedrosa Valentino - 103112400056</p>

## Dasar Teori
Bahasa pemrograman, yang juga dikenal sebagai bahasa komputer, adalah metode perintah atau instruksi standar untuk mengendalikan komputer. Bahasa pemrograman digunakan untuk merancang sistem aplikasi sesuai kebutuhan yang bisa digunakan di berbagai sektor, termasuk pendidikan, ekonomi, bisnis, hingga sosial budaya. Hingga kini, terdapat banyak variasi bahasa pemrograman. Salah satu contohnya adalah C++, yang merupakan gabungan dari bahasa C [1,2,3].  C++ merupakan bahasa pemrograman yang diciptakan oleh Bjarne Stroustrup, hasil pengembangan dari bahasa C yang diteliti di Bong Labs (Dennis Ritchie) pada awal tahun 1970-an. Bahasa ini merupakan turunan dari bahasa sebelumnya yaitu B. Pada awal kemunculannya, bahasa ini ditujukan untuk pemrograman di sistem Unix. Seiring waktu, muncul versi ANSI (American National Standard Institute), di mana bahasa C menjadi yang paling banyak digunakan. Meskipun kini versi tersebut jarang digunakan dalam pengembangan sistem, jaringan, atau sistem tertanam, Bjarne Stroustrup pertama kali menciptakan C++ di Bell Labs pada awal 1980-an. Untuk mendukung berbagai fitur di C++, dibuatlah efisiensi dan sistem dukungan untuk pemrograman tingkat rendah. Di C++, diperkenalkan konsep-konsep baru seperti class beserta sifat-sifat seperti inheritance dan overloading. Salah satu perbedaan utama dibandingkan bahasa C adalah adanya dukungan untuk pemrograman berorientasi objek [4]. 

### A. Dasar Pemrograman<br/>

#### 1. Struktur Program C++
Struktur bahasa pemrograman C++ adalah sebagai berikut : [5]
a. #include <iostream> 
untuk pendeklarasian library yang digunakan pada program
b. #define PHI 3.14 
const int constant1;
const float constant2 = o.5; 
untuk pendefinisian konstanta
c. struct new_record_type (
    int element1; 
    float element2;
)
untuk pendefinisian tipe data bentukan / record type / struktur
d. int var1; 
float var2(2);
untuk pendeklarasian variabel
e. int function_A() {
    //
}
void procedure_B() {
    //
}
untuk pendeklarasian fungsi dan prosedur
f. int main() {
    // blok program
    return 0;
}
untuk program utama
#### 2. Pengenal (Identifier) 
Identifier merupakan nama yang biasa digunakan untuk variabel, konstanta, fungsi atau objek lain yang didefinisikan oleh program. [5]
Aturan yang digunakan untuk menentukan identifier:
1. Harus diawali dengan huruf (A....Z, a....z) atau garis bawah (_).
2. Karakter selanjutnya bisa berupa huruf, digit atau karakter garis bawah () atau dollar ($).
3. Panjang maksimal identifier adalah 32 karakter, jika lebih maka yang dianggap adalah 32 karakter awal.
4. Tidak boleh mengandung spasi.
5. Tidak boleh menggunakan operator aritmatika (+- /*%).
Bahasa C++ bersifat case sensitive, jadi huruf besar dan huruf kecil dianggan berbeda
#### 3. Tipe Data Dasar
Data merupakan suatu nilai yang dapat dinyatakan dalam bentuk konstanta atau variabel. Data berdasarkan jenisnya dibagi dalam 5 kelompok, yang dinamakan sebagai tipe data dasar. Kelima kelompok tersebut yaitu : [5]
1. Bilangan bulat (integer).
2. Bilangan real presisi - tunggal.
3. Bilangan real presisi - ganda.
4. Karakter
5. Tak bertipe
#### 4. Variabel
Variabel dalam program digunakan untuk menyimpan nilai, nilai variabel bisa berubah-ubah selama program berjalan. Aturan penamaan variabel sesuai dengan aturan penamaan identifier. Bentuk umum pendeklarasian suatu variabel dalam bahasa pemrograman C dapat ditulis sebagai berikut. [5]
tipe_data nama_variabel;
#### 5. Konstanta
Konstanta menyatakan nilai yang selalu tetap. Seperti halnya dengan variabel, konstanta juga mempunyai tipe. Untuk mendeklarasikan suatu nilai yang sifatnya konstan kita cukup menambahkan kata const di depan tipe data dan variabel. [5]

Contoh:
const float phi 3.14; 
const int n = 20;

### B. Input / Output<br/>

#### 1. Output
a. Fungsi cout()
Fungsi ini digunakan untuk mencetak data yang bertipe numerik, ataupun teks, baik konstanta ataupun variabel.
b. Penentu Format
Pengguna penentu format sangat berkaitan erat dengan suatu tipe data. Artinya suatu tipe data memimilik penentu format masing-masing. Format tersebut dipakai di bahasa C, sedangkan pada C++ tidak harus dipakai.
c. Penentu Lebar Field
Bila kita mencetak data bertipe float, seringkali tampilan yang diberikan tampak kurang manis. Misalnya desimal yang dicetak terlalu banyak.
d. Escape Sequence
Disebut escape sequence, karena notasi '\' dianggap sebagai karakter "escape" (menghindar), dalam arti bahwa karakter yang terdapat setelah tanda '\' dianggap merupakan bukan teks biasa. [5]
#### 2. Input 
a. Fungsi cin()
cin() merupakan salah satu fungsi yang digunakan untuk meminta inputan keyboard dari user. 
b. Penentu Format
Penentu format untuk fungsi cin() tidak sama seperti penentu format seperti pada printf() (digunakan pada C atau C++). 
Pada cin(), kita tidak perlu menggunakan penentu format seperti pada printf(). cin menggunakan operator >> untuk langsung memasukkan nilai yang diinput user ke dalam variabel yang ditentukan.  
c. Fungsi getchar()
getchar() adalah fungsi yang digunakan untuk membaca satu karakter dari input standar (biasanya keyboard). Fungsi ini akan menunggu pengguna menekan sebuah tombol pada keyboard, lalu mengembalikan karakter tersebut. Fungsi ini sering digunakan untuk membaca input karakter tunggal dari pengguna.

Berbeda dengan cin, yang memungkinkan pengguna memasukkan lebih dari satu karakter dan membutuhkan menekan tombol enter untuk menyelesaikan input, getchar() hanya membaca satu karakter dan tidak memerlukan enter untuk melanjutkan eksekusi program. Begitu satu karakter diketikkan, program akan langsung melanjutkan ke perintah berikutnya. [5]

Dalam C++, getchar() juga dapat digunakan melalui namespace std jika kita hanya menggunakan header <iostream>. 

### C. Operator<br/>
Operator adalah suatu simbol yang digunakan untuk melakukan sesuatu operasi atau manipulasi. Bahasa C++ merupakan bahasa yang kaya dengan operator yaitu : Operator Aritmatika, Operator Pengerjaan, Operator Logika, Operator Unary, Operator Bitwisie, Operator Kondisional, dan lain-lain. [5]
#### 1. Operator Aritmatika
Misalkan terdapat ungkapan sebagai berikut: A + B / C + D. Untuk mengubah jenjang dapat digunakan tanda kurung '()' (sebagai operator jenjang tertinggi) sebagai berikut: (A + B)/(C + D)
#### 2. Operator Pengerjaan (Assignment)
Operator ini digunakan untuk memindahkan nilai dari suatu ungkapan ke suatu pengenal. Di samping operator pengerjaan yang umumnya digunakan di bahasa-bahasa pemrograman, bahasa C++ menyediakan beberapa operator pengerjaan lain. [5]
Misalnya: A += 7, ekuivalen dengan, A = A + 7
#### 3. Operator Logika
Operasi logika membandingkan dua buah nilai logika. Nilai logika adalah nilai benar atau salah. [5]
Misalnya:
1. (kar > 'A') && (kar < 'Z') 
Hasil operasi && bernilai benar hanya jika kar > 'A' dan kar < 'Z'
2. (pilihan == 'Y') || (pilihan == 'y') 
Hasil operasi logika || bernilai benar jika pilihan berupa 'Y' atau 'y'.
3. ! operand 
Hasil operand! akan bernilai benar jika operand bernilai salah dan sebaliknya.
#### 4. Operator Unary
a. Operator Uneary tipe
Jika pernyataan Z = (X + Y)/(Y+W) yang memiliki output 2.000000 diubah menjadi Z = (float) (X + Y)/(Y + W) maka outputnya menjadi: Nilai Z = 2.500000. Mengapa demikian? Itulah peranan dari operator tipe ini. Operator ini akan menghasilkan tipe data yang diinginkan walau berasal dari operand-operand dengan tipe berbeda. [5]
b. Operator Unary sizeof
Operator Unary sizeof digunakan untuk mengetahui ukuran memory dari operandnya dalam satuan byte. Misalnya untuk komputer IBM PC, ukuran dari nilai float adalah 4 byte, kemungkinan di komputer yang lain, ukuran float bukan 4 byte. Contoh penggalan program penggunaan sizeof:
    printf("Ukuran karakter = %d byte \n", sizeof(char)); 
#### 5. Operator sizeof
Operator sizeof menghasilkan ukuran dari variabel atau suatu tipe pada saat kompilasi program. Penggunaan sizeof dengan operan (berupa variabel atau tipe) yang ditempatkan dalam tanda kurung. 
Contoh: 
sizeof(char) → 1 sizeof(int) 2

Operator ini sangat bermanfaat untuk menghitung besarnya sebarang tipe atau variabel, terutama untuk variabel dan tipe yang kompleks (seperti struktur). [5]
#### 6. Operator Increment dan Decrement
Bahasa C++ menyediakan 2 operator yang tidak biasa untuk increment dan decrement. Operator increment ++ akan menambahkan nilai 1 dari variabel, sedangkan operator decrement mengurangi variabel dengan nilai 1. 
Contoh:
++1; // ekuivalen dengan i=i+1
--j; // ekuivalen dengan j=j-1

Kedua operator ini bisa diletakkan sebelum variabel (prefix, contoh: ++i), dan sesudah variabel (postfix, contoh: i++). Effect dari keduanya sama yaitu akan menambahkan nilai 1 ke variabel i. Akan tetapi, untuk ekspresi ++i dan i++ ada bedanya. Jika ekspresi ++i maka variabel akan di-increment dulu sebelum digunakan sedangkan untuk operator i++ maka nilai i akan digunakan terlebih dahulu setelah itu baru di-increment. [5]

### D. Pemodifikasi Tipe<br/>
Pemodifikasi tipe (type modifier) dapat dikenakan diawal tipe data kecuali untuk void. [5]
#### 1. Unsigned
Tipe data ini digunakan bila kita hanya ingin bekerja dengan data yang bernilai positif saja. Misalnya unsigned integer akan menerima data dari 0-65.535. (tidak lagi dari -32.768 hingga 32.768). 
#### 2. Short 
Tipe data ini kadangkala disamakan dengan integer dan kadangkala juga dibedakan, tergantung pada sistem dan jenis komputer yang digunakan. 
#### 3. Long
Tipe data ini digunakan untuk menaikkan kapasitas dari suatu variabel. Misalnya long integer memiliki bilangan bulat dari -2.147.483.648 hingga 2.147.483.647 

### E. Kondisional<br/>
Untuk menyelesaikan suatu masalah diperlukan pengambilan keputusan, Bahasa C++ menyediakan beberapa jenis pernyataan berupa operator kondisi sebagai berikut. 
1. Pernyataan if
2. Pernyataan if-else
3. Pernyataan switch
Pernyataan pengambilan keputusan di atas memerlukan suatu kondisi sebagai basis pada pengambilan keputusan. Kondisi umum yang dipakai keadaan benar atau salah. [5]
#### 1. Bentuk 1
if (kondisi)
    pernyataan;

Arti dari perintah if di atas adalah jika kondisi benar maka pernyataan akan dijalankan. Sedangkan kondisi ditulis di antara tanda kurung, dapat berupa ungkapan yang memiliki nilai benar atau salah. Dan pernyataan berupa sebuah pernyataan tunggal pernyataan majemuk atau pernyataan kosong.
#### 2. Bentuk 2
if (kondisi)
    pernyataan1 ;
else
    pernyataan2 ; 

Arti dari pernyataan if-else di atas adalah
1. Jika kondisi benar, maka pernyataan1 dijalankan.
2. Jika kondisi salah, maka pernyataan2 yang akan dijalankan.

pernyataan1 dan pernyataan2 dapat berupa sebuah pernyataan tunggal, pernyataan majemuk ataupun pernyataan kosong. Bentuk ini dapat disederhanakan dengen kondisional ekspresi dengan bentuk umumnya sebagai berikut.
        expr1 ? expr2 : expr3
Jika expr1 benar maka expr2 yang dijalankan, sedangkan jika salah maka expr3 yang dijalankan.
#### 3. Bentuk 3
Bentuk ketiga menggunakan pernyataan switch, merupakan pernyataan yang dirancang khusus untuk menangani pengambilan keputusan yang melibatkan banyak alternatif.

Bentuk umumnya:
switch (variabel) {
case kondisi1: pernyataan1; break;
    case kondisi2 : pernyataan2;
break;
    default: pernyataan_n; 
    break;
}

Pengujian pada switch akan dimulai dari kondisi1, kalau nilai kondisi1 cocok maka pernyataan1 dilakukan, bila tidak cocok akan diteruskan pada pengecekan pernyataan2. Bila tidak ditemukan kondisi yang cocok maka statement pada default akan dilakukan.

### F. Perulangan<br/>
Apabila kita ingin menuliskan angka 1 s.d. 5 secara berurutan maka kita bisa saja menuliskan semua angka tersebut secara manual karena range yang ditulis masih kecil. Lain halnya apabila angka yang ingin kita tulis range-nya dari 1 s.d. 10000 , diperlukan suatu cara yaitu perulangan (looping). Perulangan digunakan untuk mengefisienkan waktu dan meringkas kode program dalam pengeksekusian sub-program yang sama. Hal yang terpenting dalam perulangan adalah harus ada kondisi berhenti. [5]
#### 1. Perulangan dengan for dan while
Perulangan for dan while biasa digunakan saat kondisi ekspresi terpenuhi. Jika tidak maka perulangan akan terhenti.

Di bawah ini merupakan bentuk umum perulangan for:
for (initialization; condition; increment/decrement)
    statement;

Bentuk for di atas ekuivalen dengan bentuk while di bawah ini:
initialization;
while (condition) {
    statement;
    increment/decrement;
}

Keterangan:
1. initialization: pernyataan untuk menyatakan keadaan awal dari variabel control.
2. condition: ekspresi relasi yang menyatakan kondisi untuk keluar dari perulangan.
3. increment/decrement: pengatur perubahan nilai variabel kontrol. 
#### 2. Perulangan dengan do ... while
Pada dasarnya struktur perulangan do...while sama saja dengan struktur while, hanya saja pada proses perulangan dengan while, seleksi berada di while yang letaknya di atas sementara pada perulangan do...while, seleksi while berada di bawah batas perulangan. Jadi dengan menggunakan struktur do...while sekurang-kurangnya akan terjadi satu kali perulangan.

Bentuk umum perulangan do... while adalah sebagai berikut:
    do {
    statement;
    } while (condition);

### G. Struktur<br/>
Struktur merupakan tipe data bentukan berupa kumpulan dari variabel yang dinyatakan dalam sebuah nama, setiap variabel bisa memiliki tipe yang berlainan. Struktur bisa digunakan untuk mengelompokkan beberapa informasi yang saling berkaitan menjadi satu kesatuan (dalam bahasa pascal, struktur disebut dengan record). [5]

Bentuk umum pendeklarasian struktur: 
struct nama_tipe_struktur {
    tipe field1;
    tipe field2;
    .
    tipe fieldN;
    } variabel_struktur1 ... variabel_strukturN;

Mengakses elemen struktur menggunakan tanda dot atau (.):
    variabel_struktur.nama_field

Tipe data struktur ini cukup rumit, tetapi sangat penting dalam pemrograman bahasa C++, terutama dalam struktur data. Untuk merepresentasikan data sebagian besar akan menggunakan struktur yang dikombinasikan dengan array maupun pointer.

### H. Blok Program<br/>
Setiap bahasa komputer disusun dengan struktur yang berbeda. Untuk dapat mengerti bagaimana membuat program maka kita harus dapat memahami struktur dari program tersebut terlebih dahulu. Struktur program dari bahasa C++ terdiri dari fungsi-fungsi, seperti berikut :  [5]

fungsi_lain () { // fungsi lain yang ditulis programmer
    /* bagian ini berisi statement */
}
main () { // fungsi utama
    /* bagian ini berisi statement */
}

## Guided 

### 1. Input / Output 

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "masukkan angka : ";
    cin >> angka;
    cout << "Angka yang dimasukkan " << angka << endl;
    return 0;
}
```
Program ini berfungsi untuk menerima dan menampilkan kembali masukan pengguna. Saat dijalankan, program akan terlebih dahulu meminta pengguna untuk memasukkan sebuah bilangan bulat. Angka yang diinputkan tersebut kemudian disimpan dalam sebuah variabel, lalu program akan segera menampilkannya kembali ke layar sebagai output.

### 2. Operator Aritmatika

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    cout << "masukkan angka 2 : ";
    cin >> angka2;
    
    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian : " << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;
    cout << "sisa bagi : " << angka1 % angka2 << endl;
    return 0;
}
```
Program ini adalah sebuah kalkulator aritmatika sederhana yang meminta pengguna untuk memasukkan dua buah bilangan bulat. Setelah kedua angka diterima, program akan langsung menghitung dan menampilkan lima hasil operasi dasar secara berurutan, yaitu: penjumlahan (`+`), pengurangan (`-`), perkalian (`*`), pembagian integer (`/`), dan sisa bagi atau modulus (`%`).

### 3. Percabangan

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    cout << "masukkan angka 2 : ";
    cin >> angka2;

    if (angka1 < angka2) {
        cout << angka1 << " kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    // if (angka1 == angka2) {
    //     cout << angka1 << " sama dengan " << angka2 << endl;
    // } else if (angka1 != angka2) {
    //     cout << "angka berbeda" << endl;
    // }

    int pilihan; 
    cout << "MENU" << endl;
    cout << "1. penjumlahan" << endl;
    cout << "2. pengurangan" << endl;
    cout << "masukkan pilihan : " << endl;
    cin >> pilihan;

    switch(pilihan) {
        case 1:
        cout << "penjumlahan : " << angka1 + angka2 << endl;
        cout << endl;
        break;
        case 2:
        cout << "pengurangan : " << angka1 - angka2 << endl;
        cout << endl;
        break;
        default : 
        cout << "pilihan salah" << endl;
    }

    return 0;
}
```
Program ini memiliki dua fungsionalitas utama yang berjalan secara berurutan. Awalnya, program meminta input dua bilangan bulat dari pengguna dan langsung melakukan perbandingan untuk menentukan apakah bilangan pertama lebih kecil atau lebih besar/sama dengan bilangan kedua. Setelah hasil perbandingan ditampilkan, program kemudian menyajikan sebuah menu kalkulator sederhana, di mana pengguna dapat memilih untuk melakukan operasi penjumlahan atau pengurangan pada kedua bilangan yang telah diinputkan sebelumnya.

### 4. Perulangan

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    
    for (int i = 0; i < angka1; i++) { //increment
        cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1) {
        cout << j << " - ";
        j--; //decrement
    }

    cout << endl;
    int k = 10;
    do {
        cout << k << " - ";
    } while (k < angka1);
    
    return 0;
}
```
Program ini bertujuan untuk mendemonstrasikan tiga jenis struktur perulangan (loop) yang berbeda  dengan menggunakan satu input bilangan bulat dari pengguna. Pertama, sebuah for loop digunakan untuk mencetak urutan angka yang menaik (increment) mulai dari 0 hingga batas angka yang diinputkan. Kedua, sebuah while loop mencetak urutan angka yang menurun (decrement) mulai dari 10. Terakhir, sebuah do-while loop dijalankan untuk menunjukkan perilakunya yang selalu mengeksekusi perintah setidaknya satu kali, terlepas dari kondisi yang diberikan.

### 5. Struct

```C++
#include <iostream>
using namespace std;

int main() {
    const int MAX = 3;
    struct rapot{
        string nama;
        float nilai;
    };
    rapot siswa[MAX];
    
    for(int i = 0; i < MAX; i++) {
        cout << "masukkan nama siswa : ";
        cin >> siswa[i].nama;
        cout << "masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
        cout << endl;
    }

    int j = 0;
    while (j < MAX) {
        cout << "Nama siswa : " << siswa[j].nama << ", Nilai : " << siswa[j].nilai << endl;
        j++;
    } 

    return 0;
}
```
Program ini merupakan sistem pendataan nilai siswa sederhana dengan kapasitas tetap untuk tiga orang. Program ini menggunakan sebuah struct untuk mengelompokkan nama dan nilai dari setiap siswa. Prosesnya terbagi menjadi dua tahap: pertama, program akan menggunakan perulangan for untuk meminta pengguna menginputkan data ketiga siswa satu per satu. Setelah semua data tersimpan dalam sebuah array, program akan menggunakan perulangan while untuk menampilkan kembali seluruh daftar nama beserta nilai siswa yang telah dimasukkan ke layar. 

## Unguided 

### 1. Soal Unguided 1

Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
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
```
### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week2_modul1/output-unguided1-modul1.png)

Program ini merupakan sebuah kalkulator empat fungsi dasar yang dirancang untuk bekerja dengan bilangan desimal (float). Program akan meminta pengguna untuk menginputkan dua angka, kemudian langsung menghitung dan menampilkan hasil dari tiga operasi: penjumlahan, pengurangan, dan perkalian. Untuk operasi pembagian, program dilengkapi dengan sebuah kondisi pengecekan khusus untuk memastikan angka pembagi bukan nol. Jika pembagi adalah nol, program akan menampilkan pesan peringatan untuk mencegah error; jika tidak, hasil pembagian akan ditampilkan seperti operasi lainnya. 

### 2. Soal Unguided 2

Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
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
```
### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week2_modul1/output-unguided2-modul1.png)

Program ini adalah sebuah konverter angka ke tulisan dalam bahasa Indonesia yang bekerja untuk rentang bilangan bulat dari 0 hingga 100. Inti dari program ini adalah sebuah fungsi yang secara cerdas menggunakan array sebagai kamus untuk nama-nama bilangan (satuan, belasan, dan puluhan), sehingga kode lebih efisien. Logikanya memecah angka input ke dalam beberapa kondisi, seperti bilangan satuan, belasan, dan puluhan, lalu merangkai kata yang sesuai dari kamus tersebut. Program utama (main) bertugas untuk menangani interaksi dengan pengguna, termasuk memvalidasi input agar tetap dalam jangkauan yang ditentukan, sebelum akhirnya memanggil fungsi konversi untuk mencetak hasilnya.

### 3. Soal Unguided 3

Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;

    for (int i = n; i >= 1; i--) {
        for (int spasi = 0; spasi < n - i; spasi++) {
            cout << "  "; 
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j;
            if (j != i) cout << " ";
        }

        cout << endl;
    }

    for (int spasi = 0; spasi < n; spasi++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}
```
### Output Unguided 3 :

![Screenshot Output Unguided 3_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week2_modul1/output-unguided3-modul1.png)

Program ini merupakan sebuah generator pola visual yang menggunakan perulangan bersarang (nested loops) untuk menciptakan bentuk piramida sama kaki terbalik di layar. Berdasarkan satu input bilangan bulat n dari pengguna, program akan membangun setiap barisnya secara simetris. Untuk setiap baris, program terlebih dahulu mencetak spasi untuk menempatkan output di tengah, kemudian mencetak urutan angka menurun, sebuah tanda bintang * di bagian tengah, dan diakhiri dengan urutan angka menaik. Pola ini menyusut di setiap barisnya dan diakhiri dengan satu tanda bintang di puncaknya.

## Kesimpulan
Bahasa pemrograman C++ bermula dari bahasa C, yang dikembangkan oleh Bjarne Stroustrup, berkaitan erat dengan Pemrograman Berorientasi Objek (OOP). C++ dibangun di atas struktur program yang jelas, yang dimulai dengan pustaka deklarasi (#include) dan definisi variabel serta konstanta menggunakan tipe data spesifik seperti int dan float. Setiap elemen diberi nama unik melalui pengenal yang mematuhi aturan penamaan yang ketat dan bersifat case-sensitive. Untuk berinteraksi dengan pengguna, C++ menggunakan perintah cout dan cin untuk menampilkan output dan cin untuk menerima input. Bahasa ini juga dapat digunakan sebagai operator untuk berbagai manipulasi data, mulai dari matematika, logaritma, hingga increment/decrement. Eksekusi program dilakukan secara efisien menggunakan pernyataan kondisional seperti if-else dan switch untuk keputusan, serta mekanisme for, while, dan do-while untuk tugas-tugas berulang. Selain itu, C++ menyediakan fitur bernama struct yang memungkinkan untuk mengonversi beberapa variabel menjadi satu nilai logis. 

## Referensi
[1] Arsyad, A. (1997). Media pembelajaran. Jakarta: RajaGrafindo.
<br>
[2] Heriyanto, A. K. (2006). Algoritma pemrograman menggunakan C++. Yogyakarta: Andi.
<br>
[3] Raharjo, B. (2006). Pemrograman C++. Bandung: Informatika.
<br>
[4] Fakultas Teknik, Jurusan Teknik Elektro. (2018). Modul Praktikum Dasar Pemrograman Komputer: Pengenalan Bahasa C++, Algoritma Pemrograman, Integrated Development Equipment (IDE) Visual C++ dan Dasar Dasar Bahasa C++. Universitas Negeri Malang.
<br>
[5] Modul 1 - Praktikum Struktur Data
