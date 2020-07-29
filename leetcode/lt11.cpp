#include <iostream>
#include <algorithm>
#include <vector>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt11 : public lt
{
public:
    int maxArea(vector<int> &height)
    {
        int maxW = -1;
        int l = 0, h = height.size() - 1;
        while (l < h)
        {
            int w = min(height[l], height[h]) * (h - l);
            maxW = w > maxW ? w : maxW;
            if (height[l] <= height[h])
            {
                l++;
            }
            else
            {
                h--;
            }
        }
        return maxW;
    }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();

        /** test code begin **/

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