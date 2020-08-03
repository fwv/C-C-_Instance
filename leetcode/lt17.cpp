#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt17 : public lt
{
public:
    vector<string> rlts;
    map<char, string> mp;

    vector<string> letterCombinations(string digits)
    {   
        if (0 == digits.size())return rlts;
        
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        dfs(digits, 0, "");
        return rlts;
    }

    void dfs(string digits, int depth, string rlt)
    {   
        if (depth == digits.size())
        {
            rlts.push_back(rlt);
            return;
        }
        
        char c = digits[depth];
        string options = mp[c];
        for (int i = 0; i < options.size(); i++)
        {
            char temp = options[i];
            // rlt += temp; 注意这里string要使用值传递
            string rlt_c = rlt + temp;
            dfs(digits, depth+1, rlt_c);
        }
    }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();

        /** test code begin **/
        letterCombinations("23");
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