#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt438 : public lt
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> rlts;
        unordered_map<char, int> smap;
        unordered_map<char, int> pmap;
        for (char c : p)
        {
            ++pmap[c];
        }
        int target_num = pmap.size();
        int left = 0, right = 0, count = 0;
        while (right < s.size())
        {
            char right_c = s[right];
            smap[right_c]++;
            if (pmap[right_c] && pmap[right_c] == smap[right_c])
            {
                count++;
            }
            while (right - left + 1 > p.size())
            {
                char left_c = s[left];
                if (pmap[left_c] && pmap[left_c] == smap[left_c])
                {
                    count--;
                }
                --smap[left_c];
                left++;
            }
            if (count == target_num)
            {
                rlts.push_back(left);
            }
            right++;
        }
        return rlts;
    }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();

        /** test code begin **/
        string s = "cbaebabacd";
        string p = "abc";
        vector<int> rlts = findAnagrams(s, p);
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