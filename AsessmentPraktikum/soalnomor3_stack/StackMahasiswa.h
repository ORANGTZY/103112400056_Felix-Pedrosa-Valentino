#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
#include <string>

using namespace std;

const int MAX = 6;

// Type Struct Mahasiswa
struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

// Type StackMahasiswa
struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

// Prototype Functions & Procedures
bool isEmpty(StackMahasiswa &S);
bool isFull(StackMahasiswa &S);
void createStack(StackMahasiswa &S);

// Push interaktif
void Push(StackMahasiswa &S);

// Overload Push (opsional, untuk mempermudah input otomatis di main)
void Push(StackMahasiswa &S, Mahasiswa mhsBaru);

void Pop(StackMahasiswa &S);
void Update(StackMahasiswa &S, int posisi);
void View(StackMahasiswa &S);

void SearchNilaiAkhir(StackMahasiswa &S, float min, float max);

// Bagian B: MaxNilaiAkhir
void MaxNilaiAkhir(StackMahasiswa &S);

#endif