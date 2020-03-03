#include<iostream>
using namespace std;


/* 
-----queue-----
Structure:
Pattern:
        0    1   2   3   4   5   6   7   8
    ========================================
    | null | 2 | 3 | 2 | 5 | 7 | 8 | 5 | 4 |
    ========================================
        ^                                ^
        |                                |
      front                             rear

Connection:

-----queue----- 
*/

int q[20];
int front,rear;

void clear() {
    front = -1;
    rear = -1;
}

int getSize() {
    return rear-front;
}

bool isEmpty() {
    return rear==front;
}

void push(int a) {
    q[++rear] = a;
}

void pop() {
    front++;
}

int getTop() {

    // return q[++front]; error:change the structure of the queue
     return q[front+1];
}

int getRear() {
    return q[rear];
}