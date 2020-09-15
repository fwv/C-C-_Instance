#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <vector>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt39 : public lt
{
public:
    vector<vector<int>> rlts;

    void dfs(vector<int> &candidates, int target, vector<int> &rlt, int lastCandidate)
    {
        vector<int>::iterator it = candidates.begin();
        for (; it != candidates.end(); it++)
        {
            int candidate = *(it);
            if(candidate < lastCandidate)continue;
            rlt.push_back(candidate);
            int newTarget = target - candidate;
            if (!newTarget)
            {
                vector<int> rlt_copy(rlt); 
                rlts.push_back(rlt_copy);
            }
            else if (newTarget > 0)
            {
                dfs(candidates, newTarget, rlt, candidate);
            }
            else
            {
            }
            rlt.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> rlt;
        dfs(candidates, target, rlt, -1);
        return rlts;
    }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();

        /** test code begin **/
        vector<int> can;
        can.push_back(2);
        can.push_back(3);
        can.push_back(6);
        can.push_back(7);
        combinationSum(can, 7);
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