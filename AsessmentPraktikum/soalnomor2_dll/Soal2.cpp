#include <iostream>

using namespace std;

// Struktur Node untuk Double Linked List
struct Node {
    int data;
    Node *next;
    Node *prev;
};

// Global Pointers untuk Head (depan) dan Tail (belakang)
Node *head = NULL;
Node *tail = NULL;

// 1. Fungsi Insert Nilai Akhir
void insertLast(int nilai) {
    Node *newNode = new Node();
    newNode->data = nilai;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        // Jika list masih kosong
        head = newNode;
        tail = newNode;
    } else {
        // Sambungkan node baru setelah tail saat ini
        tail->next = newNode;
        newNode->prev = tail;
        // Pindahkan tail ke node baru
        tail = newNode;
    }
}

// 2. Fungsi Delete Nilai Terakhir
void deleteLast() {
    if (head == NULL) {
        return; // List kosong, tidak ada yang dihapus
    }

    Node *toDelete = tail;

    if (head == tail) {
        // Jika hanya ada 1 node
        head = NULL;
        tail = NULL;
    } else {
        // Jika lebih dari 1 node
        tail = tail->prev; // Mundurkan tail
        tail->next = NULL; // Putus hubungan dengan node lama
    }
    
    delete toDelete; // Hapus dari memori
}

// 3. Fungsi View Depan ke Belakang
void viewList() {
    Node *curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// 4. Fungsi Reverse List (Tukar urutan tanpa node baru)
void reverseList() {
    if (head == NULL) return;

    Node *current = head;
    Node *temp = NULL;

    // Loop untuk menukar pointer next dan prev pada setiap node
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        // Pindah ke node berikutnya (yang sekarang ada di prev karena sudah ditukar)
        current = current->prev;
    }

    // Setelah loop selesai, head dan tail harus ditukar posisinya secara global
    // Cek jika list tidak kosong atau cuma 1 elemen
    if (temp != NULL) {
        // Head yang baru adalah node terakhir yang diproses (temp->prev)
        tail = head;       // Head lama jadi Tail
        head = temp->prev; // Node terakhir jadi Head
    }
}

int main() {
    int pilihan;
    int inputAngka;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit" << endl;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> inputAngka;
                insertLast(inputAngka);
                break;

            case 2:
                deleteLast();
                break;

            case 3:
                viewList();
                break;

            case 4:
                reverseList();
                cout << "List setelah di-reverse: ";
                viewList();
                break;

            case 0:
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}