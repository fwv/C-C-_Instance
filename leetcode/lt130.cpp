#include <iostream>
#include <algorithm>
#include <vector>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt130 : public lt
{
public:
    void solve(vector<vector<char>> &board)
    {
        int row = board.size();
        if (0 == row)
            return;
        int colume = board[0].size();
        int len = row * colume;
        vector<int> father(len);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < colume; j++)
            {
                int no = colume * i + j;
                if (board[i][j] == 'O')
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
            if ('O' == board[r][c])
            {
                if (0 <= c - 1 && c - 1 < colume && 'O' == board[r][c - 1])
                {
                    unionP(father, no, colume * r + c - 1);
                }
                if (0 <= c + 1 && c + 1 < colume && 'O' == board[r][c + 1])
                {
                    unionP(father, no, colume * r + c + 1);
                }
                if (0 <= r - 1 && r - 1 < row && 'O' == board[r - 1][c])
                {
                    unionP(father, no, colume * (r - 1) + c);
                }
                if (0 <= r + 1 && r + 1 < row && 'O' == board[r + 1][c])
                {
                    unionP(father, no, colume * (r + 1) + c);
                }
            }
        }

        for (int i = 0; i < father.size(); i++)
        {
            int no = i;
            int r = no / colume;
            int c = no % colume;
            if (board[r][c] == 'O')
                father[i] = findF(father, i);
        }

        for (int i = 0; i < father.size(); i++)
        {
            int root = father[i];
            int no = i;
            int r = no / colume;
            int c = no % colume;
            if ('O' == board[r][c] && (0 == r || row - 1 == r || 0 == c || colume - 1 == c))
            {
                for (int j = 0; j < father.size(); j++)
                {
                    if (father[j] == root)
                        father[j] = -1;
                }
            }
        }

        for (int i = 0; i < father.size(); i++)
        {
            int no = i;
            int r = no / colume;
            int c = no % colume;
            if (father[no] != -1)
            {
                board[r][c] = 'X';
            }
        }
    }
    int findF(vector<int> &father, int x)
    {
        int a = x;
        while (x != father[x])
        {
            x = father[x];
        }
        //compose
        while (a != father[a])
        {
            int z = father[a];
            father[a] = x;
            a = z;
        }

        return x;
    }

    void unionP(vector<int> &father, int x, int y)
    {
        int fx = findF(father, x);
        int fy = findF(father, y);
        if (fx != fy)
        {
            father[fy] = fx;
        }
    }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();

        /** test code begin **/
        vector<vector<char>> g(6, vector<char>(20));
        g[0][0] = 'X';
        g[0][1] = 'X';
        g[0][2] = 'X';
        g[0][3] = 'X';
        g[0][4] = 'X';
        g[0][5] = 'X';
        g[0][6] = 'X';
        g[0][7] = 'X';
        g[0][8] = 'X';
        g[0][9] = 'X';
        g[0][10] = 'X';
        g[0][11] = 'X';
        g[0][12] = 'X';
        g[0][13] = 'X';
        g[0][14] = 'X';
        g[0][15] = 'X';
        g[0][16] = 'X';
        g[0][17] = 'X';
        g[0][18] = 'X';
        g[0][19] = 'X';

        g[1][0] = 'X';
        g[1][1] = 'X';
        g[1][2] = 'X';
        g[1][3] = 'X';
        g[1][4] = 'X';
        g[1][5] = 'X';
        g[1][6] = 'X';
        g[1][7] = 'X';
        g[1][8] = 'X';
        g[1][9] = 'O';
        g[1][10] = 'O';
        g[1][11] = 'O';
        g[1][12] = 'X';
        g[1][13] = 'X';
        g[1][14] = 'X';
        g[1][15] = 'X';
        g[1][16] = 'X';
        g[1][17] = 'X';
        g[1][18] = 'X';
        g[1][19] = 'X';

        g[2][0] = 'X';
        g[2][1] = 'X';
        g[2][2] = 'X';
        g[2][3] = 'X';
        g[2][4] = 'X';
        g[2][5] = 'O';
        g[2][6] = 'O';
        g[2][7] = 'O';
        g[2][8] = 'X';
        g[2][9] = 'O';
        g[2][10] = 'X';
        g[2][11] = 'O';
        g[2][12] = 'X';
        g[2][13] = 'X';
        g[2][14] = 'X';
        g[2][15] = 'X';
        g[2][16] = 'X';
        g[2][17] = 'X';
        g[2][18] = 'X';
        g[2][19] = 'X';
        
        g[3][0] = 'X';
        g[3][1] = 'X';
        g[3][2] = 'X';
        g[3][3] = 'X';
        g[3][4] = 'X';
        g[3][5] = 'O';
        g[3][6] = 'X';
        g[3][7] = 'O';
        g[3][8] = 'X';
        g[3][9] = 'O';
        g[3][10] = 'X';
        g[3][11] = 'O';
        g[3][12] = 'O';
        g[3][13] = 'O';
        g[3][14] = 'X';
        g[3][15] = 'X';
        g[3][16] = 'X';
        g[3][17] = 'X';
        g[3][18] = 'X';
        g[3][19] = 'X';

        g[4][0] = 'X';
        g[4][1] = 'X';
        g[4][2] = 'X';
        g[4][3] = 'X';
        g[4][4] = 'X';
        g[4][5] = 'O';
        g[4][6] = 'X';
        g[4][7] = 'O';
        g[4][8] = 'O';
        g[4][9] = 'O';
        g[4][10] = 'X';
        g[4][11] = 'X';
        g[4][12] = 'X';
        g[4][13] = 'X';
        g[4][14] = 'X';
        g[4][15] = 'X';
        g[4][16] = 'X';
        g[4][17] = 'X';
        g[4][18] = 'X';
        g[4][19] = 'X';

        g[5][0] = 'X';
        g[5][1] = 'X';
        g[5][2] = 'X';
        g[5][3] = 'X';
        g[5][4] = 'X';
        g[5][5] = 'O';
        g[5][6] = 'X';
        g[5][7] = 'X';
        g[5][8] = 'X';
        g[5][9] = 'X';
        g[5][10] = 'X';
        g[5][11] = 'X';
        g[5][12] = 'X';
        g[5][13] = 'X';
        g[5][14] = 'X';
        g[5][15] = 'X';
        g[5][16] = 'X';
        g[5][17] = 'X';
        g[5][18] = 'X';
        g[5][19] = 'X';

        solve(g);

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