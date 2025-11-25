#include <iostream>
#include <string>

using namespace std;

// Struktur Node untuk Linked List
struct Node {
    string nama;
    Node *next;
};

// Pointer head global agar mudah diakses
Node *head = NULL;

// 1. Fungsi Insert (Menambah nama di akhir list)
void insertLast(string nama) {
    Node *newNode = new Node();
    newNode->nama = nama;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 2. Fungsi Delete (Menghapus nama pertama yang ditemukan)
void deleteByName(string target) {
    if (head == NULL) {
        return; // List kosong
    }

    // Jika node yang dihapus adalah head (data pertama)
    if (head->nama == target) {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    // Mencari node di tengah atau akhir
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL && curr->nama != target) {
        prev = curr;
        curr = curr->next;
    }

    // Jika data ditemukan
    if (curr != NULL) {
        prev->next = curr->next;
        delete curr;
    } else {
        // Opsional: Bisa tambah pesan jika nama tidak ditemukan
    }
}

// 3. Fungsi View (Menampilkan seluruh list)
void viewList() {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->nama << " ";
        temp = temp->next;
    }
    cout << endl;
}

// 4. Fungsi Hitung Genap (Menghitung nama dengan jumlah huruf genap)
void hitungGenap() {
    int count = 0;
    Node *temp = head;
    
    while (temp != NULL) {
        // Cek apakah panjang string habis dibagi 2 (genap)
        if (temp->nama.length() % 2 == 0) {
            count++;
        }
        temp = temp->next;
    }
    
    cout << "Jumlah nama dengan huruf genap: " << count << endl;
}

int main() {
    int pilihan;
    string inputNama;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> inputNama;
                insertLast(inputNama);
                break;

            case 2:
                cout << "Masukkan nama untuk delete: ";
                cin >> inputNama;
                deleteByName(inputNama);
                break;

            case 3:
                viewList();
                break;

            case 4:
                hitungGenap();
                break;

            case 0:
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}