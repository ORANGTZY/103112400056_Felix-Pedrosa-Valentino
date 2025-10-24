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
    Node* newNode = new Node{value, nullptr};  // Membuat node baru
    
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

// Fungsi Binary Search pada Linked List dengan visualisasi detail
Node* binarySearch(Node* head, int key) {
    // Menghitung jumlah elemen dalam linked list
    int size = 0;
    for (Node* current = head; current; current = current->next) {
        size++;
    }
    
    // Jika linked list kosong
    if (size == 0) {
        cout << "Linked list kosong!" << endl;
        return nullptr;
    }
    
    cout << "\nProses Pencarian:" << endl;
    
    // Variabel untuk menyimpan range pencarian
    int left = 0;           // Indeks kiri
    int right = size - 1;   // Indeks kanan
    int iterasi = 1;        // Counter iterasi
    
    // Binary Search Algorithm
    while (left <= right) {
        // Hitung indeks tengah
        int mid = left + (right - left) / 2;
        
        // Traverse ke node di posisi mid
        Node* midNode = head;
        for (int i = 0; i < mid; i++) {
            midNode = midNode->next;
        }
        
        // Tampilkan detail iterasi
        cout << "Iterasi " << iterasi << ": Mid = " << mid 
             << " (indeks tengah)";
        
        // Cek apakah data ditemukan
        if (midNode->data == key) {
            cout << " - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key 
                 << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << midNode << endl;
            cout << "Data node: " << midNode->data << endl;
            
            // Tampilkan node berikutnya
            if (midNode->next != nullptr) {
                cout << "Node berikutnya: " << midNode->next->data << endl;
            } else {
                cout << "Node berikutnya: NULL (ini adalah node terakhir)" << endl;
            }
            
            return midNode;
        }
        // Jika key lebih kecil dari midNode, cari di bagian kiri
        else if (key < midNode->data) {
            cout << " -> Cari di bagian kiri" << endl;
            right = mid - 1;
        }
        // Jika key lebih besar dari midNode, cari di bagian kanan
        else {
            cout << " -> Cari di bagian kanan" << endl;
            left = mid + 1;
        }
        
        iterasi++;
    }
    
    // Data tidak ditemukan
    cout << "Tidak ada elemen tersisa" << endl;
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
    
    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    
    // Membuat linked list dengan minimal 5 elemen (terurut ascending)
    // Data harus terurut untuk binary search bekerja dengan benar
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    
    // Visualisasi linked list
    visualizeList(head);
    
    // TEST CASE 1: Mencari nilai yang ada (40)
    cout << "Mencari nilai: 40" << endl;
    Node* result1 = binarySearch(head, 40);
    
    cout << "\n" << string(60, '=') << endl;
    
    // TEST CASE 2: Mencari nilai yang tidak ada (25)
    cout << "\nMencari nilai: 25" << endl;
    Node* result2 = binarySearch(head, 25);
    
    // Membersihkan memori
    deleteList(head);
    
    return 0;
}