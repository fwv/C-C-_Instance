#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt76 : public lt
{
public:
    int count = 0;
    unordered_map<char, int> tmap;
    unordered_map<char, int> smap;
    int rlt_len = 999999;
    string rlt = "";
    bool isLeft = false;
    string minWindow(string s, string t)
    {
        int left = 0, right = 0;
        int target_num = t.size();
        for (char c : t)
        {
            ++tmap[c];
        }
        while (right < s.size())
        {
            if (isLeft)
            {
                --smap[s[left-1]];
                char temp = s[left - 1];
                if (tmap[temp] && smap[temp] < tmap[temp])
                {
                    count--;
                }
            }
            else
            {
                char temp = s[right];
                ++smap[temp];
                if (tmap[temp] && smap[temp] <= tmap[temp])
                {
                    count++;
                }
            }
            if (count == target_num)
            {
                isLeft = true;
                if (right - left + 1 < rlt_len)
                {
                    rlt_len = right - left + 1;
                    rlt = s.substr(left, rlt_len);
                }
                left++;
            }
            else
            {
                isLeft = false;
                right++;
            }
        }
        return rlt;
    }

    //right answer
    // string minWindow(string s, string t)
    // {
    //     int left = 0, right = 0;
    //     int target_num = t.size();
    //     for (char c : t)
    //     {
    //         ++tmap[c];
    //     }
    //     while (right < s.size())
    //     {
    //         char right_c = s[right];
    //         ++smap[right_c];
    //         if (tmap[right_c] && smap[right_c] <= tmap[right_c]){
    //             count++;
    //         }
    //         if (count == target_num)
    //         {
    //             if (right - left + 1 < rlt_len)
    //             {
    //                 rlt_len = right - left + 1;
    //                 rlt = s.substr(left, right - left + 1);
    //             }
    //             while (left <= right && count == target_num)
    //             {
    //                 if (right - left + 1 < rlt_len)
    //                 {
    //                     rlt_len = right - left + 1;
    //                     rlt = s.substr(left, right - left + 1);
    //                 }
    //                 char left_c = s[left];
    //                 if (tmap[left_c] && smap[left_c] <= tmap[left_c])
    //                 {
    //                     count--;
    //                 }
    //                 --smap[left_c];
    //                 left++;
    //             }
    //         }
    //         right++;
    //     }
    //     return rlt;
    // }

    // string minWindow(string s, string t)
    // {
    //     int left = 0, right = 0;
    //     int target_num = t.size();
    //     bool left_modify = false;
    //     for (char c : t)
    //     {
    //         ++tmap[c];
    //     }
    //     while (right < s.size())
    //     {
    //         if (count == target_num)
    //         {

    //             if (tmap[s[left]] && smap[s[left]] <= tmap[s[left]])
    //             {
    //                 count--;
    //             }
    //             left++;
    //             left_modify = true;
    //             smap[s[left]]--;
    //         }
    //         else
    //         {

    //             right++;
    //             left_modify = false;
    //             smap[s[right]]--;
    //         }
    //     }
    //     return rlt;
    // }

    //超时答案，没有画出流程图，初步估算一下时间复杂度为O(n^2)，第一次在实践中了解算法分析的重要性
    // string minWindow(string s, string t)
    // {
    //     if (s.size() < t.size())
    //         return "";
    //     int rlt = 999999;
    //     int start = -1;
    //     int right = 0, left = 0;
    //     while (left < s.size() && right < s.size())
    //     {
    //         string sub = s.substr(left, right - left + 1);
    //         bool isC = isContain(sub, t);
    //         if (!isC)
    //         {
    //             while (right < s.size())
    //             {
    //                 string sub2 = s.substr(left, right - left + 1);
    //                 if (isContain(sub2, t))
    //                 {
    //                     if (right - left + 1 < rlt)
    //                     {
    //                         rlt = right - left + 1;
    //                         start = left;
    //                     }
    //                     break;
    //                 }
    //                 right++;
    //             }
    //         }
    //         else
    //         {
    //             if (right - left + 1 < rlt)
    //             {
    //                 rlt = right - left + 1;
    //                 start = left;
    //             }
    //             left++;
    //         }
    //     }
    //     return (-1 == start) ? "" : s.substr(start, rlt);
    // }

    // bool isContain(string s, string t)
    // {
    //     if (s.size() < t.size())
    //         return false;
    //     vector<char> vc;
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         char c = s[i];
    //         vc.push_back(c);
    //     }
    //     for (int i = 0; i < t.size(); i++)
    //     {
    //         vector<char>::iterator isElment = find(vc.begin(), vc.end(), t[i]);
    //         if (isElment == vc.end())
    //         {
    //             return false;
    //         }
    //         else
    //         {
    //             vc.erase(isElment);
    //         }
    //     }
    //     return true;
    // }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();

        /** test code begin **/
        string s = "ADOBECODEBANC";
        string t = "ABC";
        string rlt = minWindow(s, t);
        /** test code end **/

        end = getTimeUsec();

        cout << "程序耗时：" << (end - begin) / 1000 << "ms" << endl;
    }

    long getTimeUsec()
    {
        struct timeval t;
        gettimeofday(&t, 0);
        return (long)((long)t.tv_sec * 1000 * 1000 + t.tv_usec);
    }
};