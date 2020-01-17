#include<iostream>
#include<string>
#include<queue>
using namespace std;

void queue_instance() {

    //d_queue
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    cout<< q.front() <<endl;
    cout<< q.back() <<endl;

    //priority_queue
    priority_queue<int> pq;
    pq.top();
}