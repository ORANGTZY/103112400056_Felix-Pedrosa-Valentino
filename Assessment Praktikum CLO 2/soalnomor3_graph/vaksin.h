#ifndef VAKSIN_H
#define VAKSIN_H

#include <string>
#include <iostream>

using namespace std;

// Forward declaration
struct Node;

// Struct Edge (Jalur Distribusi)
// Menyimpan pointer ke Node tujuan dan pointer ke Edge selanjutnya (milik Node asal yang sama)
struct Edge {
    Node* destNode;
    Edge* nextEdge;
};

// Struct Node (Kota)
// Menyimpan data kota, status simulasi, pointer ke Edge pertamanya, dan pointer ke Node selanjutnya (dalam list graph)
struct Node {
    string id;          // Nama Kota (A, B, C, etc.)
    bool isLockedDown;  // Status simulasi: true jika sedang disimulasikan lockdown
    bool visited;       // Helper untuk traversal DFS
    Edge* firstEdge;    // Head of Edge list
    Node* nextNode;     // Next node in graph list
};

// Struct Graph
// Hanya menyimpan pointer ke Node pertama
struct Graph {
    Node* firstNode;
};

// --- Fungsi Manajemen Graph ---
void createGraph(Graph &G);
Node* alokasiNode(string id);
void addNode(Graph &G, string id);
Node* findNode(Graph G, string id);
void addEdge(Graph &G, string src, string dest);

// --- Fungsi Algoritma & Simulasi ---
void resetVisited(Graph &G);
void dfs(Node* currentNode, int &countVisited);
int countActiveNodes(Graph G);
bool isGraphConnected(Graph G);
void printGraph(Graph G);
void analisisKotaKritis(Graph G);

#endif