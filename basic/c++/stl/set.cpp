#include<set>
#include<iostream>
using namespace std;

/* 
-----set-----
Structure:internally ordered and non-repeated array
Pattern:Chinese zodiac
Connection:Set in Java
-----set----- 
*/
void set_instance() {
        set<int> S;

        S.insert(3);
        S.insert(1);
        S.insert(2);

        set<int>::iterator it; 
        for(it = S.begin(); it!=S.end(); it++) {
            printf("%d\n", *it);
        }
        // majority usage
            //find() return the specific elem's iterator(pointer)
            it = S.find(2);
            //erase the specific elem
            S.erase(S.find(2)); //erase(it)
            S.erase(2);         //erase(value)
            S.erase(S.find(2), S.end());

        

}       