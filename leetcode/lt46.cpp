#include<vector>
#ifndef LT_H
#define LT_H
#include"lt.cpp"
#endif
using namespace std;

// 核心：回溯
// 46.Permutations
// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/permutations

class lt46 : public lt{
public:
    int n;
    int temp[50];
    vector<vector<int>> rlt;
    bool hashlist[50];

    vector<vector<int>> permute(vector<int>& nums) {
       n = nums.size();
       for (int i = 0; i <= n-1; i++) {
           hashlist[i] = true;
       }
       generate(1, nums);
       return rlt;
    }

    void generate(int index, vector<int>& nums) {
      if(index == n+1) { //right 
        vector<int> temp_rlt;
        for (int i = 1; i <= n; i++)
        {
            temp_rlt.push_back(temp[i]);
        }
        rlt.push_back(temp_rlt);
        return;
      }
      for(int i = 0; i <= n-1; i++) {
         if (hashlist[i]) {
            temp[index] = nums[i];
            hashlist[i] = false;
            generate(index+1, nums);
            hashlist[i] = true;
         }
      }
    }

   void run() override{
      vector<int> v;
      v.push_back(-2);
      v.push_back(-1);
      v.push_back(0);
      permute(v);
   }
};