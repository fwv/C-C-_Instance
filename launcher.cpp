#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "mylib.h"

using namespace std;

void show(vector<string>*  adj);

int main()
{   
    //todo:归档到pointer中
    // vector<string>* adj = (vector<string>*)malloc(3*sizeof(vector<string>));
    // // vector<string>* adj;
    // vector<string> msg {"Helloooo", "C++", "World", "from", "VS Code!"};
    // adj[0] = msg;

    // for(int i = 1; i < 3; i++) {
    //     vector<string> v;
    //     adj[i] = v;
    // }
    // show(adj);
    // cout << endl;
    // for (const string& word : msg)
    // {
    //     cout << word << " ";
    // }
    // cout << endl;
    // vector<string> v1 = adj[1];
    // for (const string& word : v1)
    // {
    //     cout << word << " ";
    // }
    // cout << endl;
    // for (const string& word : adj[2])
    // {
    //     cout << word << " ";
    // }
    // cout << endl;
    p1003();
    system("PAUSE");
}

void show(vector<string>* adj) {
    cout << adj[0].size() <<endl;
    for (const string& word : adj[0])
    {
        cout << word << " ";
    }
    adj[0].push_back("fw!!!");
    adj[1].push_back("sss");
    adj[2].push_back("i am 333333333!");
}