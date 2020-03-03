#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    node* next;
}; 


/** apply for dynamic memory */
    // by malloc() in C
    node* p1 = (node*)malloc(sizeof(node));
    //free(p1);

    // by new() in C++, distinguish in java
    node* p2 = new node;
    //delete(p2);

     