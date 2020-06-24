#include <iostream>
#include <vector>
#include <map>


#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;
class lt1 : lt
{
public:
    //1.hash table
    map<int,int> hash_t;
    int index = 0;
    vector<int> rlt;
    
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int>::iterator it = nums.begin();
       for (; it != nums.end(); it++)
       {
           int temp = target - *(it);
           if (hash_t.end() != hash_t.find(temp))
           {
               rlt.push_back(hash_t[temp]);
               rlt.push_back(index);
               return rlt;
           }
           hash_t[*(it)] = index++;
       }
       return rlt;
    }

    void run() override
    {
    }
};