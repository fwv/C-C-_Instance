#include<vector>
#include<string>
#include<algorithm>
#include<sstream>

#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include"lt.cpp"
#endif

using namespace std;
// The set [1,2,3,...,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Note:

// Given n will be between 1 and 9 inclusive.
// Given k will be between 1 and n! inclusive.
// Example 1:

// Input: n = 3, k = 3
// Output: "213"

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/permutation-sequence

class lt60 : public lt {
public:
    int range;
    int rlt[99];
    int rlt_len;
    bool used[99];
    int seq;
    int seq_now = 0;
    string rlt_string;

    string getPermutation(int n, int k) {
        rlt_len = n;
        range = n;
        seq = k;
        for (int i = 1; i < range; i++)
        {
            used[i] = false;
        }
        dfs(1);
        return rlt_string;
    }

    void dfs(int depth) {
        if (depth == rlt_len + 1)
        {  
            if (++seq_now == seq)
            {
            //输出结果字符串
             for (int i = 1; i <= rlt_len; i++)
             {
                 int& temp = rlt[i];
                 rlt_string += IntToString(temp);
             }
            }
            
            return;
        }

        for (int i = 1; i <= range; i++)
        {
            if (!used[i])
            {
                rlt[depth] = i;
                used[i] = true;
                dfs(depth+1);
                used[i] = false;
            }
            
        }
        
    }


    string IntToString(int & i)
    {
    string s;
    stringstream ss(s);
    ss<<i;
    return ss.str();
    }

    void run() override{
      getPermutation(3,3);
   }

};