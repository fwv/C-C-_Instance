#include <iostream>
#include <algorithm>
#include <stack>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt20 : public lt
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == '{' || c == '[' || c == '(')
            {
                stack.push(c);
            }
            else if (c == '}')
            {
                if (stack.empty())
                    return false;

                char top = stack.top();
                if (top != '{')
                {
                    return false;
                }
                else
                {
                    stack.pop();
                }
            }
            else if (c == ']')
            {
                if (stack.empty())
                    return false;

                char top = stack.top();
                if (top != '[')
                {
                    return false;
                }
                else
                {
                    stack.pop();
                }
            }
            else if (c == ')')
            {
                if (stack.empty())
                    return false;

                char top = stack.top();
                if (top != '(')
                {
                    return false;
                }
                else
                {
                    stack.pop();
                }
            }
        }
        if (stack.empty())
        {
            return true;
        }
        else
        {
            return false;
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