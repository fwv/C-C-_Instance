#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std; 

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
    vector<int> shortRoadNum;
    vector<int> maxScyNum;
    int startCity;
    int endCity;

    scanf("%d %d %d %d", &cityNUm, &roadNum, &startCity, &endCity);
    scyNum = (int*)malloc(sizeof(int)*cityNUm);
    adj = (vector<city>*)malloc(sizeof(vector<city>*)*cityNUm);
    for(int i = 0; i < cityNUm; i++) {
        city c;
        c.v = i;
        c.w = 0;
        adj[i].push_back(c);
    }
    visited = (bool*)malloc(sizeof(bool)*cityNUm);

    for(int i = 0; i < cityNUm; i++) {
        scanf("%d", &scyNum[i]);
    }
    for(int i = 0; i < roadNum; i++) {
        int s,e,w;
        scanf("%d %d %d", &s, &e, &w);
        addEdge(adj, s, e, w);
    }

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