# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Felix Pedrosa Valentino - 103112400056</p>

## Dasar Teori
Graph adalah salah satu struktur data non-linear yang fundamental dalam ilmu komputer, yang digunakan untuk merepresentasikan hubungan antar objek. Secara matematis, sebuah graph didefinisikan sebagai pasangan himpunan G = (V, E), di mana V adalah himpunan simpul (vertices atau nodes) yang tidak kosong, dan E adalah himpunan sisi (edges) yang menghubungkan pasangan simpul tersebut [1]. Struktur ini sangat fleksibel dan dapat digunakan untuk memodelkan berbagai persoalan dunia nyata, seperti jaringan komputer, peta rute transportasi, hingga hubungan sosial antar pengguna media sosial [2]. Berbeda dengan struktur data pohon (tree) yang bersifat hierarkis, graph memungkinkan adanya siklus (cycle) dan hubungan yang lebih kompleks antar elemennya. 

Berdasarkan arah sisinya, graph dapat dikategorikan menjadi dua jenis utama, yaitu Directed Graph (Digraph) dan Undirected Graph. Pada Undirected Graph, sisi yang menghubungkan dua simpul tidak memiliki arah, artinya hubungan berlaku dua arah secara otomatis (misalnya, jika A terhubung ke B, maka B juga terhubung ke A). Sebaliknya, pada Directed Graph, sisi memiliki arah tertentu, yang digambarkan dengan anak panah dari simpul asal ke simpul tujuan [3]. Selain itu, graph juga dapat memiliki bobot (weight) pada setiap sisinya, yang disebut sebagai Weighted Graph. Bobot ini biasanya merepresentasikan biaya, jarak, atau waktu tempuh antar dua simpul, yang sangat krusial dalam algoritma pencarian jalur terpendek seperti Dijkstra atau Bellman-Ford [1]. 

Dalam pemrograman C++, terdapat dua metode umum untuk merepresentasikan graph di dalam memori komputer, yaitu menggunakan Adjacency Matrix dan Adjacency List. Adjacency Matrix menggunakan array dua dimensi (2D) berukuran V x V, di mana baris dan kolom merepresentasikan simpul, dan nilai dalam sel menunjukkan adanya hubungan sisi (nilai 1 jika ada, 0 jika tidak). Metode ini memungkinkan pengecekan hubungan antar simpul dilakukan dalam waktu konstan O(1), namun memakan memori yang besar (O(V^2)), sehingga kurang efisien untuk sparse graph (graph dengan sedikit sisi) [4].

Sebaliknya, Adjacency List lebih sering digunakan dalam implementasi C++ modern karena efisiensi memorinya. Metode ini merepresentasikan graph sebagai array dari linked list atau menggunakan std::vector dari Standard Template Library (STL) C++. Setiap elemen array mewakili sebuah simpul, dan list yang terkait dengannya berisi daftar simpul tetangga yang terhubung langsung [3]. Pendekatan ini lebih hemat memori, terutama untuk graph yang jarang, dengan kompleksitas ruang O(V + E). Untuk menelusuri atau mengunjungi setiap simpul dalam graph, terdapat dua algoritma traversal utama: Breadth-First Search (BFS) yang menggunakan struktur data Queue untuk menelusuri secara melebar, dan Depth-First Search (DFS) yang menggunakan struktur data Stack (atau rekursi) untuk menelusuri secara mendalam [5].

## Guided 

### 1. Guided 1

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

// Prototypes
void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif
```

graph_edge.cpp
```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);
    
    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge; // Insert First di list Edge
        pStart->firstEdge = newEdge;
    }
}
```

graph_init.cpp
```C++
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode (infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
```

graph_print.cpp
```C++
#include "graph.h"

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
```

main.cpp
```C++
#include "graph.h"
#include <iostream>
using namespace std;

int main(){
    Graph G;
    createGraph(G);

    // Menambahkan Node
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // Menghubungkan Node
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```

Program ini merupakan implementasi struktur data Graph Berarah (Directed Graph) menggunakan bahasa C++ dengan metode representasi Adjacency List. Struktur kode disusun secara modular dalam beberapa file terpisah untuk membedakan fungsi deklarasi (graph.h), inisialisasi simpul (graph_init.cpp), pengelolaan sisi atau hubungan antar simpul (graph_edge.cpp), dan pencetakan hasil (graph_print.cpp). Dalam implementasi ini, setiap simpul (Node) disimpan dalam sebuah linked list utama, di mana setiap simpul tersebut memiliki linked list sekunder (Edge) yang menyimpan pointer ke simpul-simpul tetangganya, memungkinkan penggunaan memori yang dinamis dan efisien.

Secara fungsional, program menyediakan operasi dasar untuk memanipulasi graph. Fungsi insertNode digunakan untuk menambahkan simpul baru yang berisi data karakter (seperti 'A', 'B') ke dalam graph. Fungsi connectNode bertugas menciptakan hubungan antar simpul dengan cara mencari alamat simpul asal dan tujuan, lalu menambahkan edge baru pada simpul asal. Terakhir, fungsi printGraph bekerja dengan menelusuri seluruh simpul yang ada dan menampilkan daftar tetangga yang terhubung dengan simpul tersebut ke layar konsol.

Pada eksekusi utama di main.cpp, program mendemonstrasikan pembuatan sebuah graph sederhana yang terdiri dari empat simpul: 'A', 'B', 'C', dan 'D'. Program kemudian membentuk jalur koneksi spesifik (A ke B, A ke C, B ke D, dan C ke D) dan mencetak struktur graph tersebut. Hasil akhirnya menampilkan daftar keterhubungan yang menunjukkan node mana saja yang dapat dijangkau dari node lainnya sesuai dengan sisi yang telah dibuat.

## Unguided 

### 1. Soal Unguided 1 
![Screenshot Soal Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week14_modul14/SoalUnguided1-Modul14.png)

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

// Definisi Tipe Data sesuai Soal
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited; // 0: belum, 1: sudah
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node; // Pointer ke node tujuan
    adrEdge next;
};

struct Graph {
    adrNode first;
};

// Prototype Prosedur & Fungsi Soal No 1
void createGraph(Graph &G);
void insertNode(Graph &G, infoGraph X);
void connectNode(adrNode N1, adrNode N2);
void printInfoGraph(Graph G);

// Helper function untuk memudahkan main.cpp mencari alamat node berdasarkan karakter
adrNode findNode(Graph G, infoGraph X);

#endif
```

graph.cpp
```C++
#include "graph.h"

// --- Jawaban Nomor 1: Implementasi ADT Dasar ---

void createGraph(Graph &G) {
    G.first = NULL;
}

// Fungsi bantuan alokasi node baru
adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

// Fungsi bantuan alokasi edge baru
adrEdge allocateEdge(adrNode destination) {
    adrEdge E = new ElmEdge;
    E->node = destination;
    E->next = NULL;
    return E;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        // Insert Last agar urutan node rapi (A, B, C...)
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void connectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        // 1. Hubungkan N1 ke N2
        adrEdge E1 = allocateEdge(N2);
        E1->next = N1->firstEdge; // Insert First pada edge list N1
        N1->firstEdge = E1;

        // 2. Hubungkan N2 ke N1 (Karena Graph TIDAK BERARAH)
        adrEdge E2 = allocateEdge(N1);
        E2->next = N2->firstEdge; // Insert First pada edge list N2
        N2->firstEdge = E2;
    }
}

void printInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung dengan: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}
```

main.cpp
```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    // 1. Insert Node (A sampai H)
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    // 2. Buat Koneksi sesuai Gambar Ilustrasi (Graph Tidak Berarah)
    // A terhubung ke B dan C
    connectNode(findNode(G, 'A'), findNode(G, 'B'));
    connectNode(findNode(G, 'A'), findNode(G, 'C'));
    
    // B terhubung ke D dan E
    connectNode(findNode(G, 'B'), findNode(G, 'D'));
    connectNode(findNode(G, 'B'), findNode(G, 'E'));

    // C terhubung ke F dan G
    connectNode(findNode(G, 'C'), findNode(G, 'F'));
    connectNode(findNode(G, 'C'), findNode(G, 'G'));

    // D, E, F, G terhubung ke H
    connectNode(findNode(G, 'D'), findNode(G, 'H'));
    connectNode(findNode(G, 'E'), findNode(G, 'H'));
    connectNode(findNode(G, 'F'), findNode(G, 'H'));
    connectNode(findNode(G, 'G'), findNode(G, 'H'));

    // Tampilkan Info Graph
    cout << "=== Info Graph (Adjacency List) ===" << endl;
    printInfoGraph(G);
    cout << endl;

    return 0;
}
```

### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week14_modul14/output-unguided1-modul14.png)

Program ini merupakan implementasi struktur data Graph Tidak Berarah (Undirected Graph) menggunakan representasi Adjacency List dalam bahasa C++. Kode disusun secara modular yang terbagi menjadi file header (graph.h) untuk definisi tipe data dan prototipe fungsi, serta file implementasi (graph.cpp) yang memuat logika manipulasi graph. Struktur data disusun secara dinamis menggunakan linked list, di mana setiap elemen simpul (Node) memiliki pointer yang menunjuk ke daftar sisi (Edge) yang merepresentasikan hubungan ketetanggaan dengan simpul lain. Dalam struktur ini, setiap simpul juga dilengkapi dengan atribut visited yang berfungsi sebagai penanda status kunjungan untuk mencegah infinite loop saat melakukan penelusuran graph.

Secara fungsional, program menyediakan operasi modular untuk manipulasi graph. Fungsi insertNode digunakan untuk menambahkan simpul baru ke dalam graph, sementara fungsi connectNode bertugas menghubungkan dua simpul. Karena sifatnya yang tidak berarah (undirected), logika koneksi dirancang untuk secara otomatis membuat hubungan timbal balik (dua arah); saat simpul A dihubungkan ke B, program juga secara otomatis menghubungkan B ke A. Terdapat pula fungsi utilitas findNode untuk mencari alamat memori simpul berdasarkan label karakternya, serta printInfoGraph untuk memvisualisasikan seluruh struktur graph ke layar konsol.

Pada bagian eksekusi utama (main.cpp), program mendemonstrasikan pembentukan sebuah topologi graph yang kompleks melibatkan 8 simpul (A hingga H). Simpul-simpul tersebut dihubungkan mengikuti pola hierarkis yang menyatu kembali, dimulai dari simpul akar 'A', bercabang ke simpul perantara, dan akhirnya bertemu di simpul 'H'. Program kemudian mencetak daftar adjacency list dari setiap simpul, yang memverifikasi bahwa semua koneksi telah terbentuk dengan benar sesuai logika graph tidak berarah.

### 2. Soal Unguided 2 
Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur PrintDFS (Graph G, adrNode N);

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

// Definisi Tipe Data sesuai Soal
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited; // 0: belum, 1: sudah
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node; // Pointer ke node tujuan
    adrEdge next;
};

struct Graph {
    adrNode first;
};

// Prototype Prosedur & Fungsi Soal No 1
void createGraph(Graph &G);
void insertNode(Graph &G, infoGraph X);
void connectNode(adrNode N1, adrNode N2);
void printInfoGraph(Graph G);

// Helper function untuk memudahkan main.cpp mencari alamat node berdasarkan karakter
adrNode findNode(Graph G, infoGraph X);

// Prototype Soal No 2
void printDFS(Graph G, adrNode N);

#endif
```

graph.cpp
```C++
#include "graph.h"

// --- Jawaban Nomor 1: Implementasi ADT Dasar ---

void createGraph(Graph &G) {
    G.first = NULL;
}

// Fungsi bantuan alokasi node baru
adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

// Fungsi bantuan alokasi edge baru
adrEdge allocateEdge(adrNode destination) {
    adrEdge E = new ElmEdge;
    E->node = destination;
    E->next = NULL;
    return E;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        // Insert Last agar urutan node rapi (A, B, C...)
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void connectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        // 1. Hubungkan N1 ke N2
        adrEdge E1 = allocateEdge(N2);
        E1->next = N1->firstEdge; // Insert First pada edge list N1
        N1->firstEdge = E1;

        // 2. Hubungkan N2 ke N1 (Karena Graph TIDAK BERARAH)
        adrEdge E2 = allocateEdge(N1);
        E2->next = N2->firstEdge; // Insert First pada edge list N2
        N2->firstEdge = E2;
    }
}

void printInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung dengan: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

// --- Nomor 2: Prosedur PrintDFS ---

// Helper untuk rekursi DFS
void dfsHelper(adrNode N) {
    if (N == NULL) return;

    // Tandai sudah dikunjungi dan cetak
    N->visited = 1;
    cout << N->info << " ";

    // Kunjungi semua tetangga yang belum dikunjungi
    adrEdge E = N->firstEdge;
    while (E != NULL) {
        if (E->node->visited == 0) {
            dfsHelper(E->node);
        }
        E = E->next;
    }
}

void printDFS(Graph G, adrNode N) {
    // Reset status visited semua node menjadi 0 sebelum mulai
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }

    // Mulai penelusuran
    dfsHelper(N);
}
```

main.cpp
```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    // 1. Insert Node (A sampai H)
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    // 2. Buat Koneksi sesuai Gambar Ilustrasi (Graph Tidak Berarah)
    // A terhubung ke B dan C
    connectNode(findNode(G, 'A'), findNode(G, 'B'));
    connectNode(findNode(G, 'A'), findNode(G, 'C'));
    
    // B terhubung ke D dan E
    connectNode(findNode(G, 'B'), findNode(G, 'D'));
    connectNode(findNode(G, 'B'), findNode(G, 'E'));

    // C terhubung ke F dan G
    connectNode(findNode(G, 'C'), findNode(G, 'F'));
    connectNode(findNode(G, 'C'), findNode(G, 'G'));

    // D, E, F, G terhubung ke H
    connectNode(findNode(G, 'D'), findNode(G, 'H'));
    connectNode(findNode(G, 'E'), findNode(G, 'H'));
    connectNode(findNode(G, 'F'), findNode(G, 'H'));
    connectNode(findNode(G, 'G'), findNode(G, 'H'));

    // Tampilkan Info Graph
    cout << "=== Info Graph (Adjacency List) ===" << endl;
    printInfoGraph(G);
    cout << endl;

    // Panggil DFS
    cout << "=== Hasil Penelusuran DFS (Mulai dari A) ===" << endl;
    printDFS(G, findNode(G, 'A'));
    cout << endl << endl;

    return 0;
}
```

### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week14_modul14/output-unguided2-modul14.png)

Program ini merupakan implementasi struktur data Graph Tidak Berarah (Undirected Graph) menggunakan representasi Adjacency List dalam bahasa C++. Kode disusun secara modular yang terbagi menjadi file header (graph.h) untuk definisi tipe data dan prototipe fungsi, serta file implementasi (graph.cpp) yang memuat logika manipulasi graph. Struktur data disusun secara dinamis menggunakan linked list, di mana setiap elemen simpul (Node) memiliki pointer yang menunjuk ke daftar sisi (Edge) yang merepresentasikan hubungan ketetanggaan dengan simpul lain. Dalam struktur ini, setiap simpul juga dilengkapi dengan atribut visited yang berfungsi sebagai penanda status kunjungan untuk mencegah infinite loop saat melakukan penelusuran graph.

Secara fungsional, program menyediakan operasi modular untuk manipulasi graph. Fungsi insertNode digunakan untuk menambahkan simpul baru ke dalam graph, sementara fungsi connectNode bertugas menghubungkan dua simpul. Karena sifatnya yang tidak berarah (undirected), logika koneksi dirancang untuk secara otomatis membuat hubungan timbal balik (dua arah); saat simpul A dihubungkan ke B, program juga secara otomatis menghubungkan B ke A. Terdapat pula fungsi utilitas findNode untuk mencari alamat memori simpul berdasarkan label karakternya, serta printInfoGraph untuk memvisualisasikan seluruh struktur graph ke layar konsol.

Pada bagian eksekusi utama (main.cpp), program mendemonstrasikan pembentukan sebuah topologi graph yang kompleks melibatkan 8 simpul (A hingga H). Simpul-simpul tersebut dihubungkan mengikuti pola hierarkis yang menyatu kembali, dimulai dari simpul akar 'A', bercabang ke simpul perantara, dan akhirnya bertemu di simpul 'H'. Program kemudian mencetak keluaran pertama yaitu daftar adjacency list dari setiap simpul, yang memverifikasi bahwa semua koneksi telah terbentuk dengan benar sesuai logika graph tidak berarah setelah itu program mencetak keluaran kedua yaitu hasil urutan simpul yang dikunjungi oleh algoritma DFS yang dimulai dari simpul 'A'.

### 3. Soal Unguided 3 
Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur PrintBFS (Graph G, adrNode N);

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

// Definisi Tipe Data sesuai Soal
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited; // 0: belum, 1: sudah
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node; // Pointer ke node tujuan
    adrEdge next;
};

struct Graph {
    adrNode first;
};

// Prototype Prosedur & Fungsi Soal No 1
void createGraph(Graph &G);
void insertNode(Graph &G, infoGraph X);
void connectNode(adrNode N1, adrNode N2);
void printInfoGraph(Graph G);

// Helper function untuk memudahkan main.cpp mencari alamat node berdasarkan karakter
adrNode findNode(Graph G, infoGraph X);

// Prototype Soal No 2 & 3
void printDFS(Graph G, adrNode N);
void printBFS(Graph G, adrNode N);

#endif
```

graph.cpp
```C++
#include "graph.h"
#include <queue> // Wajib ditambahkan untuk fungsi BFS
// --- Jawaban Nomor 1: Implementasi ADT Dasar ---

void createGraph(Graph &G) {
    G.first = NULL;
}

// Fungsi bantuan alokasi node baru
adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

// Fungsi bantuan alokasi edge baru
adrEdge allocateEdge(adrNode destination) {
    adrEdge E = new ElmEdge;
    E->node = destination;
    E->next = NULL;
    return E;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        // Insert Last agar urutan node rapi (A, B, C...)
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void connectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        // 1. Hubungkan N1 ke N2
        adrEdge E1 = allocateEdge(N2);
        E1->next = N1->firstEdge; // Insert First pada edge list N1
        N1->firstEdge = E1;

        // 2. Hubungkan N2 ke N1 (Karena Graph TIDAK BERARAH)
        adrEdge E2 = allocateEdge(N1);
        E2->next = N2->firstEdge; // Insert First pada edge list N2
        N2->firstEdge = E2;
    }
}

void printInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung dengan: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

// --- Nomor 2: Prosedur PrintDFS ---

// Helper untuk rekursi DFS
void dfsHelper(adrNode N) {
    if (N == NULL) return;

    // Tandai sudah dikunjungi dan cetak
    N->visited = 1;
    cout << N->info << " ";

    // Kunjungi semua tetangga yang belum dikunjungi
    adrEdge E = N->firstEdge;
    while (E != NULL) {
        if (E->node->visited == 0) {
            dfsHelper(E->node);
        }
        E = E->next;
    }
}

void printDFS(Graph G, adrNode N) {
    // Reset status visited semua node menjadi 0 sebelum mulai
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }

    // Mulai penelusuran
    dfsHelper(N);
}

// --- Nomor 3: Prosedur PrintBFS ---

void printBFS(Graph G, adrNode N) {
    if (N == NULL) return;

    // Reset status visited semua node menjadi 0
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }

    // Siapkan Queue
    queue<adrNode> Q;

    // Masukkan node awal ke antrian dan tandai visited
    Q.push(N);
    N->visited = 1;

    while (!Q.empty()) {
        // Ambil node depan antrian
        adrNode current = Q.front();
        Q.pop();

        cout << current->info << " ";

        // Cek semua tetangga
        adrEdge E = current->firstEdge;
        while (E != NULL) {
            // Jika tetangga belum dikunjungi, masukkan ke antrian
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}
```

main.cpp
```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    // 1. Insert Node (A sampai H)
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    // 2. Buat Koneksi sesuai Gambar Ilustrasi (Graph Tidak Berarah)
    // A terhubung ke B dan C
    connectNode(findNode(G, 'A'), findNode(G, 'B'));
    connectNode(findNode(G, 'A'), findNode(G, 'C'));
    
    // B terhubung ke D dan E
    connectNode(findNode(G, 'B'), findNode(G, 'D'));
    connectNode(findNode(G, 'B'), findNode(G, 'E'));

    // C terhubung ke F dan G
    connectNode(findNode(G, 'C'), findNode(G, 'F'));
    connectNode(findNode(G, 'C'), findNode(G, 'G'));

    // D, E, F, G terhubung ke H
    connectNode(findNode(G, 'D'), findNode(G, 'H'));
    connectNode(findNode(G, 'E'), findNode(G, 'H'));
    connectNode(findNode(G, 'F'), findNode(G, 'H'));
    connectNode(findNode(G, 'G'), findNode(G, 'H'));

    // Tampilkan Info Graph
    cout << "=== Info Graph (Adjacency List) ===" << endl;
    printInfoGraph(G);
    cout << endl;

    // Panggil DFS
    cout << "=== Hasil Penelusuran DFS (Mulai dari A) ===" << endl;
    printDFS(G, findNode(G, 'A'));
    cout << endl << endl;

    // Panggil BFS
    cout << "=== Hasil Penelusuran BFS (Mulai dari A) ===" << endl;
    printBFS(G, findNode(G, 'A'));
    cout << endl;

    return 0;
}
```

### Output Unguided 3 :

![Screenshot Output Unguided 3_1](https://github.com/ORANGTZY/103112400056_Felix-Pedrosa-Valentino/blob/main/strukdat_week14_modul14/output-unguided3-modul14.png)

Program ini mengimplementasikan struktur data Graph Tidak Berarah (Undirected Graph) menggunakan representasi Adjacency List dalam bahasa C++. Struktur data disusun secara dinamis menggunakan linked list, di mana setiap simpul (ElmNode) menyimpan informasi karakter, status kunjungan (visited), serta pointer yang menunjuk ke daftar sisi (ElmEdge) sebagai representasi tetangganya. Penggunaan atribut visited sangat krusial dalam program ini untuk mencegah terjadinya infinite loop (siklus tak berujung) saat melakukan penelusuran graph.

Fungsionalitas program mencakup operasi dasar graph serta dua algoritma penelusuran utama. Operasi connectNode dirancang untuk menangani sifat graph tidak berarah dengan membuat hubungan timbal balik (dua arah) antar simpul secara otomatis. Untuk penelusuran, program menyediakan Depth-First Search (DFS) yang menggunakan pendekatan rekursif untuk menelusuri jalur sedalam mungkin sebelum backtracking, dan Breadth-First Search (BFS) yang memanfaatkan struktur data std::queue dari pustaka standar untuk mengunjungi simpul secara melebar (per level) dari titik awal.

Pada eksekusi utama (main.cpp), program membangun sebuah topologi graph yang terdiri dari 8 simpul (A hingga H) dengan pola koneksi hierarkis yang menyatu kembali di simpul akhir. Program kemudian menampilkan tiga luaran utama untuk analisis: visualisasi struktur graph melalui daftar keterhubungan (adjacency list), urutan kunjungan simpul menggunakan algoritma DFS, dan urutan kunjungan simpul menggunakan algoritma BFS, yang semuanya dimulai dari simpul akar A.

## Kesimpulan
Graph merupakan struktur data non-linear yang fundamental untuk memodelkan hubungan kompleks antar objek melalui himpunan simpul (vertices) dan sisi (edges). Struktur ini memiliki fleksibilitas tinggi dengan berbagai variasi jenis, seperti Directed Graph dan Undirected Graph, serta kemampuan menampung bobot (weighted) yang krusial untuk algoritma pencarian jalur. Dalam implementasi teknis menggunakan C++, pemilihan metode representasi menjadi aspek penting, di mana Adjacency Matrix menawarkan kecepatan akses data konstan namun membutuhkan memori besar, sedangkan Adjacency List memberikan efisiensi ruang yang lebih optimal. Selain itu, pengolahan data dalam Graph didukung oleh algoritma penelusuran utama, yaitu BFS (Breadth-First Search) dan DFS (Depth-First Search), yang masing-masing memanfaatkan struktur data antrian dan tumpukan untuk mengunjungi elemen-elemen di dalamnya.

## Referensi
[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
<br>
[2] Rosen, K. H. (2019). Discrete Mathematics and Its Applications (8th ed.). McGraw-Hill Education.
<br>
[3] GeeksforGeeks. (2024). Graph Data Structure and Algorithms. Diakses dari https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/
<br>
[4] Sedgewick, R. (2002). Algorithms in C++, Part 5: Graph Algorithms (3rd ed.). Addison-Wesley Professional.
<br>
[5] Deitel, P., & Deitel, H. (2017). C++ How to Program (10th ed.). Pearson Education.