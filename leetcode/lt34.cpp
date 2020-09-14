#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <vector>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;
// 34. Find First and Last Position of Element in Sorted Array
// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class lt34 : public lt
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> a(2);
        a[0] = -1;
        a[1] = -1;
        int len = nums.size();
        if (0 == len)
            return a;
        a[0] = searchExtremelyElement(nums, target, 0, len - 1, true);
        a[1] = searchExtremelyElement(nums, target, 0, len - 1, false);
        return a;
    }

    int searchExtremelyElement(vector<int> &nums, int target, int low, int high, bool isleft)
    {
        while (low < high)
        {
            int mid = (low + high) >> 1;
            if (nums[mid] == target) //二分法找到元素时，需要区分此时查找极端值的方向
            {
                if (isleft)//找最左元素时，直接缩小区间到[low,mid]
                {
                    high = mid;
                }
                else    //查找最右元素时，因为二分法取mid时具有趋左性，故而当low与high相邻时如果low命中的话会陷入死循环，故而不能简单的将区间缩小为[mid，high]
                {
                    if (mid == low && target != nums[high]) //low与high相邻且high未命中，缩小区间为[low,high-1]或者[low,mid+1]
                    {
                        high--;
                    }
                    else if (mid == low && target == nums[high])//low与high相邻且high命中，缩小区间为[low+1,high]或者[mid+1,high]
                    {
                        low++;
                    }
                    else //如不相邻则缩小为[mid,high]
                    {
                        low = mid;
                    }
                }
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
        }
        if (nums[low] == target)
        {
            return low;
        }
        else
        {
            return -1;
        }
    }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();

        /** test code begin **/
        vector<int> nums;
        nums.push_back(5);
        nums.push_back(7);
        nums.push_back(7);
        nums.push_back(8);
        searchRange(nums, 7);
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