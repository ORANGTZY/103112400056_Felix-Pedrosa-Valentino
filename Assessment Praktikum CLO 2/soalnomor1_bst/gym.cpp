#include <iostream>
#include <string>
#include "gym.h"

using namespace std;

// Inisialisasi variabel global root
Node *root;

// Method: isEmpty()
bool isEmpty() {
    return root == NULL;
}

// Method: createTree()
void createTree() {
    root = NULL;
}

// Method: newNode()
Node* newNode(string nama, float berat, string tier) {
    Node* node = new Node();
    node->namaMember = nama;
    node->beratBadan = berat;
    node->tierMember = tier;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// --- Helper Functions (Fungsi Bantuan Recursive) ---

// Helper untuk insert
Node* insertRecursive(Node* node, string nama, float berat, string tier) {
    if (node == NULL) {
        return newNode(nama, berat, tier);
    }
    if (berat < node->beratBadan) {
        node->left = insertRecursive(node->left, nama, berat, tier);
    }
    else if (berat > node->beratBadan) {
        node->right = insertRecursive(node->right, nama, berat, tier);
    }
    return node;
}

// Helper untuk inOrder traversal
void inOrderRecursive(Node* node) {
    if (node == NULL) return;
    inOrderRecursive(node->left);
    cout << node->beratBadan << " - ";
    inOrderRecursive(node->right);
}

// --- Implementasi Method Utama ---

// Method: insertNode()
void insertNode(string nama, float berat, string tier) {
    root = insertRecursive(root, nama, berat, tier);
}

// Method: mostLeft()
void mostLeft() {
    if (isEmpty()) return;
    
    Node* curr = root;
    while (curr->left != NULL) {
        curr = curr->left;
    }
    cout << "Node MostLeft : " << curr->beratBadan << endl;
}

// Method: mostRight()
void mostRight() {
    if (isEmpty()) return;

    Node* curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }
    cout << "Node MostRight : " << curr->beratBadan << endl;
}

// Method: inOrder()
void inOrder() {
    cout << "=== Traversal InOrder ===" << endl;
    inOrderRecursive(root);
    cout << endl;
}

// Method: searchByBeratBadan()
void searchByBeratBadan(float targetBerat) {
    Node* curr = root;
    Node* parent = NULL;
    bool found = false;

    while (curr != NULL) {
        if (curr->beratBadan == targetBerat) {
            found = true;
            break;
        }
        parent = curr;
        if (targetBerat < curr->beratBadan) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if (found) {
        cout << "Data ditemukan didalam BST!" << endl;
        
        cout << "--- Data Node Yang Dicari ---" << endl;
        cout << "Nama Member : " << curr->namaMember << endl;
        cout << "Berat Badan : " << curr->beratBadan << endl;
        cout << "Tier Member : " << curr->tierMember << endl;
        cout << "-----------------------------" << endl;

        if (parent != NULL) {
            cout << endl << "--- Data Parent ---" << endl;
            cout << "Nama Member : " << parent->namaMember << endl;
            cout << "Berat Badan : " << parent->beratBadan << endl;
            cout << "Tier Member : " << parent->tierMember << endl;
            cout << "-----------------------------" << endl;

            Node* sibling = NULL;
            if (parent->left == curr) {
                sibling = parent->right;
            } else {
                sibling = parent->left;
            }

            if (sibling == NULL) {
                cout << "Tidak Memiliki Sibling" << endl;
                cout << "-----------------------------" << endl;
            } else {
                cout << "Memiliki Sibling" << endl; // Opsional
                cout << "-----------------------------" << endl;
            }
        } else {
            cout << endl << "Node adalah Root (Tidak punya Parent)" << endl;
        }

        if (curr->left != NULL) {
            cout << endl << "--- Data Child Kiri ---" << endl;
            cout << "Nama Member : " << curr->left->namaMember << endl;
            cout << "Berat Badan : " << curr->left->beratBadan << endl;
            cout << "Tier Member : " << curr->left->tierMember << endl;
            cout << "-----------------------------" << endl;
        } 

        if (curr->right != NULL) {
            cout << endl << "--- Data Child Kanan ---" << endl;
            cout << "Nama Member : " << curr->right->namaMember << endl;
            cout << "Berat Badan : " << curr->right->beratBadan << endl;
            cout << "Tier Member : " << curr->right->tierMember << endl;
            cout << "-----------------------------" << endl;
        }

    } else {
        cout << "Data member dengan berat " << targetBerat << " tidak ditemukan." << endl;
    }
}