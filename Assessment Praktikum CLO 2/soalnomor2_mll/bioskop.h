#ifndef BIOSKOP_H
#define BIOSKOP_H

#include <iostream>
#include <string>

using namespace std;

// --- Definisi Pointer ---
typedef struct NodeChild* adrChild;
typedef struct NodeParent* adrParent;

// --- Definisi Node Child (Film) ---
struct NodeChild {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    adrChild next;
    adrChild prev;
};

// --- Definisi List Child ---
struct ListChild {
    adrChild first;
    adrChild last;
};

// --- Definisi Node Parent (Genre) ---
struct NodeParent {
    string IDGenre;
    string namaGenre;
    ListChild child; // Parent memiliki List Child di dalamnya
    adrParent next;
    adrParent prev;
};

// --- Definisi List Parent ---
struct ListParent {
    adrParent first;
    adrParent last;
};

// --- Prototype Fungsi ---

// Konstruktor List
void createListParent(ListParent &L);
void createListChild(ListChild &L);

// Manajemen Memori (Alokasi & Dealokasi)
adrParent alokasiNodeParent(string id, string nama);
adrChild alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);
void dealokasiNodeParent(adrParent P);
void dealokasiNodeChild(adrChild P);

// Operasi Insert
void insertFirstParent(ListParent &L, adrParent P);
void insertLastChild(ListChild &L, adrChild P);

// Operasi Delete
void hapusListChild(adrParent P);
void deleteAfterParent(ListParent &L, adrParent prec);

// Operasi Search & View
adrParent findParent(ListParent L, string namaGenre); // Helper untuk main
void searchFilmByRatingRange(ListParent L, float minRating, float maxRating);
void printStrukturMLL(ListParent L);

#endif