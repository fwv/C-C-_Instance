#include <iostream>
#include <algorithm>
#include <vector>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt22 : public lt
{
public:
    vector<string> rlts;

    vector<string> generateParenthesis(int n)
    {
        dfs(n, 0, 0, "");
        return rlts;
    }

    void dfs(int n, int ln, int rn, string rlt)
    {
        if (rlt.size() == n * 2)
        {
            rlts.push_back(rlt);
            return;
        }
        //两条深度递归道路，满足哪边可走哪边，关键难点找出左右放行的条件
        if (ln < n)//左括号小于n就能放
        {
            string r2 = rlt + '(';
            dfs(n, ln + 1, rn, r2);
        }
        if (rn < ln)//右括号小于左括号就能放
        {
            string r2 = rlt + ')';
            dfs(n, ln, rn + 1, r2);
        }
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