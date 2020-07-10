#include <iostream>
#include <algorithm>
#include <vector>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt5 : public lt
{
public:
    bool isR[1000][1000];
    string max;

    string longestPalindrome(string s)
    {
        //边界
        if (s.empty())
        {
            return s;
        }

        //dp:构造回文检测结果集
        int len = s.size();
        for (int k = 0; k < len; k++)
        {
            for (int i = 0; i < len; i++)
            {
                int j = i + k;
                if (j > len - 1)
                    continue;
                if (i == j || (k == 1 && s[i] == s[j]))
                {
                    isR[i][j] = true;
                }
                else
                {
                    isR[i][j] = (s[i]==s[j] && isR[i+1][j-1]);
                }
                if (isR[i][j]&&((j - i + 1) > max.size()))
                {
                    max = s.substr(i, j - i + 1);
                }
            }
        }

        return max;
    }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();

        string s = "ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
        string rlt = longestPalindrome(s);

        end = getTimeUsec();
        cout << "程序耗时：" << (end - begin) / 1000 << "ms" << endl;
        cout << rlt << endl;
    }

    long getTimeUsec()
    {
        struct timeval t;
        gettimeofday(&t, 0);
        return (long)((long)t.tv_sec * 1000 * 1000 + t.tv_usec);
    }
};