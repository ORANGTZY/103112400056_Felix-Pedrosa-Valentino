#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = 0;
    if (S.top >= 0) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack kosong!" << endl;
    }
    return x;
}

void printInfo(Stack S) {
    if (S.top >= 0) {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Stack kosong!" << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    
    while (S.top >= 0) {
        push(temp, pop(S));
    }
    
    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);
    
    // Pop semua elemen yang lebih besar dari x ke stack temporary
    while (S.top >= 0 && S.info[S.top] > x) {
        push(temp, pop(S));
    }
    
    // Push elemen x ke posisi yang tepat
    push(S, x);
    
    // Kembalikan elemen-elemen dari temp ke S
    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}