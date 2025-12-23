// main.cpp
#include <iostream>
#include "vaksin.h"

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    // 1. Buat Node (Kota) A, B, C, D, E
    addNode(G, "A");
    addNode(G, "B");
    addNode(G, "C");
    addNode(G, "D");
    addNode(G, "E");

    // 2. Buat Edge (Jalur) sesuai soal
    addEdge(G, "A", "B");
    addEdge(G, "C", "B");
    addEdge(G, "E", "B");
    addEdge(G, "D", "C");

    // 3. Tampilkan Graph Awal
    printGraph(G);

    // 4. Jalankan Analisis Critical Point
    analisisKotaKritis(G);

    return 0;
}