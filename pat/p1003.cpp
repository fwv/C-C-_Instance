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
    vector<int> maxScyNum;
    int startCity;
    int endCity;

    scanf("%d %d %d %d", &cityNUm, &roadNum, &startCity, &endCity);
    scyNum = (int*)malloc(sizeof(int)*cityNUm);
    d = (int*)malloc(sizeof(int)*cityNUm);
    for(int i = 0; i < cityNUm; i++) {
            d[i] = INF;
    }
    adj = (vector<city>*)malloc(sizeof(vector<city>*)*cityNUm);
    for(int i = 0; i < cityNUm; i++) {
        city c;
        c.v = i;
        c.w = 0;
        adj[i].push_back(c);
    }
    visited = (bool*)malloc(sizeof(bool)*cityNUm);
    for(int i = 0; i < cityNUm; i++) {
            visited[i] = false;
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
        //查找最近节点
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
            if(newDistance < d[c.v]) {
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