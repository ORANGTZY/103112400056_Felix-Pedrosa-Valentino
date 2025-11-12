# <h1 align="center">Laporan Praktikum Modul 7 - Stack </h1>
<p align="center">Felix Pedrosa Valentino - 103112400056</p>

## Dasar Teori
Stack merupakan salah satu bentuk struktur data linear yang fundamental dalam ilmu komputer. Struktur data ini bekerja berdasarkan prinsip LIFO (Last-In, First-Out) [1]. Prinsip LIFO berarti bahwa elemen data yang terakhir kali dimasukkan (disisipkan) ke dalam tumpukan akan menjadi elemen data yang pertama kali dikeluarkan (diambil) [2]. Analogi yang sering digunakan untuk menggambarkan stack adalah tumpukan piring; piring baru diletakkan di atas (paling akhir masuk), dan ketika mengambil piring, piring yang diambil adalah yang paling atas (yang terakhir diletakkan) [3]. Stack bersifat terbatas, di mana operasi penyisipan (insertion) dan penghapusan (deletion) hanya dapat dilakukan pada satu ujung yang sama, yang disebut sebagai Top (puncak) dari stack [1]. 

Terdapat beberapa operasi dasar yang didefinisikan pada stack. Operasi yang paling utama adalah push dan pop. Operasi push digunakan untuk menambahkan atau menyisipkan satu elemen baru ke posisi paling atas (top) dari stack [2]. Jika stack diimplementasikan dengan array dan sudah penuh, operasi push akan menyebabkan kondisi yang disebut overflow (penuh) [3]. Sebaliknya, operasi pop digunakan untuk menghapus atau mengambil elemen yang berada di posisi paling atas (top) stack. Jika operasi pop dilakukan pada stack yang sudah kosong, akan terjadi kondisi underflow (kosong) [1].

Selain dua operasi utama tersebut, terdapat operasi-operasi pendukung yang penting. Operasi peek (atau sering disebut top) berfungsi untuk melihat atau mengakses nilai elemen di posisi top tanpa menghapusnya dari stack [3]. Terdapat pula fungsi boolean isEmpty yang digunakan untuk memeriksa apakah stack sedang dalam keadaan kosong (tidak memiliki elemen) dan isFull untuk memeriksa apakah stack telah penuh (khususnya relevan jika diimplementasikan menggunakan array dengan ukuran terbatas) [2]. 

Dalam implementasinya menggunakan bahasa C++, stack dapat dibangun dengan dua cara utama: menggunakan array (implementasi statis) atau menggunakan linked list (implementasi dinamis) [1]. Implementasi menggunakan array (baik array statis maupun dynamic array) memerlukan sebuah variabel integer (sering disebut top) untuk melacak indeks dari elemen teratas. Implementasi ini cenderung lebih cepat karena akses memori yang berdekatan, namun memiliki keterbatasan ukuran yang harus ditentukan di awal (statis) atau memerlukan realokasi memori jika menggunakan dynamic array [3].

Implementasi menggunakan linked list (khususnya singly linked list) lebih fleksibel karena ukuran stack dapat bertambah atau berkurang secara dinamis sesuai kebutuhan memori saat runtime [1]. Dalam implementasi ini, operasi push setara dengan menambah node baru di awal (insert head), dan operasi pop setara dengan menghapus node di awal (delete head). Pointer top akan selalu menunjuk ke node terdepan dari linked list [2]. Selain implementasi manual, C++ juga menyediakan container adapter <stack> dalam Standard Template Library (STL). Adapter ini membungkus fungsionalitas stack di atas struktur data sekuensial lain seperti vector atau deque (yang merupakan default-nya), sehingga menyederhanakan penggunaan stack tanpa perlu mengelola implementasi dasarnya secara manual [2]. 

## Guided 

### 1. Guided 1 

stack.h 
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std; 

typedef struct node *address; 

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

stack.cpp 
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

main.cpp 
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

Program ini merupakan implementasi struktur data stack menggunakan linked list dalam bahasa C++. Stack didefinisikan dengan struct yang memiliki pointer top untuk menunjukkan elemen teratas, sementara setiap elemen adalah node yang menyimpan data integer (dataAngka) dan pointer next ke elemen berikutnya. Fungsi-fungsi utama meliputi isEmpty untuk memeriksa apakah stack kosong, createStack untuk inisialisasi stack, alokasi untuk membuat node baru, dealokasi untuk menghapus node, push untuk menambahkan elemen ke puncak stack, pop untuk menghapus elemen dari puncak, update untuk mengubah nilai elemen pada posisi tertentu, view untuk menampilkan semua elemen dari puncak ke dasar, dan searchData untuk mencari elemen berdasarkan nilai. Dalam program utama, stack dibuat dan diisi dengan lima elemen (1 hingga 5) melalui push, kemudian ditampilkan. Selanjutnya, dua elemen dihapus dengan pop, diikuti pembaruan nilai pada posisi 2 dan 1 (posisi 4 gagal karena tidak valid), dan akhirnya pencarian data 4 (ditemukan) serta 9 (tidak ditemukan), menunjukkan operasi dasar stack seperti LIFO (Last In, First Out).

### 2. Guided 2 

stack.h 
```C++
#ifndef STACK_H 
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; // Array untuk menyimpan elemen stack
    int top;
}; 

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X); // Prosedur untuk menambah elemen baru ke dalam stack 
infotype pop(Stack &S); // Prosedur untuk menghapus elemen teratas dari stack 
void printInfo(Stack S); 
void balikStack(Stack &S); // Prosedur untuk membalik urutan elemen dalam stack

#endif
```

stack.cpp 
```C++
#include "stack.h"
using namespace std; 

// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```

main.cpp 
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```

Program ini merupakan implementasi struktur data stack menggunakan array dalam bahasa pemrograman C++, dengan kapasitas maksimal 20 elemen. Stack didefinisikan sebagai struct yang berisi array info untuk menyimpan data integer dan variabel top untuk menunjukkan indeks elemen teratas. Fungsi-fungsi utama meliputi CreateStack untuk inisialisasi stack kosong, isEmpty dan isFull untuk memeriksa kondisi stack, push untuk menambahkan elemen ke puncak stack (dengan pengecekan kapasitas), pop untuk menghapus dan mengembalikan elemen teratas, printInfo untuk menampilkan isi stack dari puncak ke dasar, serta balikStack untuk membalik urutan elemen dengan menggunakan dua stack temporary sebagai bantuan. Dalam program utama, stack dibuat dan dioperasikan melalui serangkaian push (menambahkan 3, 4, 8, 2, 3, 9) dan pop (menghapus beberapa elemen), kemudian ditampilkan sebelum dan sesudah proses pembalikan urutan elemen, menunjukkan prinsip LIFO (Last In, First Out) dan manipulasi stack secara efisien.

## Unguided 

### 1. Soal Unguided 1 
(https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week9_modul7/SoalUnguided1-Modul7.png)

stack.h
```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
``` 

stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = 0;
    if (S.top >= 0) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack kosong!" << endl;
    }
    return x;
}

void printInfo(Stack S) {
    if (S.top >= 0) {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Stack kosong!" << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    
    while (S.top >= 0) {
        push(temp, pop(S));
    }
    
    S = temp;
}
``` 

main.cpp 
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    
    Stack S;
    createStack(S);
    
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    
    return 0;
}
``` 

### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week9_modul7/output-unguided1-modul7.png)

Program ini merupakan implementasi sederhana struktur data stack dalam bahasa C++ menggunakan array statis dengan kapasitas maksimal 20 elemen. Header file stack.h mendefinisikan struktur Stack yang terdiri dari array info untuk menyimpan data bertipe integer dan variabel top untuk menunjukkan indeks elemen teratas, serta mendeklarasikan fungsi-fungsi dasar seperti createStack untuk inisialisasi, push untuk menambahkan elemen (dengan pengecekan overflow), pop untuk menghapus dan mengembalikan elemen teratas (dengan pengecekan underflow), printInfo untuk mencetak isi stack dari atas ke bawah, dan balikStack untuk membalik urutan elemen menggunakan stack sementara. Implementasi di stack.cpp menangani logika operasi tersebut dengan pesan error untuk kondisi penuh atau kosong. File main.cpp mendemonstrasikan penggunaan stack melalui serangkaian operasi push dan pop, diikuti dengan pencetakan isi stack sebelum dan sesudah pembalikan, menunjukkan fungsi stack sebagai struktur LIFO (Last In, First Out).

### 2. Soal Unguided 2 
(https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week9_modul7/SoalUnguided2-Modul7.png)

stack.h
```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif
``` 

stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = 0;
    if (S.top >= 0) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack kosong!" << endl;
    }
    return x;
}

void printInfo(Stack S) {
    if (S.top >= 0) {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Stack kosong!" << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    
    while (S.top >= 0) {
        push(temp, pop(S));
    }
    
    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);
    
    // Pop semua elemen yang lebih besar dari x ke stack temporary
    while (S.top >= 0 && S.info[S.top] > x) {
        push(temp, pop(S));
    }
    
    // Push elemen x ke posisi yang tepat
    push(S, x);
    
    // Kembalikan elemen-elemen dari temp ke S
    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}
``` 

main.cpp 
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    
    Stack S;
    createStack(S);
    
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    
    return 0;
}
``` 

### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week9_modul7/output-unguided2-modul7.png) 

Program ini merupakan implementasi struktur data stack dalam bahasa C++ menggunakan array statis dengan kapasitas maksimal 20 elemen, yang dirancang untuk mempertahankan urutan elemen secara ascending (menaik). Header file stack.h mendefinisikan struktur Stack dengan array info untuk data integer dan variabel top, serta mendeklarasikan fungsi seperti createStack untuk inisialisasi, push untuk menambahkan elemen (dengan pengecekan overflow), pop untuk menghapus elemen teratas (dengan pengecekan underflow), printInfo untuk mencetak isi stack dari atas ke bawah, balikStack untuk membalik urutan elemen menggunakan stack sementara, dan pushAscending yang secara cerdas memasukkan elemen baru ke posisi yang tepat agar stack tetap terurut naik dengan memindahkan elemen yang lebih besar ke stack temporary sementara. Implementasi di stack.cpp menangani logika operasi tersebut dengan pesan error untuk kondisi penuh atau kosong. File main.cpp mendemonstrasikan penggunaan stack melalui serangkaian operasi pushAscending untuk memasukkan elemen secara terurut, diikuti dengan pencetakan isi stack sebelum dan sesudah pembalikan menggunakan balikStack, menunjukkan bagaimana stack mempertahankan sifat LIFO sambil memungkinkan penyisipan terurut. 

### 3. Soal Unguided 3 
(https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week9_modul7/SoalUnguided3-Modul7.png)

stack.h
```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
``` 

stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = 0;
    if (S.top >= 0) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack kosong!" << endl;
    }
    return x;
}

void printInfo(Stack S) {
    if (S.top >= 0) {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Stack kosong!" << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    
    while (S.top >= 0) {
        push(temp, pop(S));
    }
    
    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);
    
    // Pop semua elemen yang lebih besar dari x ke stack temporary
    while (S.top >= 0 && S.info[S.top] > x) {
        push(temp, pop(S));
    }
    
    // Push elemen x ke posisi yang tepat
    push(S, x);
    
    // Kembalikan elemen-elemen dari temp ke S
    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    infotype input;
    cout << "Masukkan angka (tekan enter setelah setiap angka, ketik angka negatif untuk berhenti):" << endl;
    
    cin >> input;
    while (input >= 0) {
        push(S, input);
        cin >> input;
    }
}
``` 

main.cpp 
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    
    Stack S;
    createStack(S);
    
    getInputStream(S);
    printInfo(S);
    
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    
    return 0;
}
``` 

### Output Unguided 3 :

![Screenshot Output Unguided 3_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week9_modul7/output-unguided3-modul7.png)

Program ini merupakan implementasi struktur data stack dalam bahasa C++ menggunakan array statis dengan kapasitas maksimal 20 elemen, yang mendukung operasi dasar dan penyisipan terurut. Header file stack.h mendefinisikan struktur Stack dengan array info untuk data integer dan variabel top, serta mendeklarasikan fungsi seperti createStack untuk inisialisasi, push untuk menambahkan elemen (dengan pengecekan overflow), pop untuk menghapus elemen teratas (dengan pengecekan underflow), printInfo untuk mencetak isi stack dari atas ke bawah, balikStack untuk membalik urutan elemen menggunakan stack sementara, pushAscending yang memasukkan elemen baru ke posisi tepat agar stack tetap terurut naik, dan getInputStream untuk membaca input angka dari pengguna secara interaktif hingga angka negatif dimasukkan. Implementasi di stack.cpp menangani logika operasi tersebut dengan pesan error untuk kondisi penuh atau kosong. File main.cpp mendemonstrasikan penggunaan stack dengan memanggil getInputStream untuk mengisi stack berdasarkan input pengguna, mencetak isi stack, membalik urutannya menggunakan balikStack, dan mencetak hasil akhir, menunjukkan sifat LIFO stack dengan kemampuan input dinamis dan penyisipan terurut. 

## Kesimpulan
Stack adalah struktur data linear fundamental yang beroperasi secara ketat berdasarkan prinsip LIFO (Last-In, First-Out), di mana elemen terakhir yang dimasukkan akan menjadi elemen pertama yang dikeluarkan. Seluruh operasi, baik penyisipan (insertion) maupun penghapusan (deletion), hanya dapat dilakukan pada satu ujung yang dikenal sebagai Top. Operasi dasar pada stack meliputi push untuk menambahkan elemen ke Top (yang dapat menyebabkan overflow jika penuh) dan pop untuk menghapus elemen dari Top (yang dapat menyebabkan underflow jika kosong). Selain itu, terdapat operasi pendukung seperti peek (untuk melihat elemen Top tanpa menghapus), isEmpty (untuk memeriksa kondisi kosong), dan isFull (untuk memeriksa kondisi penuh, relevan pada implementasi array). Dalam implementasinya di C++, stack dapat dibangun menggunakan array (statis) yang cepat namun terbatas ukurannya, atau menggunakan linked list (dinamis) yang lebih fleksibel. Bahasa C++ juga menyediakan container adapter <stack> dalam Standard Template Library (STL) untuk mempermudah penggunaan fungsionalitas tumpukan.

## Referensi
[1] Malik, D. S. (2018). Data Structures Using C++ (3rd ed.). Cengage Learning. 
<br>
[2] Deitel, P., & Deitel, H. (2017). C++ How to Program (10th ed.). Pearson Education. 
<br> 
[3] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). Introduction to Algorithms (4th ed.). MIT Press. 