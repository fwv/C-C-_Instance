#include<iostream>
using namespace std;
class Node{
    public:
        int v;
        int w;
        Node(int _v, int _w) {
            v = _v;
            w = _w;
        }

        void visit();

        private:
        

};

void Node::visit() {
    cout<<"node "<< v <<" is visited!" << endl; 
}