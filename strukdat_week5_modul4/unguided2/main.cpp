#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    address Pdel, Prec;

    createList(L);

    // Membuat list 9 -> 12 -> 8 -> 0 -> 2
    insertLast(L, alokasi(9));
    insertLast(L, alokasi(12));
    insertLast(L, alokasi(8));
    insertLast(L, alokasi(0));
    insertLast(L, alokasi(2));

    // Hapus node 9 menggunakan deleteFirst()
    deleteFirst(L, Pdel);
    dealokasi(Pdel);

    // Hapus node 2 menggunakan deleteLast()
    deleteLast(L, Pdel);
    dealokasi(Pdel);

    // Hapus node 8 menggunakan deleteAfter()
    Prec = L.First;       // Prec menunjuk ke node 12
    deleteAfter(L, Prec, Pdel);
    dealokasi(Pdel);

    // Tampilkan sisa list
    printInfo(L);

    // Tampilkan jumlah node
    cout << "Jumlah node : " << nbList(L) << endl << endl;

    // Hapus seluruh list
    deleteList(L);

    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
