#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "Nomor Polisi : " << P->info.nopol << endl;
            cout << "Warna        : " << P->info.warna << endl;
            cout << "Tahun        : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}

// SOAL NOMOR 2: Fungsi untuk mencari elemen berdasarkan nomor polisi
address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// SOAL NOMOR 3: Prosedur deleteFirst
void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.first;
        L.first = P->next;
        (L.first)->prev = Nil;
        P->next = Nil;
    }
}

// SOAL NOMOR 3: Prosedur deleteLast
void deleteLast(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.last;
        L.last = P->prev;
        (L.last)->next = Nil;
        P->prev = Nil;
    }
}

// SOAL NOMOR 3: Prosedur deleteAfter
void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            (P->next)->prev = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    } else {
        P = Nil;
    }
}