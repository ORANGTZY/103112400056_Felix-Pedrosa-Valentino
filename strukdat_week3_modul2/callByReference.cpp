// guided 5

#include <iostream>
using namespace std;

void ubahNilai(int& ref) {
    ref = 20; // Mengubah nilai melalui referensi
}

int main() {
    int x = 10;
    cout << "Nilai sebelum diubah: " << x << endl;
    
    ubahNilai(x); // Mengirimkan referensi ke x
    cout << "Nilai setelah diubah: " << x << endl;
    
    return 0;
}