#ifndef GYM_H
#define GYM_H

#include <string>

using namespace std;

// Definisi ADT Node
struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node *left;
    Node *right;
};

// Variabel Global Root (extern agar bisa diakses di file lain)
extern Node *root;

// Deklarasi Function / Method
bool isEmpty();
void createTree();
Node* newNode(string nama, float berat, string tier);
void insertNode(string nama, float berat, string tier);
void searchByBeratBadan(float targetBerat);
void mostLeft();
void mostRight();
void inOrder();

#endif