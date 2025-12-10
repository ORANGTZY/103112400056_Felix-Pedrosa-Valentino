#include "MultiLL.h" // Include header 

// Variabel global untuk List Utama agar bisa diakses di berbagai step
listParent LP;

int main() {
    // --- BAGIAN NOMOR 1: CREATE & INSERT ---
    createListParent(LP);

    NodeParent P;
    NodeChild C;

    // 1. Insert Parent G001 (Aves)
    P = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P);
        // Child G001
        C = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
        insertLastChild(P->L_Child, C);
        C = allocNodeChild("AV002", "Bebek", "Air", true, 2.0);
        insertLastChild(P->L_Child, C);

    // 2. Insert Parent G002 (Mamalia)
    P = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P);
        // Child G002
        C = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
        insertLastChild(P->L_Child, C);
        C = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
        insertLastChild(P->L_Child, C);
        C = allocNodeChild("M002", "Kucing", "Darat", true, 4);
        insertLastChild(P->L_Child, C);

    // 3. Insert Parent G003 (Pisces)
    P = allocNodeParent("G003", "Pisces");
    insertLastParent(LP, P);
        // No Child

    // 4. Insert Parent G004 (Amfibi)
    P = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P);
        // Child G004
        C = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
        insertLastChild(P->L_Child, C);

    // 5. Insert Parent G005 (Reptil)
    P = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P);
        // No Child

    // PRINT HASIL NOMOR 1
    cout << "=== OUTPUT NOMOR 1 (STRUCTURE) ===" << endl;
    printMLLStructure(LP);
    cout << "==================================" << endl << endl;

    // --- BAGIAN NOMOR 2: SEARCHING ---
    cout << "=== OUTPUT NOMOR 2 (SEARCHING EKOR = FALSE) ===" << endl;
    // Cari hewan yang TIDAK punya ekor (False/0)
    searchHewanByEkor(LP, false); 
    cout << "===============================================" << endl << endl;

    // --- BAGIAN NOMOR 3: DELETE G004 ---
    cout << "=== OUTPUT NOMOR 3 (DELETE G004 & PRINT) ===" << endl;
    
    // Logika menghapus G004 (Amfibi)
    // Kita cari dulu node G003 (Pisces) sebagai 'predecessor'
    NodeParent P_Search = LP.first;
    NodeParent Pre_Node = NULL;
    
    while(P_Search != NULL){
        if(P_Search->isidata.idGolongan == "G003"){
            Pre_Node = P_Search;
            break;
        }
        P_Search = P_Search->next;
    }

    // Lakukan penghapusan jika G003 ditemukan
    if (Pre_Node != NULL) {
        deleteAfterParent(LP, Pre_Node); // Ini akan menghapus G004 beserta childnya
    }

    // Print hasil setelah penghapusan
    printMLLStructure(LP);
    cout << "============================================" << endl;
    
    return 0;
}