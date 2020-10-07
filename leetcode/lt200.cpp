#include <iostream>
#include <algorithm>
#include <vector>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif
using namespace std;

class lt200 : public lt
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int row = grid.size();
        if(0==row)return 0;
        int colume = grid[0].size();
        int len = row * colume;
        vector<int> father(len);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < colume; j++)
            {
                int no = getNo(i, j, row, colume);
                char c = grid[i][j];
                if ('1' == c)
                {
                    father[no] = no;
                }
                else
                {
                    father[no] = -1;
                }
            }
        }

        for (int i = 0; i < father.size(); i++)
        {
            int no = i;
            int r = no / colume;
            int c = no % colume;
            if ('1' == grid[r][c])
            {
                if (0 <= c - 1 && c - 1 < colume)
                {
                    if (grid[r][c - 1] == '1')
                    {
                        unionP(father, no, getNo(r, c - 1, row, colume));
                    }
                }
                if (0 <= c + 1 && c + 1 < colume)
                {
                    if (grid[r][c + 1] == '1')
                    {
                        unionP(father, no, getNo(r, c + 1, row, colume));
                    }
                }
                if (0 <= r - 1 && r - 1 < row)
                {
                    if (grid[r - 1][c] == '1')
                    {
                        unionP(father, no, getNo(r - 1, c, row, colume));
                    }
                }
                if (0 <= r + 1 && r + 1 < row)
                {
                    if (grid[r + 1][c] == '1')
                    {
                        unionP(father, no, getNo(r + 1, c, row, colume));
                    }
                }
            }
        }
        int rlt = 0;
        vector<int> hashT(father.size());
        for (int i = 0; i < father.size(); i++)
        {
            if (father[i] != -1)
            {
                hashT[findFather(father, father[i])] = true;
            }
        }
        for (int i = 0; i < father.size(); i++)
        {
            if (hashT[i])
            {
                rlt++;
            }
        }

        return rlt;
    }

    int getNo(int i, int j, int row, int colume)
    {
        return i * colume + j;
    }

    int findFather(vector<int>& father, int a)
    {
        int x = a;
        while (a != father[a])
        {
            a = father[a];
        }
        //压缩路径
        while (x != father[x])
        {
            int z = father[x];
            father[x] = a;
            x = z;
        }

        return a;
    }

    void unionP(vector<int> &father, int p1, int p2)
    {
        int fp1 = findFather(father, p1);
        int fp2 = findFather(father, p2);
        if (fp1 != fp2)
        {
            father[fp1] = fp2;
        }
    }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();

        /** test code begin **/
        vector<vector<char>> g(4, vector<char>(5));
        g[0][0] = '1';
        g[0][1] = '1';
        g[0][2] = '1';
        g[0][3] = '1';
        g[0][4] = '0';

        g[1][0] = '1';
        g[1][1] = '1';
        g[1][2] = '0';
        g[1][3] = '1';
        g[1][4] = '0';

        g[2][0] = '1';
        g[2][1] = '1';
        g[2][2] = '0';
        g[2][3] = '0';
        g[2][4] = '0';

        g[3][0] = '0';
        g[3][1] = '0';
        g[3][2] = '0';
        g[3][3] = '0';
        g[3][4] = '0';

        int rlt = numIslands(g);
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