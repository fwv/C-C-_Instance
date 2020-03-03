#include<iostream>
#include<string>
using namespace std;

void string_instance() {
    string str = "hello, fengwei!";
    cout << str << endl;

    //visit by iterator
    string::iterator it = str.begin();
    for(;it!=str.end();it++) {
        printf("%c", *(it));
    }

    //basic usage
        //find
        cout << str.find("wei") << endl;
        cout << str.find("wwww") << endl;
        cout << string::npos << endl;

        //replace

} 
