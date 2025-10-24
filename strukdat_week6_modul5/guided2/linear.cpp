#include<iostream>
using namespace std;

//Definisi node
struct Node { //memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk pencarian linear
Node* linearSearch(Node* head, int key) {
    Node* current = head; //mulai dari node pertama
    while (current != nullptr) { //traverse sampai akhir list
        if (current->data == key) return current; // jika data ketemu
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //tidak ditemukan
}

//prosedur untuk menambahkan node
void append(Node*& head, int value){ // parameter head adalah referensi ke pointer head  // value adalah data yang mau dimasukkin
    Node* newNode = new Node{value, nullptr}; // membuat pointer baru 
    if(!head)head = newNode; //jika head null, head diisi node baru 
    else{
        Node* temp = head; //mulai dari head
        while(temp->next)temp = temp->next; //pindah ke node berikutnya sampai ketemu node terakhir
        temp->next = newNode; //node terakhir dihubungkan ke node baru
    }
}

int main() {
    Node* head = nullptr; //inisialisasi head list masih kosong 
    append(head, 10); append(head, 20); append(head, 30); // menambah node 

    Node* result = linearSearch(head, 20); // result ini pointer untuk mencari node dengan data 20 
    cout << (result ? "Found" : "Not Found") << endl; // condition ? value_if_true : value_if_false

    return 0;
}