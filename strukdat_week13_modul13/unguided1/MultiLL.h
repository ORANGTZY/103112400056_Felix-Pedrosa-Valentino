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