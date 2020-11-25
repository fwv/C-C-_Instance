using namespace std;
#include <iostream>
void cpp_instance();

class B1
{
public:
    // B1() { cout << "constructing B1 " << endl; }
    B1(int i) { cout << "constructing B1 " << i << endl; }
    ~B1() { cout << "destructing B1 " << endl; }
};
class B2
{
public:
    B2() { cout << "constructing B2 *" << endl; }
    ~B2() { cout << "destructing B2" << endl; }
};
class C : public B2, virtual public B1
{
    int j;
public:

    C(int a, int b, int c) : B1(a), memberB1(b), j(c) {cout << "constructing C *" << endl;}
    // C(int a, int b, int c) : j(c) {cout << "constructing C *" << endl;}
    ~C() {cout << "destructing C *" << endl;}
private:
    B1 memberB1;
    B2 memberB2;
};

void cpp_instance()
{
    C obj(1, 2, 3);
}