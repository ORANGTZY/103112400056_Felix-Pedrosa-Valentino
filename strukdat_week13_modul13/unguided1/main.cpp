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

    return 0;
}