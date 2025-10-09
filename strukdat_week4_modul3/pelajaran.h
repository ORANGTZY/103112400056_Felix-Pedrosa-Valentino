#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

// Definisi tipe data pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// Fungsi dan prosedur
pelajaran create_pelajaran(string namaPel, string kodePel);
void tampil_pelajaran(pelajaran pel);

#endif
