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