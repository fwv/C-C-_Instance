#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "mylib.h"

using namespace std;

void show(vector<string>*  adj);

int main()
{   
    sample_instance();
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

 