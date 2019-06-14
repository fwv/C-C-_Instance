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
    adj = (vector<city>*)malloc(sizeof(vector<city>*)*cityNUm);
    visited = (bool*)malloc(sizeof(bool)*cityNUm);

    for(int i = 0; i < cityNUm; i++) {
            d[i] = INF;     //初始化单源最短距离数组
            maxScyNum[i] = -1;   //初始化单源最大搜救队数量数组
            city c;         //邻接表添加头结点
            c.v = i;
            c.w = 0;
            adj[i].push_back(c);
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
        for(city c : adjCitys) {
            int newDistance = d[newCity] + c.w;
            if(newDistance < d[c.v]) { //这里不判断是否访问过
                d[c.v] = newDistance;
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

    for(int i = 0; i < cityNUm; i++) {
        visited[i] = false;
    }
    //计算最大搜救队集结数量（思路：djiskal单源扫描，以城市搜救队数量为权重，取大）
    maxScyNum[startCity] = scyNum[startCity];
    //循环n次 prim构建MST
    for(int i = 0; i < cityNUm; i++) {
        //查找权重最大的邻接未访问节点
        int c = -1; 
        int maxScyCnt = 0;
        for (int i = 0; i < cityNUm; i++)
        {
            if(!visited[i] && scyNum[i] > maxScyCnt) {
                maxScyCnt = scyNum[i];
                c = i;
            }
        }
        //更新新节点的距离信息
        vector<city> citys = adj[c];
        for(city adj_c : citys) {
            if(scyNum[adj_c.v] + maxScyNum[c] > maxScyNum[adj_c.v]) {
                 maxScyNum[adj_c.v] = scyNum[adj_c.v] + maxScyNum[c];
            } 
        }
        visited[c] = true;
    }
    int toEndMaxScyNum = maxScyNum[endCity];
    cout << minDisCnt+" "+toEndMaxScyNum << endl;
}

void addEdge(vector<city>* adj, int start, int end, int w) {
    vector<city> v = adj[start];
    city c1;
    c1.v = end;
    c1.w = w;
    v.push_back(c1);

    vector<city> v1 = adj[end];
    city c2;
    c2.v = start;
    c2.w = w;
    v.push_back(c2);
}