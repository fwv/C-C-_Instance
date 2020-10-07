#include <iostream>
#include <algorithm>
#include <vector>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt75 : public lt
{
public:
    //荷兰国旗问题，双指针解决
    void sortColors(vector<int> &nums)
    {
        int p0 = 0, p1 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (0 == nums[i])
            {
                if (p1 > p0)
                {
                    swap(nums[i], nums[p0]); //这里有可能把1换出了，然后变成了00002221这种情况
                    swap(nums[i], nums[p1]);
                    p0++;
                    p1++;
                } else
                {
                    swap(nums[i], nums[p0]);
                    p0++;
                    p1++;
                }
                
            }
            else if (nums[i] == 1)
            {
                swap(nums[i], nums[p1++]);
            }
        }
    }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();

        /** test code begin **/
        vector<int> rlts;
        rlts.push_back(2);
        rlts.push_back(0);
        rlts.push_back(2);
        rlts.push_back(1);
        rlts.push_back(1);
        rlts.push_back(0);
        sortColors(rlts);
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