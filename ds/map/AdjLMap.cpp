#include<iostream>
#include<vector>
#include"Map.cpp"
#include"Node.cpp"
using namespace std;
#define INF 9999;

void adjl_map_instance();

class AdjLMap : public Map {
    public:
        //节点数
        int N;
        //访问记录数组
        bool *visited;
        //单元距离数组
        int *d;
        //邻接表
        vector<Node> *adj;

        AdjLMap(int _N) {
            N = _N;
            visited = (bool *)malloc(_N*sizeof(bool));
            d = (int*)malloc(N*sizeof(int));
            adj = (vector<Node>*)malloc(_N*sizeof(vector<Node>));  
            for(int i = 0; i < _N; i++) {
                Node* node = new Node(i, 0);
                adj[i].push_back(* node);
                visited[i] = false;
                d[i] = INF;
            }
        } 

        AdjLMap(){}

        ~AdjLMap(){}

        void addEdge(int node1, int node2, int w);

        void dfs(int sp);

        void dfs_travel();

        void dijkstra(int sp);

    private:
};     

void AdjLMap::addEdge(int node1, int node2, int w) {
    Node* newNode = new Node(node2, w);
    adj[node1].push_back(*newNode);
}


void AdjLMap::dfs(int sp) {
    vector<Node> nodes = adj[sp];
    for(int i = 0; i < nodes.size(); i++) {
        Node node = nodes[i];
        if(!visited[node.v]) {
            node.visit();
            visited[node.v] = true;
            dfs(node.v);
        }
    }
}

void AdjLMap::dfs_travel() {
    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

void AdjLMap::dijkstra(int sp) {
    if(sp >= N) {
        cout<<"输入节点非法"<<endl;
    } 
    d[sp] = 0;
    //visited[sp] = true;
    //N次循环以后MST形成
    for(int i = 0; i < N; i++) {
        int u = -1,MIN = INF;
        //N次循环以后选出候选节点
        for(int j = 0; j < N; j++) {
            if(!visited[j] && d[j] < MIN) {
                    u = j;
                    MIN = d[j];
            }
        }
        //不存在未访问且距离最小节点（与sp节点不连通）
        if(-1 == u) return;
        visited[u] = true;
        //优化距离
        vector<Node> nodes = adj[u];
         for(Node node : nodes) {
            if(!visited[node.v] && (d[node.v] > d[u] + node.w)) {
                d[node.v] = d[u] + node.w;
            }
        }
    }
}

void adjl_map_instance() {
     AdjLMap map(5);
    //AdjLMap* map = new AdjLMap(5);
    map.addEdge(0,1,5);
    map.addEdge(0,2,6);
    map.addEdge(0,4,1);
    map.addEdge(1,0,5);
    map.addEdge(1,3,4);
    map.addEdge(1,4,2);
    map.addEdge(2,0,6);
    map.addEdge(2,3,3);
    map.addEdge(3,1,4);
    map.addEdge(3,2,3);
    map.addEdge(4,0,1);
    map.addEdge(4,1,2);
    //map.dfs_travel();
    map.dijkstra(0);
    for(int i = 0; i < map.N; i++) {
        cout<<"d["<<i<<"] is: "<<map.d[i]<<endl;
    }
}