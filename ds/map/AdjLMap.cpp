#include<iostream>
#include<vector>
#include"Map.cpp"
#include"Node.cpp"
using namespace std;

class AdjLMap : public Map {
    public:
        int N;
        bool *visited;
        vector<Node> *adj;

        AdjLMap(int _N) {
            N = _N;
            visited = (bool *)malloc(_N*sizeof(bool));
            adj = (vector<Node>*)malloc(_N*sizeof(vector<Node>));  
            for(int i = 0; i < _N; i++) {
                Node* node = new Node(i, 0);
                adj[i].push_back(* node);
                visited[i] = false;
            }
        } 

        AdjLMap(){}

        ~AdjLMap(){}

        void addEdge(int node1, int node2, int w);

        void dfs(int sp);

        void dfs_travel();

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