#include<iostream>
using namespace std;

// implement by array
int st[20];
int TOP;

void clear() {
    TOP = -1;
}

int size() {
    return TOP + 1;
}

bool empty() {
    return -1 == TOP;
}

void pop() {
    TOP--;
}

void push(int a) {
    st[++TOP] = a;
}

int top() {
    return st[TOP];
}
