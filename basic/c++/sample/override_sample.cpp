using namespace std;
#include <iostream>
void cpp_instance();
class A
{
public:
    virtual void act1() { cout << "A::act1" << endl; }
    A()
    {
        //act1();
    }
    void act2()
    {
        act1();
        //A::act1();
    }
};

class B : public A
{
public:
    B() {}
    virtual void act1() { cout << "B::act1" << endl; }
};
void cpp_instance()
{
    A *a = new B;
    a->act2();
    a->A::act1();
}