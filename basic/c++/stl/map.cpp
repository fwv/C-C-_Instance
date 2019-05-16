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

}       