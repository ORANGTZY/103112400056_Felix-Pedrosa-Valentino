#include "bioskop.h"

// --- Membuat List Kosong ---
void createListParent(ListParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(ListChild &L) {
    L.first = NULL;
    L.last = NULL;
}

// --- Alokasi Node ---
adrParent alokasiNodeParent(string id, string nama) {
    adrParent P = new NodeParent;
    P->IDGenre = id;
    P->namaGenre = nama;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->child); // Inisialisasi list child kosong untuk parent ini
    return P;
}

adrChild alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    adrChild P = new NodeChild;
    P->IDFilm = id;
    P->judulFilm = judul;
    P->durasiFilm = durasi;
    P->tahunTayang = tahun;
    P->ratingFilm = rating;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

// --- Dealokasi ---
void dealokasiNodeParent(adrParent P) {
    delete P;
}

void dealokasiNodeChild(adrChild P) {
    delete P;
}

// --- Insert Parent (First) ---
void insertFirstParent(ListParent &L, adrParent P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

// --- Insert Child (Last) ---
void insertLastChild(ListChild &L, adrChild P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

// --- Menghapus seluruh Child dari Parent tertentu ---
void hapusListChild(adrParent P) {
    adrChild curr = P->child.first;
    adrChild temp;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        dealokasiNodeChild(temp);
    }
    // Set pointer list child menjadi NULL setelah dihapus semua
    P->child.first = NULL;
    P->child.last = NULL;
}

// --- Delete Parent After (beserta childnya) ---
void deleteAfterParent(ListParent &L, adrParent prec) {
    if (prec != NULL && prec->next != NULL) {
        adrParent del = prec->next;
        
        // 1. Hapus semua child dari node yang akan dihapus
        hapusListChild(del);

        // 2. Relinking List Parent
        prec->next = del->next;
        if (del->next != NULL) {
            del->next->prev = prec;
        } else {
            // Jika yang dihapus adalah node terakhir
            L.last = prec;
        }

        // 3. Dealokasi node parent
        dealokasiNodeParent(del);
    }
}

// --- Helper: Mencari Parent berdasarkan Nama (untuk insert di main) ---
adrParent findParent(ListParent L, string namaGenre) {
    adrParent P = L.first;
    while (P != NULL) {
        if (P->namaGenre == namaGenre) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

// --- Menampilkan Seluruh Struktur MLL ---
void printStrukturMLL(ListParent L) {
    adrParent P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre   : " << P->IDGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;

        adrChild C = P->child.first;
        int j = 1;
        if (C == NULL) {
            cout << "  (Tidak ada film)" << endl;
        }
        while (C != NULL) {
            cout << "  - Child " << j << " :" << endl;
            cout << "      ID Film      : " << C->IDFilm << endl;
            cout << "      Judul Film   : " << C->judulFilm << endl;
            cout << "      Durasi Film  : " << C->durasiFilm << " menit" << endl;
            cout << "      Tahun Tayang : " << C->tahunTayang << endl;
            cout << "      Rating Film  : " << C->ratingFilm << endl;
            C = C->next;
            j++;
        }
        cout << "------------------------------" << endl;
        P = P->next;
        i++;
    }
    cout << endl;
}

// --- Mencari Film berdasarkan Range Rating ---
void searchFilmByRatingRange(ListParent L, float minRating, float maxRating) {
    adrParent P = L.first;
    int idxP = 1;
    bool foundAny = false;

    while (P != NULL) {
        adrChild C = P->child.first;
        int idxC = 1;
        while (C != NULL) {
            if (C->ratingFilm >= minRating && C->ratingFilm <= maxRating) {
                foundAny = true;
                cout << "Data Film ditemukan pada list child dari node parent " << P->namaGenre 
                     << " pada posisi ke-" << idxC << "!" << endl;
                
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film  : " << C->judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << idxC << endl;
                cout << "ID Film     : " << C->IDFilm << endl;
                cout << "Durasi Film : " << C->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang: " << C->tahunTayang << endl;
                cout << "Rating Film : " << C->ratingFilm << endl;
                cout << "-------------------------" << endl;

                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre    : " << P->IDGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << idxP << endl;
                cout << "Nama Genre  : " << P->namaGenre << endl;
                cout << "==========================================" << endl;
            }
            C = C->next;
            idxC++;
        }
        P = P->next;
        idxP++;
    }

    if (!foundAny) {
        cout << "Tidak ada film dengan rating " << minRating << " - " << maxRating << endl;
    }
}