#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std; 
#define INF 9999;

class city{
    public:
        int v;//目标城市编号
        int w;//到目标城市距离
        //int s;//搜救队数量    
};

void addEdge(vector<city>* adj, int start, int end, int w);
void showAdj(vector<city>* adj, int len);
    
void p1003() {
    vector<city>* adj;
    int cityNUm;
    bool* visited;
    int* scyNum; //搜救队数量数组
    int roadNum;
    int* d;//单源最短路径数组
    // vector<int> toEndRoadlens;
    int* maxScyNum;
    int startCity;
    int endCity;
    int* minDisCnt;

    scanf("%d %d %d %d", &cityNUm, &roadNum, &startCity, &endCity);
    //申请内存
    scyNum = (int*)malloc(sizeof(int)*cityNUm);
    d = (int*)malloc(sizeof(int)*cityNUm);
    maxScyNum = (int*)malloc(sizeof(int)*cityNUm);
    adj = (vector<city>*)malloc(sizeof(vector<city>)*cityNUm); 
    visited = (bool*)malloc(sizeof(bool)*cityNUm);
    minDisCnt = (int*)malloc(sizeof(int)*cityNUm);


    for(int i = 0; i < cityNUm; i++) {
            d[i] = INF;     //初始化单源最短距离数组
            maxScyNum[i] = -1;   //初始化单源最快最多搜救队数量数组
            city c;         //邻接表添加头结点
            c.v = i;
            c.w = 0;
            vector<city> v;
            v.push_back(c);
            adj[i] = v;
            visited[i] = false; //初始化访问数组
            minDisCnt[i] = 0;
    } 

    for(int i = 0; i < cityNUm; i++) {
        scanf("%d", &scyNum[i]);
    }
    for(int i = 0; i < roadNum; i++) {
        int s,e,w;
        scanf("%d %d %d", &s, &e, &w);
        addEdge(adj, s, e, w);
    }

    //计算最小路径数量 思路：djiskal单源扫描，遇到目标节点距离d[end]每比较一次记录一次，自己节点不记录
    d[startCity] = 0;
    minDisCnt[startCity] = 1;
    maxScyNum[startCity] = scyNum[startCity];
    //循环N次，构建MST
    for(int i = 0; i < cityNUm; i++) {
        //查找相邻最近节点
        int min = INF;
        int newCity = -1;
        for(int i = 0; i < cityNUm; i++) {
            if(!visited[i] && d[i] < min) {
                min = d[i];
                newCity = i;
            }
        }
        //更新邻节点距离
        vector<city> adjCitys = adj[newCity];
        int size = adjCitys.size();
        visited[newCity] = true;
        for(city c : adjCitys) {
            if (visited[c.v]) {continue;}
            int newDistance = d[newCity] + c.w;
            int newScyNum = maxScyNum[newCity] + scyNum[c.v];
            if(newDistance <= d[c.v]) { //这里不判断是否访问过
                if(newDistance == d[c.v]) {
                    if(newScyNum > maxScyNum[c.v]) {
                        maxScyNum[c.v] = newScyNum;
                    }
                    minDisCnt[c.v] += minDisCnt[newCity];
                } else {
                        maxScyNum[c.v] = newScyNum;
                        minDisCnt[c.v] = minDisCnt[newCity];
                }
                d[c.v] = newDistance;
                
            } else {
                if (-1 == maxScyNum[c.v]) {
                      maxScyNum[c.v] = newScyNum;  
                }
            }
        }
    }
    std::printf("%d %d", minDisCnt[endCity], maxScyNum[endCity]);
}

void addEdge(vector<city>* adj, int start, int end, int w) {
    city c;
    c.v = end;
    c.w = w;
    adj[start].push_back(c);

    city c1;
    c1.v = start;
    c1.w = w;
    adj[end].push_back(c1);
}

void showAdj(vector<city>* adj, int len) {
    int i = 0;
    while(i < len) {
         vector<city> citys = adj[i];
         cout<< " line " << i <<":";
         for(city c : citys) {
               cout<< c.v << " "; 
         }
         cout<< endl;
         i++;   
    }
}

//my answer(partly correct):
/*
void p1003() {
    vector<city>* adj;
    int cityNUm;
    bool* visited;
    int* scyNum; //搜救队数量数组
    int roadNum;
    int* d;//单源最短路径数组
    vector<int> toEndRoadlens;
    int* maxScyNum;
    int startCity;
    int endCity;

    scanf("%d %d %d %d", &cityNUm, &roadNum, &startCity, &endCity);
    //申请内存
    scyNum = (int*)malloc(sizeof(int)*cityNUm);
    d = (int*)malloc(sizeof(int)*cityNUm);
    maxScyNum = (int*)malloc(sizeof(int)*cityNUm);
    adj = (vector<city>*)malloc(sizeof(vector<city>)*cityNUm); 
    visited = (bool*)malloc(sizeof(bool)*cityNUm);

    for(int i = 0; i < cityNUm; i++) {
            d[i] = INF;     //初始化单源最短距离数组
            maxScyNum[i] = -1;   //初始化单源最快最多搜救队数量数组
            city c;         //邻接表添加头结点
            c.v = i;
            c.w = 0;
            vector<city> v;
            v.push_back(c);
            adj[i] = v;
            visited[i] = false; //初始化访问数组
    } 

    for(int i = 0; i < cityNUm; i++) {
        scanf("%d", &scyNum[i]);
    }
    for(int i = 0; i < roadNum; i++) {
        int s,e,w;
        scanf("%d %d %d", &s, &e, &w);
        addEdge(adj, s, e, w);
    }

    //计算最小路径数量 思路：djiskal单源扫描，遇到目标节点距离d[end]每比较一次记录一次，自己节点不记录
    d[startCity] = 0;
    maxScyNum[startCity] = scyNum[startCity];
    //循环N次，构建MST
    for(int i = 0; i < cityNUm; i++) {
        //查找相邻最近节点
        int min = INF;
        int newCity = -1;
        for(int i = 0; i < cityNUm; i++) {
            if(!visited[i] && d[i] < min) {
                min = d[i];
                newCity = i;
            }
        }
        //更新邻节点距离
        vector<city> adjCitys = adj[newCity];
        int size = adjCitys.size();
        for(city c : adjCitys) {
            //跳过头节点
            if (c.v == newCity || visited[c.v]) {continue;}

            int newDistance = d[newCity] + c.w;
            int newScyNum = maxScyNum[newCity] + scyNum[c.v];
            if(newDistance <= d[c.v]) { //这里不判断是否访问过
                if(newDistance == d[c.v]) {
                    if(newScyNum > maxScyNum[c.v]) {
                        maxScyNum[c.v] = newScyNum;
                    }
                } else {
                        maxScyNum[c.v] = newScyNum;
                }
                d[c.v] = newDistance;
                
            } else {
                if (-1 == maxScyNum[c.v]) {
                      maxScyNum[c.v] = newScyNum;  
                }
            }
            //判断比较节点是不是目标节点，且不是自身
            if(endCity == c.v && c.w != 0) {
                toEndRoadlens.push_back(newDistance);
            }
        }
        visited[newCity] = true;
    }
    //统计最小距离路径数量
    int minDis = INF;
    for(int distance : toEndRoadlens) {
        if(distance < minDis){
            minDis = distance;
        }
    }
    int minDisCnt = 0;
    for(int distance : toEndRoadlens) {
        if(distance == minDis){
           minDisCnt++;
        }
    }
  
    int toEndMaxScyNum = maxScyNum[endCity];
    // cout << minDisCnt+" "+toEndMaxScyNum << endl; //不理解为什么输出奇怪的字符
    std::printf("%d %d", minDisCnt, toEndMaxScyNum);
}
*/