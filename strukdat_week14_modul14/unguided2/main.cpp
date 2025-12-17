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