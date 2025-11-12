#ifndef STACK_H 
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; // Array untuk menyimpan elemen stack
    int top;
}; 

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X); // Prosedur untuk menambah elemen baru ke dalam stack 
infotype pop(Stack &S); // Prosedur untuk menghapus elemen teratas dari stack 
void printInfo(Stack S); 
void balikStack(Stack &S); // Prosedur untuk membalik urutan elemen dalam stack

#endif