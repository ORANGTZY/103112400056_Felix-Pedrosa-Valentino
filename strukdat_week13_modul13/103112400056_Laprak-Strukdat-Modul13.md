# <h1 align="center">Laporan Praktikum Modul 13 - Multi Linked List</h1>
<p align="center">Felix Pedrosa Valentino - 103112400056</p>

## Dasar Teori
Struktur data Linked List adalah sekumpulan elemen data (node) yang urutannya ditentukan oleh pointer atau penunjuk. Berbeda dengan array yang memiliki ukuran tetap, Linked List memungkinkan alokasi memori secara dinamis, di mana setiap node menunjuk ke node berikutnya dalam urutan linear [1]. Namun, dalam representasi data yang lebih kompleks yang melibatkan hubungan hierarkis atau relasional, Single Linked List biasa seringkali tidak cukup. Oleh karena itu, dikembangkanlah konsep Multi Linked List.

Multi Linked List (MLL) adalah variasi dari Linked List di mana setiap node memiliki kemungkinan untuk memiliki lebih dari satu pointer yang menghubungkan ke node lain, baik dalam satu list yang sama maupun ke list yang berbeda [2]. Secara umum, MLL digunakan untuk merepresentasikan hubungan data yang bersifat One-to-Many (satu ke banyak) atau Many-to-Many (banyak ke banyak). Contoh implementasi paling umum adalah hubungan antara data induk (Parent) dengan data anak (Child), seperti data Mahasiswa (Parent) yang mengambil banyak Mata Kuliah (Child). Dalam struktur ini, node Parent tidak hanya memiliki pointer next yang menunjuk ke Parent berikutnya, tetapi juga memiliki pointer tambahan (sering disebut child atau sub) yang menunjuk ke alamat node pertama dari list Child yang dimilikinya [3].

Dalam bahasa pemrograman C++, implementasi MLL dilakukan dengan menggunakan struct atau class. Struktur data ini memerlukan dua jenis definisi node yang berbeda atau satu definisi node yang fleksibel, tergantung pada desainnya. Pada model Parent-Child, pointer pada Parent yang mengarah ke Child akan bernilai NULL jika data induk tersebut tidak memiliki anak [2]. Keuntungan utama menggunakan MLL dibandingkan struktur data linear lainnya adalah efisiensi dalam merepresentasikan data yang berkelompok tanpa membuang memori untuk slot kosong (seperti pada multidimensional array), serta kemudahan dalam operasi penyisipan dan penghapusan data pada level hierarki tertentu tanpa mengganggu struktur keseluruhan [1].

Operasi traversal (penelusuran) pada Multi Linked List memiliki kompleksitas yang lebih tinggi dibandingkan Single Linked List. Algoritma penelusuran biasanya melibatkan nested loop (perulangan bersarang), di mana pointer utama menelusuri list Parent, dan pada setiap node Parent, pointer sekunder melakukan traversal ke dalam list Child yang terkait [3]. Pemahaman mendalam mengenai manajemen memori dan manipulasi pointer sangat krusial dalam MLL untuk mencegah terjadinya memory leak atau dangling pointer saat node dihapus.

## Guided 

### 1. Guided 1

multilist.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>

using namespace std;

typedef struct nodeParent *NodeParent; // alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild; // alias pointer ke struct nodeChild 

struct nodeChild { // node child
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
}; 

struct listAnak { // list child
    NodeChild first;
    NodeChild last;
};

struct nodeParent { // node parent
    string idKategoriMakanan;
    string namaKategoriMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk { // list parent
    NodeParent first;
    NodeParent last;
};

// create list
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

// alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);

// alokasi & dealokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeChild(NodeChild &nodeAnak);

// operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

// operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);

// operasi print
void printStrukturMLL(listInduk &LInduk);

#endif
```

multilist.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```

main.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk LInduk;
    createListInduk(LInduk);

    // 2. Membuat Data Parent (Kategori Makanan)
    NodeParent K01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, K01);
    NodeParent K02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, K02);
    NodeParent K03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, K03);
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    // --> Isi Kategori Makanan Berat (K01) 
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng Spesial");
    insertLastChild(K01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(K01->L_Anak, M02);
    // --> Isi Kategori Minuman (K02) 
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(K02->L_Anak, D02);
    NodeChild D01 = alokasiNodeChild("D01", "Es Teh Manis");
    insertLastChild(K02->L_Anak, D01);
    // --> Isi Kategori Dessert (K03) 
    NodeChild S01 = alokasiNodeChild("S01", "Puding Cokelat");
    insertLastChild(K03->L_Anak, S01);
    cout << endl;

    // 4. Print mll setelah insert-insert
    printStrukturMLL(LInduk);
    cout << endl;

    // 5. searching node child
    findChildByID(LInduk, "D01");
    cout << endl;

    // 6. delete node child
    deleteAfterChild(K01->L_Anak, M01); //  menghapus node child ayam bakar madu
    cout << endl;

    // 7. delete node parent
    deleteAfterParent(LInduk, K02); // menghapus node parent Dessert
    cout << endl;

    // 8. print mll setelah delete-delete
    printStrukturMLL(LInduk);
    cout << endl;
    
    return 0;
}
```

Program ini mengimplementasikan struktur data Multi Linked List (MLL) menggunakan bahasa C++ untuk memodelkan hubungan hierarkis antara Kategori Makanan sebagai node Parent dan Menu Makanan sebagai node Child. Desain struktur data yang digunakan adalah variasi Double Linked List pada kedua level (baik Parent maupun Child), di mana setiap node dilengkapi dengan pointer next dan prev untuk navigasi dua arah. Struktur struct nodeParent secara khusus memiliki komponen listAnak, yang memungkinkan setiap kategori makanan menampung daftar menu makanannya sendiri, menciptakan relasi one-to-many.

Secara fungsional, program ini menyediakan operasi dasar manajemen data yang meliputi alokasi memori dinamis, penyisipan data di akhir list (insertLast) untuk kategori dan menu, serta penghapusan data (deleteAfter). Logika penghapusan pada Parent dirancang secara rekursif atau bertingkat, di mana menghapus sebuah kategori akan secara otomatis memicu fungsi hapusListAnak untuk membersihkan seluruh menu yang ada di dalamnya terlebih dahulu, guna mencegah terjadinya memory leak. Selain itu, terdapat fitur traversal kompleks seperti findChildByID yang menggunakan perulangan bersarang (nested loop) untuk mencari keberadaan menu tertentu di seluruh kategori dan menampilkan lokasi spesifiknya.

Pada eksekusi utama (main), program mensimulasikan skenario pengelolaan data restoran sederhana. Dimulai dengan inisialisasi list induk, program kemudian membentuk tiga kategori (Makanan Berat, Minuman, Dessert) dan mengisi masing-masing dengan menu terkait. Program kemudian mendemonstrasikan validitas logika pointer melalui operasi pencarian data, penghapusan satu menu spesifik, dan penghapusan satu kategori utuh (Dessert) yang berada setelah kategori Minuman. Seluruh perubahan struktur data ditampilkan ke konsol melalui fungsi printStrukturMLL untuk memverifikasi hierarki data yang terbentuk.

## Unguided 

### 1. Soal Unguided 1 (isi dengan soal unguided 1)
![Screenshot Soal Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week13_modul13/SoalUnguided1-Bagian1-Modul13.png)
![Screenshot Soal Unguided 1_2](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week13_modul13/SoalUnguided1-Bagian2-Modul13.png)
![Screenshot Soal Unguided 1_3](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week13_modul13/SoalUnguided1-Bagian3-Modul13.png)
![Screenshot Soal Unguided 1_4](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week13_modul13/SoalUnguided1-Bagian4-Modul13.png)
![Screenshot Soal Unguided 1_5](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week13_modul13/SoalUnguided1-Bagian5-Modul13.png)
![Screenshot Soal Unguided 1_6](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week13_modul13/SoalUnguided1-Bagian6-Modul13.png)

MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

// Definisi Struktur Data
struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor; // 1 (True) jika berekor, 0 (False) jika tidak
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child; // List child berada di dalam node parent
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

// --- Prototypes ---

// Cek Kosong
bool isEmptyParent(listParent L);
bool isEmptyChild(listChild L);

// Create List
void createListParent(listParent &L);
void createListChild(listChild &L);

// Alokasi Node
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

// Dealokasi
void deallocNodeParent(NodeParent p); // Menghapus node parent
void deallocNodeChild(NodeChild c);   // Menghapus node child

// Operasi Parent (Double Linked List)
void insertFirstParent(listParent &L, NodeParent P);
void insertLastParent(listParent &L, NodeParent P);
void deleteFirstParent(listParent &L);
void deleteAfterParent(listParent &L, NodeParent Pre); // Dibutuhkan untuk menghapus G004 (setelah G003)
void deleteListChild(listChild &L); // Helper untuk membersihkan child sebelum parent dihapus

// Operasi Child (Double Linked List)
void insertFirstChild(listChild &L, NodeChild C);
void insertLastChild(listChild &L, NodeChild C);
void deleteFirstChild(listChild &L);
void deleteAfterChild(listChild &L, NodeChild Pre);

// Print
void printMLLStructure(listParent L);

// SEARCHING (Untuk Nomor 2)
void searchHewanByEkor(listParent L, bool tail);

#endif
```

MultiLL.cpp
```C++
#include "MultiLL.h"

// --- IMPLEMENTASI DASAR (NOMOR 1) ---

bool isEmptyParent(listParent L) {
    return L.first == NULL;
}

bool isEmptyChild(listChild L) {
    return L.first == NULL;
}

void createListParent(listParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L) {
    L.first = NULL;
    L.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child); // Penting: inisialisasi list child
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void insertLastParent(listParent &L, NodeParent P) {
    if (isEmptyParent(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertLastChild(listChild &L, NodeChild C) {
    if (isEmptyChild(L)) {
        L.first = C;
        L.last = C;
    } else {
        C->prev = L.last;
        L.last->next = C;
        L.last = C;
    }
}

void deleteFirstChild(listChild &L) {
    if (!isEmptyChild(L)) {
        NodeChild P = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
            P->next = NULL;
        }
        delete P;
    }
}

void deleteListChild(listChild &L) {
    while (!isEmptyChild(L)) {
        deleteFirstChild(L);
    }
}

void deleteAfterParent(listParent &L, NodeParent Pre) {
    if (Pre != NULL && Pre->next != NULL) {
        NodeParent Del = Pre->next;
        
        // Hapus semua child dulu agar tidak memori leak
        deleteListChild(Del->L_Child);

        Pre->next = Del->next;
        if (Del->next != NULL) {
            Del->next->prev = Pre;
        } else {
            L.last = Pre;
        }
        delete Del;
    }
}

void printMLLStructure(listParent L) {
    NodeParent P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "Parent " << i << endl;
        cout << "ID Golongan: " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan: " << P->isidata.namaGolongan << endl;

        if (isEmptyChild(P->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << " - Child " << j << ":" << endl;
                cout << "   ID Hewan: " << C->isidata.idHewan << endl;
                cout << "   Nama Hewan: " << C->isidata.namaHewan << endl;
                cout << "   Habitat: " << C->isidata.habitat << endl;
                cout << "   Ekor: " << C->isidata.ekor << endl;
                cout << "   Bobot: " << C->isidata.bobot << endl;
                C = C->next;
                j++;
            }
        }
        cout << endl;
        P = P->next;
        i++;
    }
}
```

main.cpp
```C++
#include "MultiLL.h" // Include header 

// Variabel global untuk List Utama agar bisa diakses di berbagai step
listParent LP;

int main() {
    // --- BAGIAN NOMOR 1: CREATE & INSERT ---
    createListParent(LP);

    NodeParent P;
    NodeChild C;

    // 1. Insert Parent G001 (Aves)
    P = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P);
        // Child G001
        C = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
        insertLastChild(P->L_Child, C);
        C = allocNodeChild("AV002", "Bebek", "Air", true, 2.0);
        insertLastChild(P->L_Child, C);

    // 2. Insert Parent G002 (Mamalia)
    P = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P);
        // Child G002
        C = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
        insertLastChild(P->L_Child, C);
        C = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
        insertLastChild(P->L_Child, C);
        C = allocNodeChild("M002", "Kucing", "Darat", true, 4);
        insertLastChild(P->L_Child, C);

    // 3. Insert Parent G003 (Pisces)
    P = allocNodeParent("G003", "Pisces");
    insertLastParent(LP, P);
        // No Child

    // 4. Insert Parent G004 (Amfibi)
    P = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P);
        // Child G004
        C = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
        insertLastChild(P->L_Child, C);

    // 5. Insert Parent G005 (Reptil)
    P = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P);
        // No Child

    // PRINT HASIL NOMOR 1
    cout << "=== OUTPUT NOMOR 1 (STRUCTURE) ===" << endl;
    printMLLStructure(LP);
    cout << "==================================" << endl << endl;

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week13_modul13/output1-unguided1-modul13.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week13_modul13/output2-unguided1-modul13.png)

Program ini mengimplementasikan struktur data Multi Linked List (MLL) untuk memodelkan hierarki klasifikasi hewan, di mana terdapat hubungan "Parent-Child". Parent List merepresentasikan Golongan Hewan (seperti Mamalia, Aves, dll.), sedangkan Child List merepresentasikan data spesifik hewan (seperti Harimau, Bebek) yang terhubung langsung ke Parent-nya. Baik struktur Parent maupun Child dibangun menggunakan konsep Double Linked List, yang memiliki pointer next dan prev, memungkinkan penelusuran data secara bolak-balik (dua arah).

Secara fungsional, modul program (MultiLL.h dan MultiLL.cpp) menyediakan sekumpulan operasi Abstract Data Type (ADT) yang lengkap. Ini mencakup alokasi memori untuk node baru, prosedur penyisipan data (insert) di awal atau akhir list, serta mekanisme penghapusan data (delete). Salah satu logika penting dalam program ini adalah penanganan penghapusan Parent (deleteAfterParent), yang dirancang untuk secara otomatis menghapus seluruh daftar Child (deleteListChild) yang berada di bawahnya terlebih dahulu sebelum menghapus node Parent itu sendiri, guna mencegah terjadinya kebocoran memori (memory leak).

Pada eksekusi utamanya (main.cpp), program mendemonstrasikan pembentukan struktur data tersebut dengan menginisialisasi list kosong dan memasukkan data secara bertahap. Program menyusun lima node Parent (Aves, Mamalia, Pisces, Amfibi, Reptil) dan mengisi masing-masing Parent dengan node Child yang relevan sesuai spesifikasi soal. Akhirnya, program memanggil prosedur printMLLStructure untuk menelusuri seluruh node dari Parent pertama hingga terakhir, sekaligus mencetak setiap Child yang dimiliki oleh masing-masing Parent, menampilkan struktur hierarki data secara visual di layar. 

### 2. Soal Unguided 2 
![Screenshot Soal Unguided 2_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week13_modul13/SoalUnguided2-Modul13.png)

MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

// Definisi Struktur Data
struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor; // 1 (True) jika berekor, 0 (False) jika tidak
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child; // List child berada di dalam node parent
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

// --- Prototypes ---

// Cek Kosong
bool isEmptyParent(listParent L);
bool isEmptyChild(listChild L);

// Create List
void createListParent(listParent &L);
void createListChild(listChild &L);

// Alokasi Node
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

// Dealokasi
void deallocNodeParent(NodeParent p); // Menghapus node parent
void deallocNodeChild(NodeChild c);   // Menghapus node child

// Operasi Parent (Double Linked List)
void insertFirstParent(listParent &L, NodeParent P);
void insertLastParent(listParent &L, NodeParent P);
void deleteFirstParent(listParent &L);
void deleteAfterParent(listParent &L, NodeParent Pre); // Dibutuhkan untuk menghapus G004 (setelah G003)
void deleteListChild(listChild &L); // Helper untuk membersihkan child sebelum parent dihapus

// Operasi Child (Double Linked List)
void insertFirstChild(listChild &L, NodeChild C);
void insertLastChild(listChild &L, NodeChild C);
void deleteFirstChild(listChild &L);
void deleteAfterChild(listChild &L, NodeChild Pre);

// Print
void printMLLStructure(listParent L);

// SEARCHING (Untuk Nomor 2)
void searchHewanByEkor(listParent L, bool tail);

#endif
```

MultiLL.cpp
```C++
#include "MultiLL.h"

// --- IMPLEMENTASI DASAR (NOMOR 1) ---

bool isEmptyParent(listParent L) {
    return L.first == NULL;
}

bool isEmptyChild(listChild L) {
    return L.first == NULL;
}

void createListParent(listParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L) {
    L.first = NULL;
    L.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child); // Penting: inisialisasi list child
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void insertLastParent(listParent &L, NodeParent P) {
    if (isEmptyParent(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertLastChild(listChild &L, NodeChild C) {
    if (isEmptyChild(L)) {
        L.first = C;
        L.last = C;
    } else {
        C->prev = L.last;
        L.last->next = C;
        L.last = C;
    }
}

void deleteFirstChild(listChild &L) {
    if (!isEmptyChild(L)) {
        NodeChild P = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
            P->next = NULL;
        }
        delete P;
    }
}

void deleteListChild(listChild &L) {
    while (!isEmptyChild(L)) {
        deleteFirstChild(L);
    }
}

void deleteAfterParent(listParent &L, NodeParent Pre) {
    if (Pre != NULL && Pre->next != NULL) {
        NodeParent Del = Pre->next;
        
        // Hapus semua child dulu agar tidak memori leak
        deleteListChild(Del->L_Child);

        Pre->next = Del->next;
        if (Del->next != NULL) {
            Del->next->prev = Pre;
        } else {
            L.last = Pre;
        }
        delete Del;
    }
}

void printMLLStructure(listParent L) {
    NodeParent P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "Parent " << i << endl;
        cout << "ID Golongan: " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan: " << P->isidata.namaGolongan << endl;

        if (isEmptyChild(P->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << " - Child " << j << ":" << endl;
                cout << "   ID Hewan: " << C->isidata.idHewan << endl;
                cout << "   Nama Hewan: " << C->isidata.namaHewan << endl;
                cout << "   Habitat: " << C->isidata.habitat << endl;
                cout << "   Ekor: " << C->isidata.ekor << endl;
                cout << "   Bobot: " << C->isidata.bobot << endl;
                C = C->next;
                j++;
            }
        }
        cout << endl;
        P = P->next;
        i++;
    }
}

// --- IMPLEMENTASI NOMOR 2 (SEARCHING) ---
void searchHewanByEkor(listParent L, bool tail) {
    NodeParent P = L.first;
    int idxParent = 1;

    while (P != NULL) {
        if (!isEmptyChild(P->L_Child)) {
            NodeChild C = P->L_Child.first;
            int idxChild = 1;
            
            while (C != NULL) {
                // Cek kondisi ekor (False/0 sesuai soal)
                if (C->isidata.ekor == tail) {
                    cout << "Data ditemukan pada list anak dari node parent " 
                         << P->isidata.namaGolongan << " pada posisi ke-" << idxChild << "!" << endl;
                    
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << C->isidata.idHewan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << idxChild << endl;
                    cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                    cout << "Habitat : " << C->isidata.habitat << endl;
                    cout << "Ekor : " << C->isidata.ekor << endl;
                    cout << "Bobot : " << C->isidata.bobot << endl;
                    
                    cout << "------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << P->isidata.idGolongan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << idxParent << endl;
                    cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
                    cout << "------------------------" << endl << endl;
                }
                C = C->next;
                idxChild++;
            }
        }
        P = P->next;
        idxParent++;
    }
}
```

main.cpp
```C++
#include "MultiLL.h" // Include header 

// Variabel global untuk List Utama agar bisa diakses di berbagai step
listParent LP;

int main() {
    // --- BAGIAN NOMOR 1: CREATE & INSERT ---
    createListParent(LP);

    NodeParent P;
    NodeChild C;

    // 1. Insert Parent G001 (Aves)
    P = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P);
        // Child G001
        C = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
        insertLastChild(P->L_Child, C);
        C = allocNodeChild("AV002", "Bebek", "Air", true, 2.0);
        insertLastChild(P->L_Child, C);

    // 2. Insert Parent G002 (Mamalia)
    P = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P);
        // Child G002
        C = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
        insertLastChild(P->L_Child, C);
        C = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
        insertLastChild(P->L_Child, C);
        C = allocNodeChild("M002", "Kucing", "Darat", true, 4);
        insertLastChild(P->L_Child, C);

    // 3. Insert Parent G003 (Pisces)
    P = allocNodeParent("G003", "Pisces");
    insertLastParent(LP, P);
        // No Child

    // 4. Insert Parent G004 (Amfibi)
    P = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P);
        // Child G004
        C = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
        insertLastChild(P->L_Child, C);

    // 5. Insert Parent G005 (Reptil)
    P = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P);
        // No Child

    // PRINT HASIL NOMOR 1
    cout << "=== OUTPUT NOMOR 1 (STRUCTURE) ===" << endl;
    printMLLStructure(LP);
    cout << "==================================" << endl << endl;

    // --- BAGIAN NOMOR 2: SEARCHING ---
    cout << "=== OUTPUT NOMOR 2 (SEARCHING EKOR = FALSE) ===" << endl;
    // Cari hewan yang TIDAK punya ekor (False/0)
    searchHewanByEkor(LP, false); 
    cout << "===============================================" << endl << endl;

    return 0;
}
```

### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week13_modul13/output-unguided2-modul13.png)

Program ini merupakan implementasi struktur data Multi Linked List (MLL) menggunakan bahasa C++ untuk memodelkan hierarki klasifikasi hewan. Struktur ini terdiri dari dua level Double Linked List: level Parent yang menyimpan kategori golongan hewan (seperti Aves, Mamalia, Pisces) dan level Child yang menyimpan data spesifik hewan (seperti Harimau, Gorila) yang terhubung langsung ke node Parent masing-masing. Setiap node Parent memiliki pointer khusus yang menunjuk ke list Child miliknya, memungkinkan pengelompokan data yang terstruktur.

Secara fungsional, program memisahkan deklarasi tipe data abstrak (ADT) pada file header (MultiLL.h) dan logika operasional pada file implementasi (MultiLL.cpp). Fitur-fitur utama mencakup alokasi memori, penyisipan data (insert) secara bertingkat, pencarian data (searching) berdasarkan atribut ekor, serta penghapusan data (delete) yang aman, di mana penghapusan node Parent akan secara otomatis membersihkan seluruh node Child di bawahnya untuk mencegah kebocoran memori. Pada eksekusi utama (main.cpp), program mendemonstrasikan penyusunan data hierarkis tersebut, menampilkan strukturnya ke layar, dan melakukan pencarian hewan yang tidak memiliki ekor.

### 3. Soal Unguided 3 
![Screenshot Soal Unguided 3_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week13_modul13/SoalUnguided3-Bagian1-Modul13.png)
![Screenshot Soal Unguided 3_2](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week13_modul13/SoalUnguided3-Bagian2-Modul13.png)
![Screenshot Soal Unguided 3_3](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week13_modul13/SoalUnguided3-Bagian3-Modul13.png)

MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

// Definisi Struktur Data
struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor; // 1 (True) jika berekor, 0 (False) jika tidak
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child; // List child berada di dalam node parent
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

// --- Prototypes ---

// Cek Kosong
bool isEmptyParent(listParent L);
bool isEmptyChild(listChild L);

// Create List
void createListParent(listParent &L);
void createListChild(listChild &L);

// Alokasi Node
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

// Dealokasi
void deallocNodeParent(NodeParent p); // Menghapus node parent
void deallocNodeChild(NodeChild c);   // Menghapus node child

// Operasi Parent (Double Linked List)
void insertFirstParent(listParent &L, NodeParent P);
void insertLastParent(listParent &L, NodeParent P);
void deleteFirstParent(listParent &L);
void deleteAfterParent(listParent &L, NodeParent Pre); // Dibutuhkan untuk menghapus G004 (setelah G003)
void deleteListChild(listChild &L); // Helper untuk membersihkan child sebelum parent dihapus

// Operasi Child (Double Linked List)
void insertFirstChild(listChild &L, NodeChild C);
void insertLastChild(listChild &L, NodeChild C);
void deleteFirstChild(listChild &L);
void deleteAfterChild(listChild &L, NodeChild Pre);

// Print
void printMLLStructure(listParent L);

// SEARCHING (Untuk Nomor 2)
void searchHewanByEkor(listParent L, bool tail);

#endif
```

MultiLL.cpp
```C++
#include "MultiLL.h"

// --- IMPLEMENTASI DASAR (NOMOR 1) ---

bool isEmptyParent(listParent L) {
    return L.first == NULL;
}

bool isEmptyChild(listChild L) {
    return L.first == NULL;
}

void createListParent(listParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L) {
    L.first = NULL;
    L.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child); // Penting: inisialisasi list child
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void insertLastParent(listParent &L, NodeParent P) {
    if (isEmptyParent(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertLastChild(listChild &L, NodeChild C) {
    if (isEmptyChild(L)) {
        L.first = C;
        L.last = C;
    } else {
        C->prev = L.last;
        L.last->next = C;
        L.last = C;
    }
}

void deleteFirstChild(listChild &L) {
    if (!isEmptyChild(L)) {
        NodeChild P = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
            P->next = NULL;
        }
        delete P;
    }
}

void deleteListChild(listChild &L) {
    while (!isEmptyChild(L)) {
        deleteFirstChild(L);
    }
}

void deleteAfterParent(listParent &L, NodeParent Pre) {
    if (Pre != NULL && Pre->next != NULL) {
        NodeParent Del = Pre->next;
        
        // Hapus semua child dulu agar tidak memori leak
        deleteListChild(Del->L_Child);

        Pre->next = Del->next;
        if (Del->next != NULL) {
            Del->next->prev = Pre;
        } else {
            L.last = Pre;
        }
        delete Del;
    }
}

void printMLLStructure(listParent L) {
    NodeParent P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "Parent " << i << endl;
        cout << "ID Golongan: " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan: " << P->isidata.namaGolongan << endl;

        if (isEmptyChild(P->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << " - Child " << j << ":" << endl;
                cout << "   ID Hewan: " << C->isidata.idHewan << endl;
                cout << "   Nama Hewan: " << C->isidata.namaHewan << endl;
                cout << "   Habitat: " << C->isidata.habitat << endl;
                cout << "   Ekor: " << C->isidata.ekor << endl;
                cout << "   Bobot: " << C->isidata.bobot << endl;
                C = C->next;
                j++;
            }
        }
        cout << endl;
        P = P->next;
        i++;
    }
}

// --- IMPLEMENTASI NOMOR 2 (SEARCHING) ---
void searchHewanByEkor(listParent L, bool tail) {
    NodeParent P = L.first;
    int idxParent = 1;

    while (P != NULL) {
        if (!isEmptyChild(P->L_Child)) {
            NodeChild C = P->L_Child.first;
            int idxChild = 1;
            
            while (C != NULL) {
                // Cek kondisi ekor (False/0 sesuai soal)
                if (C->isidata.ekor == tail) {
                    cout << "Data ditemukan pada list anak dari node parent " 
                         << P->isidata.namaGolongan << " pada posisi ke-" << idxChild << "!" << endl;
                    
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << C->isidata.idHewan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << idxChild << endl;
                    cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                    cout << "Habitat : " << C->isidata.habitat << endl;
                    cout << "Ekor : " << C->isidata.ekor << endl;
                    cout << "Bobot : " << C->isidata.bobot << endl;
                    
                    cout << "------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << P->isidata.idGolongan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << idxParent << endl;
                    cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
                    cout << "------------------------" << endl << endl;
                }
                C = C->next;
                idxChild++;
            }
        }
        P = P->next;
        idxParent++;
    }
}
```

main.cpp
```C++
#include "MultiLL.h" // Include header 

// Variabel global untuk List Utama agar bisa diakses di berbagai step
listParent LP;

int main() {
    // --- BAGIAN NOMOR 1: CREATE & INSERT ---
    createListParent(LP);

    NodeParent P;
    NodeChild C;

    // 1. Insert Parent G001 (Aves)
    P = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P);
        // Child G001
        C = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
        insertLastChild(P->L_Child, C);
        C = allocNodeChild("AV002", "Bebek", "Air", true, 2.0);
        insertLastChild(P->L_Child, C);

    // 2. Insert Parent G002 (Mamalia)
    P = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P);
        // Child G002
        C = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
        insertLastChild(P->L_Child, C);
        C = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
        insertLastChild(P->L_Child, C);
        C = allocNodeChild("M002", "Kucing", "Darat", true, 4);
        insertLastChild(P->L_Child, C);

    // 3. Insert Parent G003 (Pisces)
    P = allocNodeParent("G003", "Pisces");
    insertLastParent(LP, P);
        // No Child

    // 4. Insert Parent G004 (Amfibi)
    P = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P);
        // Child G004
        C = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
        insertLastChild(P->L_Child, C);

    // 5. Insert Parent G005 (Reptil)
    P = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P);
        // No Child

    // PRINT HASIL NOMOR 1
    cout << "=== OUTPUT NOMOR 1 (STRUCTURE) ===" << endl;
    printMLLStructure(LP);
    cout << "==================================" << endl << endl;

    // --- BAGIAN NOMOR 2: SEARCHING ---
    cout << "=== OUTPUT NOMOR 2 (SEARCHING EKOR = FALSE) ===" << endl;
    // Cari hewan yang TIDAK punya ekor (False/0)
    searchHewanByEkor(LP, false); 
    cout << "===============================================" << endl << endl;

    // --- BAGIAN NOMOR 3: DELETE G004 ---
    cout << "=== OUTPUT NOMOR 3 (DELETE G004 & PRINT) ===" << endl;
    
    // Logika menghapus G004 (Amfibi)
    // Kita cari dulu node G003 (Pisces) sebagai 'predecessor'
    NodeParent P_Search = LP.first;
    NodeParent Pre_Node = NULL;
    
    while(P_Search != NULL){
        if(P_Search->isidata.idGolongan == "G003"){
            Pre_Node = P_Search;
            break;
        }
        P_Search = P_Search->next;
    }

    // Lakukan penghapusan jika G003 ditemukan
    if (Pre_Node != NULL) {
        deleteAfterParent(LP, Pre_Node); // Ini akan menghapus G004 beserta childnya
    }

    // Print hasil setelah penghapusan
    printMLLStructure(LP);
    cout << "============================================" << endl;
    
    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week13_modul13/output1-unguided3-modul13.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week13_modul13/output2-unguided3-modul13.png)

Program ini mengimplementasikan struktur data Multi Linked List (MLL) menggunakan bahasa C++ untuk memodelkan hierarki klasifikasi hewan. Struktur ini terdiri dari dua level Double Linked List: level Parent yang menyimpan kategori golongan hewan (seperti Aves, Mamalia, Pisces) dan level Child yang menyimpan data spesifik hewan (seperti Harimau, Gorila) yang bersarang di dalam node Parent masing-masing. Kode program terbagi secara modular menjadi file header (MultiLL.h) untuk definisi ADT dan file implementasi (MultiLL.cpp) yang menangani logika operasi dasar seperti alokasi memori, penyisipan data (insert), dan pencarian (search).

Fitur utama dalam program ini mencakup manajemen memori yang aman, khususnya pada operasi penghapusan (delete). Prosedur deleteAfterParent dirancang untuk secara otomatis menghapus seluruh node Child yang terkait (deleteListChild) sebelum menghapus node Parent-nya, guna mencegah kebocoran memori (memory leak). Pada eksekusi utama (main.cpp), program mensimulasikan skenario lengkap: dimulai dengan pembentukan struktur hierarki data awal, dilanjutkan dengan pencarian hewan yang tidak memiliki ekor, dan diakhiri dengan penghapusan node Parent "Amfibi" (G004) beserta seluruh hewan di dalamnya, di mana setiap perubahan struktur ditampilkan ke layar. 

## Kesimpulan
Multi Linked List (MLL) merupakan pengembangan struktur data dinamis yang dirancang untuk mengatasi keterbatasan Single Linked List dalam merepresentasikan hubungan data yang kompleks, khususnya relasi One-to-Many atau Many-to-Many. Melalui mekanisme penggunaan pointer ganda pada node, MLL mampu membentuk hierarki Parent-Child yang lebih efisien dalam penggunaan memori dibandingkan array multidimensi karena tidak memerlukan alokasi ruang statis untuk slot kosong. Meskipun menawarkan fleksibilitas yang tinggi dalam penyisipan dan penghapusan data, implementasi MLL dalam bahasa C++ memiliki tingkat kompleksitas yang lebih tinggi, terutama pada operasi traversal yang membutuhkan perulangan bersarang serta manajemen memori yang ketat untuk mencegah terjadinya kesalahan seperti memory leak atau dangling pointer. 

## Referensi
[1] Malik, D. S. (2010). Data Structures Using C++ (2nd ed.). Cengage Learning. 
<br>
[2] Sjukani, M. (2012). Struktur Data (Algoritma & Struktur Data 2) dengan C, C++. Mitra Wacana Media. 
<br>
[3] Karumanchi, N. (2017). Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles. CareerMonk Publications. 