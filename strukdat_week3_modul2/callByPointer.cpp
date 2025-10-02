// guided 4

#include <iostream>
using namespace std;

void ubahNilai(int* ptr) {
    *ptr = 20; // Mengubah nilai yang ditunjuk oleh pointer
}

int main() {
    int x = 10;
    cout << "Nilai sebelum diubah: " << x << endl;
    
    ubahNilai(&x); // Mengirimkan alamat memori x ke fungsi
    cout << "Nilai setelah diubah: " << x << endl;
    
    return 0;
}