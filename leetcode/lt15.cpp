#include <iostream>
#include <algorithm>
#include <vector>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt_temp : public lt
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> rlt;
        for (int first = 0; first < len - 2; first++)
        {
            int target = -nums[first];
            int third = len - 1; //精髓所在 第三指针不回头 确保时杂O(n)
            for (int second = first + 1; second < len - 1; second++)
            {
                if (second == first + 1 || nums[second - 1] != nums[second])
                {
                    while (nums[second] + nums[third] > target && second < third)
                    {
                        third--;
                    }
                    if (target == nums[second] + nums[third])
                    {
                        vector<int> temp;
                        temp.push_back(nums[first]);
                        temp.push_back(nums[second]);
                        temp.push_back(nums[third]);
                        rlt.push_back(temp);
                    }
                }
            }
        }
        return rlt;
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