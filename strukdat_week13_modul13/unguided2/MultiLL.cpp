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