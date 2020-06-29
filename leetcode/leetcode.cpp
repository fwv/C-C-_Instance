#include<iostream>
#include<vector>

#ifndef LT_H
#define LT_H
#include"lt.cpp"
#endif

#include"lt2.cpp"
#include"lt3.cpp"
#include"lt4.cpp"
#include"lt46.cpp"
#include"lt47.cpp"
#include"lt60.cpp"
#include"lt206.cpp"
#include"lt148.cpp"




using namespace std;
void leetcode_instance();

void leetcode_instance() {

  lt* lt = new lt4();
  lt->run();

  cout << endl;
  cout<<"over"<<endl;
  
}
