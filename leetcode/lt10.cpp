#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <vector>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

using namespace std;

class lt10 : public lt
{
public:
    //状态机节点结构体
    struct stateNode
    {
        int state; //状态序号 0为开始状态 
        char val;  //状态值 对应p字符串中的char值
        bool isR;  //是否为可变长节点（即后面是否紧跟*字符）
        int firstNotRNextState; //第一个后继非可变长节点状态序号
        stateNode(int _state, char _val, bool _isR) : state(_state), val(_val), isR(_isR) {}
    };

    vector<stateNode> stateNodeList; //状态节点列表
    bool rlt = false; //全局结果

    bool isMatch(string s, string p)
    {
    //1.构造状态机节点列表
        //统计状态数
        int stateNum = 0;
        for (int i = 0; i < p.size(); i++)
        {
            if ('*' != p[i])
                stateNum++;
        }
        //构造开始节点
        stateNode startNode = stateNode(0, -1, false);
        stateNodeList.push_back(startNode);
        int state = 1;
        //构造中间状态节点
        for (int i = 0; i < p.size(); i++)
        {
            if ('*' == p[i])
                continue;
            bool isR;
            if (i + 1 < p.size() && '*' == p[i + 1])
            {
                isR = true;
            }
            else
            {
                isR = false;
            }
            stateNode node = stateNode(state++, p[i], isR);
            stateNodeList.push_back(node);
        }
        //构造结束节点
        stateNode endNode = stateNode(state++, -1, false);
        stateNodeList.push_back(endNode);

        //各个节点的第一个非可变长节点状态序号赋值
        for (int i = 0; i < stateNodeList.size(); i++)
        {
            stateNode *node = &stateNodeList[i];
            node->firstNotRNextState = -1;
            for (int j = node->state + 1; j < stateNodeList.size(); j++)
            {
                stateNode bnode = stateNodeList[j];
                if (!bnode.isR)
                {
                    node->firstNotRNextState = bnode.state;
                    break;
                }
            }
        }

        //2.根据状态机列表构造自动机对应图，权重为输入字符值
        //例如G[0][1]='a'表示当输入为'a'时状态机可从0状态变到1状态,特别标识G[0][1]=-1表示当前输入任意字符状态机可从0状态变到1状态以对应p串中的'.'字符
        vector<vector<int>> G(stateNum + 2, vector<int>(stateNum + 2));
        for (int i = 0; i < stateNodeList.size(); i++)
        {
            stateNode node = stateNodeList[i];
            if (node.isR)
            {
                //可变长节点自己形成环
                if ('.' == node.val)
                {
                    //处理任意输入都匹配的'.'字符
                    G[node.state][node.state] = -1;
                }
                else
                {
                    G[node.state][node.state] = node.val;
                }
            }
            //非可变长节点与后继的所有可变长节点建立状态变化通路
            if (-1 != node.firstNotRNextState)
            {
                for (int i = node.state + 1; i <= node.firstNotRNextState; i++)
                {
                    stateNode middleNode = stateNodeList[i];
                    if ('.' == middleNode.val)
                    {   
                        //处理任意输入都匹配的'.'字符
                        G[node.state][middleNode.state] = -1;
                    }
                    else
                    {
                        G[node.state][middleNode.state] = middleNode.val;
                    }
                }
            }
        }
        //3.开始深度优先遍历回溯，逐个输入s串至自动机以判定是否能够成功达到结束节点
        dfs(s, 0, 0, G);
        return rlt;
    }
    //参数说明 index:s串输入下标 state：当前处理状态序号 G:自动机对应图
    void dfs(string s, int index, int state, vector<vector<int>> &G)
    {
        //递归深度边界控制
        if (index > s.size())
            return;
        int stateNum = stateNodeList.size();
        stateNode curNode = stateNodeList[state];
        //成功边界：s串扫描至末尾时，当前状态节点的第一个非可变长节点为末尾节点
        if (stateNum - 1 == curNode.firstNotRNextState && index == s.size())
        {
            rlt = true;
            return;
        }

        char temp = s[index];
        //遍历当前节点的所有后继子节点
        for (int i = state; i < stateNum; i++)
        {   
            //值匹配或者'.'任意匹配成功
            if (G[state][i] == temp || G[state][i] == -1)
            {
                //进入下一层处理s串中的下一个字符
                dfs(s, index + 1, i, G);
            }
        }
    }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();

        /** test code begin **/
        string s = "";
        string p = "a*b*";
        bool rlt = isMatch(s, p);
        /** test code end **/

        end = getTimeUsec();
        cout << "程序耗时：" << (end - begin) / 1000 << "ms" << endl;
    }
    // //使用动态规划
    // bool isMatch(string s, string p)
    // {
    //     vector<vector<int>> f(s.size(), vector<int>(p.size()));

    //     f[0][0] = isMatch(s[0], p[0]); //边界
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         for (int j = 0; j < p.size(); j++)
    //         {
    //             if (0 == i && 0 == j)
    //                 continue;
    //             if (p[j] == '.')
    //             {
    //                 if (i - 1 < 0 || j - 1 < 0)
    //                 {
    //                     f[i][j] = false;
    //                 }
    //                 else
    //                 {
    //                     f[i][j] = f[i - 1][j - 1];
    //                 }
    //             }
    //             else if (p[j] == '*')
    //             {
    //                 if (j - 1 >= 0)
    //                 {
    //                     if (isMatch(s[i], p[j-1])) //yuejie
    //                     {
    //                         if (i-1>=0)
    //                         {
    //                             f[i][j] = f[i - 1][j] || f[i][j - 1];
    //                         } else
    //                         {
    //                             f[i][j] = f[i][j - 1];
    //                         }
    //                     }
    //                     else
    //                     {
    //                         if (j-2>=0)
    //                         {
    //                             f[i][j] = f[i][j - 2];
    //                         } else
    //                         {
    //                             f[i][j] = false;
    //                         }
    //                     }
    //                 }
    //                 else
    //                 {
    //                     f[i][j] = false;
    //                 }
    //             }
    //             else
    //             {
    //                 if (i - 1 >= 0 && j - 1 >= 0)
    //                 {
    //                     f[i][j] = f[i - 1][j - 1] && (s[i] == p[j]);
    //                 }
    //                 else
    //                 {
    //                     f[i][j] = false;
    //                 }
    //             }
    //         }
    //     }
    //     return f[s.size() - 1][p.size() - 1];
    // }

    // bool isMatch(char a, char b)
    // {
    //     if (b == '.')
    //     {
    //         return true;
    //     }
    //     return a == b;
    // }

    //用状态机的方法，缺回溯过程 待实现
    // bool isMatch(string s, string p)
    // {
    //     //1.判断边界
    //     if (p == ".*")
    //     {
    //         return true;
    //     }

    //     if ("" == s)
    //     {
    //         if (p == "*")
    //         {
    //             return true;
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //     }

    //     int stateNum = p.size();
    //     vector<vector<int>> stateM(stateNum, vector<int>(26));
    //     //2.构造p状态机
    //     for (int i = 0; i < stateNum; i++)
    //     {
    //         if (p[i] != '.' && p[i] != '*')
    //         {
    //             int event = alphabetToInt(p[i]);
    //             //进入下一状态
    //             stateM[i][event] = i + 1;
    //         }
    //         else if (p[i] == '*')
    //         {
    //             //输入与上一个匹配相同，进入本次状态
    //             if (i - 1 >= 0 && '.' != p[i - 1])
    //             {
    //                 int pre_event = alphabetToInt(p[i - 1]);
    //                 stateM[i][pre_event] = i;
    //             }
    //             //输入与下一个匹配相同，进入下一状态
    //             if (i + 1 < stateNum)
    //             {
    //                 //*. 输入任意字符进入下一状态
    //                 if ('.' == p[i + 1])
    //                 {
    //                     for (int j = 0; j <= 25; j++)
    //                     {
    //                         stateM[i][j] = i + 1;
    //                     }
    //                 }
    //                 else
    //                 {
    //                     int next_event = alphabetToInt(p[i + 1]);
    //                     stateM[i][next_event] = i + 1;
    //                 }
    //             }
    //         }
    //         else if (p[i] == '.')
    //         {
    //             //输入任意字符进入下一状态
    //             for (int j = 0; j <= 25; j++)
    //             {
    //                 stateM[i][j] = i + 1;
    //             }
    //         }
    //     }

    //     //开始匹配识别
    //     int curState = 0;
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         int event = alphabetToInt(s[i]);
    //         int preState = curState;
    //         curState = stateM[curState][event];
    //         //状态有折返直接匹配失败
    //         if (curState < preState)
    //         {
    //             return false;
    //         }
    //         //到结尾状态,仍然未匹配完
    //         if (curState == stateNum)
    //         {
    //             if (i != (s.size() - 1))
    //             {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    // int alphabetToInt(char c)
    // {
    //     return c - 97;
    // }
    long getTimeUsec()
    {
        struct timeval t;
        gettimeofday(&t, 0);
        return (long)((long)t.tv_sec * 1000 * 1000 + t.tv_usec);
    }
};