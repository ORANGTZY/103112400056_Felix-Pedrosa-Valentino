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