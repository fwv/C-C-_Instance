#include <iostream>
#include <algorithm>
#include <vector>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt33 : public lt
{
public:
    int search(vector<int> &nums, int target)
    {
        int len = nums.size();
        if (0 == len)
            return -1;
        if (1 == len)
            return target == nums[0] ? 0 : -1;
        int l = 0, r = len - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] >= nums[0])
            {
                if (target >= nums[0] && nums[mid] > target)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else if (nums[mid] < nums[len-1])
            {
                if (target <= nums[len - 1] && nums[mid] < target)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
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