#include <iostream>
#include <algorithm>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt32 : public lt
{
public:
    int longestValidParentheses(string s)
    {
        int len = s.size();
        if (len == 0)
            return 0;
        int dp[len];
        fill(dp, dp + len, 0);
        int maxLen = 0;
        for (int i = 1; i < len; i++)
        {
            if (s[i] == '(')
            {
                dp[i] = 0;
                continue;
            }
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = (i > 2 ? dp[i - 2] : 0) + 2;
                    maxLen = dp[i] > maxLen ? dp[i] : maxLen;
                }
                else if (s[i - 1] == ')')
                {   
                    int matchIndex = s[i - 1 - dp[i - 1]];
                    if (matchIndex>=0 && s[matchIndex] == '(')
                    {
                        dp[i] = (matchIndex - 1 >= 0 ? dp[matchIndex - 1] : 0) + dp[i - 1] + 2;
                        maxLen = dp[i] > maxLen ? dp[i] : maxLen;
                    }
                    else
                    {
                        dp[i] = 0;
                        maxLen = dp[i] > maxLen ? dp[i] : maxLen;
                    }
                }
            }
        }
        return maxLen;
    }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();
        /** test code begin **/
        string s = ")()())";
        int rlt = longestValidParentheses(s);
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