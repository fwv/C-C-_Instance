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

class lt567 : public lt
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> s1map;
        unordered_map<char, int> s2map;
        for (char c : s1)
        {
            ++s1map[c];
        }
        int count = 0, target_num = s1map.size();
        int left = 0, right = 0;
        while (right < s2.size())
        {
            char right_c = s2[right];
            ++s2map[right_c];
            if (s1map[right_c] && s1map[right_c] == s2map[right_c])
            {
                count++;
            }
            while (right - left + 1 > s1.size())
            {
                char left_c = s2[left];
                if (s1map[left_c] && (s1map[left_c] == s2map[left_c]))
                {
                    count--;
                }
                --s2map[left_c];
                left++;
            }
            if (count == target_num)
            {
                return true;
            }
            right++;
        }
        return false;
    }

    //wrong answer
    // bool checkInclusion(string s1, string s2)
    // {
    //     unordered_map<char, int> s1map;
    //     unordered_map<char, int> s2map;
    //     for (char c : s1)
    //     {
    //         ++s1map[c];
    //     }
    //     int count = 0, target_num = s1.size();
    //     int left = 0, right = 0;
    //     while (right < s2.size())
    //     {
    //         if (left == right)
    //         {
    //             cout << "" << endl;
    //         }

    //         char right_c = s2[right];
    //         ++s2map[right_c];
    //         if (s1map[right_c] && s2map[right_c] <= s1map[right_c])
    //         {
    //             count++;
    //             if (count == target_num)
    //             {
    //                 return true;
    //             }
    //         }
    //         else
    //         {
    //             char left_c = s2[left];
    //             if (s1map[right_c])
    //             {
    //                 if (left_c == right_c)
    //                 {
    //                     if (s2map[left_c] <= s1map[left_c] + 1)
    //                     {
    //                         --s2map[s2[left]];
    //                         left++;
    //                     }
    //                 }
    //                 else
    //                 {
    //                     while (left < right)
    //                     {
    //                         --s2map[s2[left]];
    //                         left++;
    //                     }
    //                     count = 1;
    //                 }
    //             }
    //             else
    //             {
    //                 while (left <= right)
    //                 {
    //                     --s2map[s2[left]];
    //                     left++;
    //                 }
    //                 count = 0;
    //             }
    //         }
    //         right++;
    //     }
    //     return false;
    // }

    bool checkInclusion1(string s1, string s2)
    {
        int m[128] = {0};
        int left = 0, right = 0, need = 0;
        for (char c : s1)
            m[c]++;
        while (right < s2.size())
        {
            if (m[s2[right]] > 0)
                ++need;
            --m[s2[right]];
            ++right;
            while (need == s1.size())
            {
                if (right - left == s1.size())
                {
                    cout << left << endl;
                    cout << s2.substr(left, right - left + 1);
                    return true;
                }
                if (m[s2[left]] == 0)
                    --need;
                ++m[s2[left]];
                ++left;
            }
        }
        return false;
    }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();

        /** test code begin **/
        string s1 = "abcabe";
        string s2 = "abeabc";
        bool rlt = checkInclusion(s1, s2);
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