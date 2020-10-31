#include <iostream>
#include <algorithm>
#include <vector>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;
// 4. Median of Two Sorted Arrays
// There are two sorted arrays nums1 and nums2 of size m and n respectively.

// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

// You may assume nums1 and nums2 cannot be both empty.

// Example 1:

// nums1 = [1, 3]
// nums2 = [2]

// The median is 2.0
// Example 2:

// nums1 = [1, 2]
// nums2 = [3, 4]

// The median is (2 + 3)/2 = 2.5
class lt4 : public lt
{
public:

     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthE(nums1, nums2, 0, 0, (totalLength + 1) / 2);
        }
        else {
           return (getKthE(nums1, nums2, 0, 0, totalLength / 2) + getKthE(nums1, nums2, 0, 0,totalLength / 2 + 1)) / 2.0;
        }
    }

    int getKthE(vector<int>& n1, vector<int>& n2, int index1, int index2, int k) {
        int len1 = n1.size();
        int len2 = n2.size();
        if(index1 >= len1)return n2[index2 + k -1];
        if(index2 >= len2)return n1[index1 + k -1];
        if(1==k)return min(n1[index1], n2[index2]);

        int newIndex1 = min(len1-1, index1+k/2-1);
        int newIndex2 = min(len2-1, index2+k/2-1);
        int newk = k;
        if(n1[newIndex1] <= n2[newIndex2]) {
            newk -= newIndex1-index1+1;
            index1 = newIndex1+1;
        } else {
            newk = k - newIndex2-index2+1;
            index2 = newIndex2+1;
        }
        return getKthE(n1, n2, index1, index2, newk);
    }

    double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int k = (m + n) % 2 == 0 ? (m + n) / 2 : (m + n) / 2 + 1;
        //core:双数组二分查找法 寻找2个数组中第k大的元素---》找到A[k/2-1]与B[k/2-1]中的较小者，就能去除0到k/2-1这k/2个较小者，再继续排除k/2个即可。
        int i = 0, j = 0;
        bool is1 = false;
        if (m == 0)
        {
            if (n % 2 == 1)
            {
                return nums2[j + k - 1];
            }
            else
            {
                return (double)(nums2[j + k - 1] + nums2[j + k]) / 2;
            }
        }
        else if (n == 0)
        {
            if (m % 2 == 1)
            {
                return nums1[i + k - 1];
            }
            else
            {
                return (double)(nums1[i + k - 1] + nums1[i + k]) / 2;
            }
        }

        while (k != 1)
        {
            int pivot1 = i + (k / 2 - 1);
            int pivot2 = j + (k / 2 - 1);
            if (pivot1 < m && pivot2 < n)
            {
                if (nums1[pivot1] <= nums2[pivot2])
                {
                    i = pivot1 + 1;
                    is1 = true;
                }
                else
                {
                    j = pivot2 + 1;
                    is1 = false;
                }
                k = k - k / 2;
                if (k == 1 && i == m)
                {
                    is1 = false;
                }
                else if (k == 1 && j == n)
                {
                    is1 = true;
                }
                else if (k == 1 && i < m && j < n)
                {
                    if (nums1[i] <= nums2[j])
                    {
                        is1 = true;
                    }
                    else
                    {
                        is1 = false;
                    }
                }
                else if (k != 1 && i == m)
                {
                    j = j + (k - 1);
                    is1 = false;
                    k = 1;
                }
                else if (k != 1 && j == n)
                {
                    i = i + (k - 1);
                    is1 = true;
                    k = 1;
                }
            }
            else if (pivot1 >= m && pivot2 < n)
            {
                if (nums1[m - 1] > nums2[pivot2])
                {
                    k = k - (pivot2 - j + 1);
                    j = pivot2 + 1;
                    is1 = false;
                }
                else
                {
                    j = j + k - 1 - m;
                    i = m;
                    is1 = false;
                    k = k - (k - 1);
                }
            }
            else if (pivot1 < m && pivot2 >= n)
            {
                if (nums2[n - 1] > nums1[pivot1])
                {
                    k = k - (pivot1 - i + 1);
                    i = pivot1 + 1;
                    is1 = true;
                }
                else
                {
                    i = i + k - 1 - n;
                    j = n;
                    is1 = true;
                    k = k - (k - 1);
                }
            }
        }
        double rlt1, rlt2;
        if (is1)
        {
            rlt1 = nums1[i];
            if ((m + n) % 2 == 1)
            {
                return rlt1;
            }
            else
            {
                if (i + 1 < m && j < n)
                {
                    rlt2 = (double)min(nums1[i + 1], nums2[j]);
                }
                else if (i + 1 >= m && j < n)
                {
                    rlt2 = nums2[j];
                }
                else if (i + 1 < m && j >= n)
                {
                    rlt2 = nums1[i + 1];
                }
                return (rlt1 + rlt2) / 2;
            }
        }
        else
        {
            rlt1 = nums2[j];
            if ((m + n) % 2 == 1)
            {
                return rlt1;
            }
            else
            {
                if (i < m && j + 1 < n)
                {
                    rlt2 = (double)min(nums1[i], nums2[j + 1]);
                }
                else if (i >= m && j + 1 < n)
                {
                    rlt2 = nums2[j + 1];
                }
                else if (i < m && j + 1 >= n)
                {
                    rlt2 = nums1[i];
                }
                return (rlt1 + rlt2) / 2;
            }
        }
    }

    void run() override
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(3);
        // v1.push_back(2);
        // v1.push_back(5);
        // v1.push_back(6);

        vector<int> v2;
        v2.push_back(2);
        v2.push_back(7);
        // v2.push_back(2);
        // v2.push_back(3);
        // // v2.push_back(4);
        // v2.push_back(5);
        // v2.push_back(6);
        // v2.push_back(7);
        // v2.push_back(8);

        double rlt = findMedianSortedArrays(v1, v2);
        cout << endl;
    }
};