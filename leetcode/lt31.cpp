#include <iostream>
#include <algorithm>
#include <vector>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt31 : public lt
{
public:
    void nextPermutation(vector<int> &nums)
    {
        //使用数制中进位的思想 1.找到落点 2.使用最近大者替换落点 3.逆置落点后的值保证最小
        int fallIndex = -1;
        for (int i = nums.size() - 2; i > -1; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                fallIndex = i;
                break;
            }
        }
        if (-1 == fallIndex)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int p = fallIndex + 1, pre;
        while (p <= nums.size() - 1 && nums[p] > nums[fallIndex])
        {
            pre = p;
            p++;
        }
        //swap
        int temp = nums[fallIndex];
        nums[fallIndex] = nums[pre];
        nums[pre] = temp;
        //reverse
        reverse(nums.begin() + fallIndex + 1, nums.end());
    }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();

        /** test code begin **/
        vector<int> nums;
        nums.push_back(3);
        nums.push_back(2);
        nums.push_back(1);
        nextPermutation(nums);
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