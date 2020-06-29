#include <iostream>
#include <algorithm>
#include <unordered_set>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

// 3. Longest Substring Without Repeating Characters
// Given a string, find the length of the longest substring without repeating characters.

// Example 1:

// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 

class lt3 : public lt
{
public:
    int rlt = 0;
    int rk = 0;
    unordered_set<char> hashset;
    int lengthOfLongestSubstring(string s)
    {
       // 采用滑动窗口思维解题 O(n) 右边指针不会折返
        int n = s.size();
        for (int i = 0; i < n; i++)
        {   
            if(i > 0) {
                hashset.erase(s[i-1]);
            }
            while (rk < n && hashset.end() == hashset.find(s[rk]))
            {
                hashset.insert(s[rk]);
                rk++;
            }
            rlt = max(rlt, rk - i);
        }
        return rlt;
    }

    void run() override
    {
         string s = "abca";
         int rlt = lengthOfLongestSubstring(s);
    }
};