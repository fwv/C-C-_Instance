using namespace std;
#include <iostream>
void cpp_instance();

template <class T>
class Node {
    public:
        Node()=default;
        Node(T t);
        Node(Node & n);
        ~Node()=default;
        // Node& operator =(const Node&);
        // friend istream& operator>>(istream&, const Node<T>&);
        friend ostream& operator<<(ostream& out, Node& n){
             out << n.val << "\t";
            //  out << endl;
             return out;
        }
        // friend Node<T>& operator+(Node<T>&, Node<T>&);
        // void show()const;
    private:
        T val;
        Node *next;
};

template<class T>
Node<T>::Node(T t) {
    this->val = t;
    this->next = nullptr;
}

template<class T>
Node<T>::Node(Node& node) {
    this->val = node.val;
    this->next = nullptr;
}

// template<class T>
// Node<T>& Node<T>::operator =(const Node<T>& node){
//     this->val = node.val;
//     this->next = nullptr;
//     return this;
// }

// template<class T>
// istream& operator>>(istream& in, const Node<T> &node) {
//     return in>>node.val;
// }

// template<class T>
// ostream& operator<<(ostream& out, const Node<T> &node) {
//     return out<<node.val;
// }

// template<class T>
// Node<T>& operator+(Node<T>& node1, Node<T>& node2) {
//     // Node& tail = this;
//     // while (tail!=nullptr)
//     // {
//     //     tail = tail->next;
//     // }
//     node1.next = &node2;
//     return node1;
// }

// template<class T>
// void Node<T>::show()const {
//     cout<<*this;
//     while (nullptr!=this->next)
//     {
//         cout<<"->"<<*(this->next);
//     }
//     cout<<endl;
// }

void cpp_instance()
{   
    Node<int> n1(1);
    Node<int> n2(2);
    cout << n1 << n2;
    // cout<<endl;
    // Node<int> n2(2);
    // Node<int> n3(3);
    // n1.show();
    // n1 = n1+n2+n3;
    //n1.show();
}