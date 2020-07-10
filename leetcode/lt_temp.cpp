#include <iostream>
#include <algorithm>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt_temp : public lt
{
public:

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();
        // code
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