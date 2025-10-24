#include <iostream>
#include <iomanip>
using namespace std;

// Definisi node
struct Node {
    int data;       // Data integer
    Node* next;     // Pointer ke node berikutnya
};

// Prosedur untuk menambahkan node di akhir linked list
void append(Node*& head, int value) {
    // Membuat node baru dengan data value dan next = nullptr
    Node* newNode = new Node{value, nullptr};
    
    if (!head) {
        // Jika linked list kosong, node baru menjadi head
        head = newNode;
    } else {
        // Traverse ke node terakhir
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        // Hubungkan node terakhir dengan node baru
        temp->next = newNode;
    }
}

// Prosedur untuk menampilkan visualisasi linked list
void visualizeList(Node* head) {
    cout << "Linked List yang dibuat: ";
    Node* current = head;
    
    while (current) {
        cout << current->data;
        if (current->next) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

// Fungsi Linear Search pada Linked List dengan visualisasi detail
Node* linearSearch(Node* head, int key) {
    // Jika linked list kosong
    if (head == nullptr) {
        cout << "Linked list kosong!" << endl;
        return nullptr;
    }
    
    cout << "\nProses Pencarian:" << endl;
    
    Node* current = head;   // Pointer untuk traverse linked list
    int nodeNumber = 1;     // Counter nomor node
    
    // Traverse linked list dari awal sampai akhir
    while (current != nullptr) {
        // Tampilkan node yang sedang diperiksa
        cout << "Memeriksa node " << nodeNumber << ": " 
             << current->data;
        
        // Cek apakah data pada node current sama dengan key
        if (current->data == key) {
            // Data ditemukan
            cout << " (SAMA) - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key 
                 << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << current << endl;
            cout << "Data node: " << current->data << endl;
            
            // Tampilkan node berikutnya jika ada
            if (current->next != nullptr) {
                cout << "Node berikutnya: " << current->next->data << endl;
            } else {
                cout << "Node berikutnya: NULL (ini adalah node terakhir)" << endl;
            }
            
            return current;
        } else {
            // Data tidak sama, lanjut ke node berikutnya
            cout << " (tidak sama)" << endl;
        }
        
        // Pindah ke node berikutnya
        current = current->next;
        nodeNumber++;
    }
    
    // Jika sampai di sini, berarti data tidak ditemukan
    cout << "Tidak ada node lagi yang tersisa" << endl;
    cout << "\nHasil: Nilai " << key 
         << " TIDAK DITEMUKAN dalam linked list!" << endl;
    
    return nullptr;
}

// Fungsi untuk membersihkan memori linked list
void deleteList(Node*& head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;  // Inisialisasi linked list kosong
    
    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;
    
    // Membuat linked list dengan minimal 3 elemen
    // Data tidak perlu terurut untuk linear search
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    
    // Visualisasi linked list
    visualizeList(head);
    
    // TEST CASE 1: Mencari nilai yang ada (30)
    cout << "Mencari nilai: 30" << endl;
    Node* result1 = linearSearch(head, 30);
    
    cout << "\n" << string(60, '=') << endl;
    
    // TEST CASE 2: Mencari nilai yang tidak ada (25)
    cout << "\nMencari nilai: 25" << endl;
    Node* result2 = linearSearch(head, 25);
    
    // Membersihkan memori
    deleteList(head);
    
    return 0;
}