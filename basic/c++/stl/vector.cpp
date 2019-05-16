#include<iostream>
#include<vector>
using namespace std;

/* 
-----vector-----
Structure:variable-length array
Pattern:train
Connection:List in Java
-----vector----- 
*/
void vector_instance() {

    //initialization
        //1-d
        vector<int> S;
        //2-d variable-length
        vector<vector<int>> S1;
        //2-d fixed-length
        vector<int> S2[10];

        S.push_back(1);
        S.push_back(2);
        S.push_back(3);
    //visit
        //by index
            //printf("vector S[0]'s value is : %d\n",S[0]);
        //by iterator
            //printf("vector S addr is: %d\n", S.begin());   
            vector<int>::iterator it = S.begin(); 
            // int i = *(it+2);
            // printf("vector S[0]'s value is : %d\n",i);
    
    // majority usage of vectors
        // S.pop_back();
        // S.size();
        // S.clear();
        // S.insert(it+2, 1);   
        // S.erase(it+2);s
        // S.erase(it+1,it+2);
            

}