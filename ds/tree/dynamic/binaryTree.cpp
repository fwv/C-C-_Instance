#include<iostream>
using namespace std;

struct node{
    int data;
    node* lchild;
    node* rchild;
}; 

node* newNode(int data) {
    //node * Node =  new node;
    node * Node =  (node*)malloc(sizeof(node));
    Node->data = data;
    Node->lchild = NULL;
    Node->rchild = NULL;
    return Node;
}
