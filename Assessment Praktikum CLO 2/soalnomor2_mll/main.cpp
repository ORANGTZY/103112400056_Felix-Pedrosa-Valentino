#include <iostream>
#include "bioskop.h"

using namespace std;

int main() {
    ListParent LP;
    
    // 1. createListParent()
    createListParent(LP);

    // 2. Alokasi Node Parent & Insert First Parent
    // Agar urutannya G001 -> G002 -> G003 -> G004 menggunakan Insert First,
    // Harus insert dari belakang (G004 duluan).
    
    adrParent p1 = alokasiNodeParent("G004", "Romance");
    insertFirstParent(LP, p1);
    
    adrParent p2 = alokasiNodeParent("G003", "Horror");
    insertFirstParent(LP, p2);

    adrParent p3 = alokasiNodeParent("G002", "Comedy");
    insertFirstParent(LP, p3);

    adrParent p4 = alokasiNodeParent("G001", "Action");
    insertFirstParent(LP, p4);

    // 3. Insert Child (Film) ke Genre yang sesuai (Insert Last Child)
    
    // Film Action (G001)
    adrParent genreAction = findParent(LP, "Action");
    insertLastChild(genreAction->child, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));

    // Film Comedy (G002)
    adrParent genreComedy = findParent(LP, "Comedy");
    insertLastChild(genreComedy->child, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(genreComedy->child, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));

    // Film Horror (G003)
    adrParent genreHorror = findParent(LP, "Horror");
    insertLastChild(genreHorror->child, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));

    // Film Romance (G004)
    adrParent genreRomance = findParent(LP, "Romance");
    insertLastChild(genreRomance->child, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(genreRomance->child, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    // 4. Print Struktur MLL Awal
    cout << "### MLL AWAL ###" << endl;
    printStrukturMLL(LP);

    // 5. Search Film by Rating Range (8.0 - 8.5)
    cout << "### SEARCH FILM RATING 8.0 - 8.5 ###" << endl;
    searchFilmByRatingRange(LP, 8.0, 8.5);
    cout << endl;

    // 6. deleteAfterParent()
    // Hapus Node G002 (Comedy). Karena instruksi deleteAfter,
    // Harus cari node sebelumnya yaitu G001 (Action). 
    cout << "### DELETE PARENT G002 (COMEDY) ###" << endl;
    
    adrParent precNode = findParent(LP, "Action"); // Cari G001 sebagai prev
    deleteAfterParent(LP, precNode); // Menghapus G002 (setelah G001)

    // 7. Print Struktur MLL Akhir
    cout << "### MLL SETELAH PENGHAPUSAN ###" << endl;
    printStrukturMLL(LP);

    return 0;
}