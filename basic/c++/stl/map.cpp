#include<map>
#include<iostream>
#include<string>
using namespace std;

/* 
-----map-----
Structure:key_value partners
Pattern:<PinkMan,Hesenberg>
Connection:Map in Java
-----map----- 
*/
void map_instance() {
    map<string,int> mp;

    //visit
        //by index
        mp["fengwei"] = 24;

        //by iterator
        map<string,int>::iterator it = mp.begin();
        printf("name: %s, age: %d\n",it->first, it->second);    

        //for 
        map<string, int>::iterator it1;
        for(it1 = mp.begin();it1 != mp.end(); it1++) { 
            printf("name: %s, age: %d\n",it1->first, it1->second);
        }

}       