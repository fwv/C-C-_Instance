#include<iostream>
using namespace std;
class lt
{
public:
    lt(/* args */)=default;
    ~lt()=default;
    virtual void run(){
        cout<<"lt::run()"<<endl;
    };
};

