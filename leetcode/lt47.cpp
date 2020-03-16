#include<vector>
#include<algorithm>
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include"lt.cpp"
#endif

using namespace std;

// 核心：回溯

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

class lt47 : public lt{
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
       //sort,必须先排序才能剪枝
       sort(nums.begin(), nums.end());
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
             //剪枝以去重
             if (i!= 0 && nums[i-1] == nums[i] && hashlist[i-1])// 剪枝条件：1.此时选中的nums不是开头第一个（因为开头第一个必然不会重复） 2.此时选中的num和同层级上一个选中的nums相同 3.上一个选中的nums还没有被使用，所以才会与本次选中nums产生等效效应
             {
                 continue;
             }
             
            temp[index] = nums[i];
            hashlist[i] = false;
            generate(index+1, nums);
            hashlist[i] = true;
         }
      }
    }

   void run() override{
      vector<int> v;
      v.push_back(2);
      v.push_back(1);
      v.push_back(1);
      permute(v);
   }
};