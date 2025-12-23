#include <iostream>
#include "gym.h"

using namespace std;

int main() {
    // 1. Create Tree
    createTree();

    // 2. Insert Node sesuai urutan soal
    insertNode("Rizkina Azizah", 60, "Basic");
    insertNode("Hakan Ismail", 50, "Bronze");
    insertNode("Olivia Saevali", 65, "Silver");
    insertNode("Felix Pedrosa", 47, "Gold");
    insertNode("Gamel Al Ghifari", 56, "Platinum");
    insertNode("Hanif Al Faiz", 70, "Basic");
    insertNode("Mutiara Fauziah", 52, "Bronze");
    insertNode("Davi Ilyas", 68, "Silver");
    insertNode("Abdad Mubarok", 81, "Gold");

    cout << endl;

    // 3. Tampilkan InOrder
    inOrder();
    cout << endl;

    // 4. Tampilkan MostLeft dan MostRight
    mostLeft();
    mostRight();
    cout << endl;

    // 5. Search Data
    searchByBeratBadan(70);

    return 0;
}