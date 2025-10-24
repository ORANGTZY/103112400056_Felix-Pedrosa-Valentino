#include<iostream>
using namespace std;

//Definisi node
struct Node { //memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//prosedur untuk menambahkan node
void append(Node*& head, int value){ // Node* ini pointer (kembalian) 
    Node* newNode = new Node{value, nullptr}; // membuat pointer baru 
    if(!head)head = newNode; //jika head null, head diisi node baru 
    else{
        Node* temp = head; //mulai dari head
        while(temp->next)temp = temp->next; //pindah ke node berikutnya sampai ketemu node terakhir
        temp->next = newNode; //node terakhir dihubungkan ke node baru
    }
}

Node* binarySearch(Node* head, int key) {  // Node* ini pointer (kembalian)  // head ini pointer ke node pertama  // key ini data yang dicari
    int size = 0; // var size diisi 0
    for (Node* current = head; current; current = current->next) size++; // current adalah pointer yangg digunakan untuk menyusuri linked list
    Node *start = head; // start adalah pointer yang menunjuk ke node pertama
    Node *end = nullptr; 
    while (size > 0) { // selama masih ada elemen > 0
        int mid =  size / 2; // bagi size jadi 2
        Node* midNode = start;
        for (int i = 0; i < mid; i++) midNode = midNode->next; // pindah ke node tengah
        if (midNode->data == key) return midNode; // Jika ditemukan data yang cocok, kembalikan ke node
        if (midNode->data < key) {  // Jika data midNode lebih kecil dari key, kita cari di bagian kanan
            start = midNode->next; // Mulai pencarian dari node setelah midNode
        } else { //jika data midNode lebih besar dari key, kita cari di bagian kiri
            end = midNode; // batasi pencarian ke bagian kiri 
        }
        size -= mid;  //kita mengurangi size dengan mid
    }
    return nullptr; // Jika key tidak ditemukan
}

int main() {
    Node* head = nullptr; //inisialisasi linked list kosong 
    append(head, 10); append(head, 20); append(head, 30); append(head, 40); append(head, 50); // menambah node 

    // mencari data 40 menggunakan binary search 
    Node* result = binarySearch(head, 40); 
    cout << (result ? "Found" : "Not Found") << endl; // menampilkan hasil pencarian

    return 0;
}
