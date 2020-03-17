#include<vector>
#include<string>
#include<algorithm>
#include<sstream>

#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include"lt.cpp"
#endif

// 77. Combinations
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// Example:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/combinations
class lt77 : public lt{
public:
    int range;
    int rlt_len;
    bool used[99];
    int rlt[99];
    vector<vector<int>> rlt_v;

    vector<vector<int>> combine(int n, int k) {
        //初始化数据
        range = n;
        rlt_len = k;
        for (int i = 1; i <= range; i++)
        {
            used[i] = false;
        }
        dfs(1, 0);
        return rlt_v;
    }

    void dfs(int depth, int pre_rlt) {
        if (depth == rlt_len+1)
        {
            vector<int> temp;
            for (int i = 1; i <= rlt_len; i++)
            {
                temp.push_back(rlt[i]);
            }
            rlt_v.push_back(temp);
            return;
        }
        for (int i = 1; i <= range; i++)
        {
            if (!used[i] && i > pre_rlt)
            {
                rlt[depth] = i;
                used[i] = true;
                dfs(depth+1, i);
                used[i] = false;
            }
        }
        
    }

    

    void run() override{
        combine(4,2);
   }
};