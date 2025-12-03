#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else if (root->info == x) {
        return root;
    } else {
        if (x < root->info) {
            return findNode(x, root->left);
        } else {
            return findNode(x, root->right);
        }
    }
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
}

int hitungTotalInfo(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
    }
}

// Implementasi rekursif untuk kedalaman (max depth)
int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start; // Mengembalikan level terakhir yang dicapai
    } else {
        int leftDepth = hitungKedalaman(root->left, start + 1);
        int rightDepth = hitungKedalaman(root->right, start + 1);
        
        if (leftDepth > rightDepth) return leftDepth;
        else return rightDepth;
    }
}

void printPreorder(address root) {
    if (root != Nil) {
        cout << root->info << " ";      // Cetak Akar
        printPreorder(root->left);      // Kunjungi Kiri
        printPreorder(root->right);     // Kunjungi Kanan
    }
}

void printPostorder(address root) {
    if (root != Nil) {
        printPostorder(root->left);     // Kunjungi Kiri
        printPostorder(root->right);    // Kunjungi Kanan
        cout << root->info << " ";      // Cetak Akar
    }
}