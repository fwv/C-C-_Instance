#include<iostream>
#include<vector>

#ifndef LT_H
#define LT_H
#include"lt.cpp"
#endif

#include"lt2.cpp"
#include"lt3.cpp"
#include"lt4.cpp"
#include"lt5.cpp"
#include"lt10.cpp"
#include"lt17.cpp"
#include"lt21.cpp"
#include"lt31.cpp"
#include"lt32.cpp"
#include"lt34.cpp"
#include"lt39.cpp"
#include"lt46.cpp"
#include"lt47.cpp"
#include"lt60.cpp"
#include"lt75.cpp"
#include"lt76.cpp"
#include"lt206.cpp"
#include"lt148.cpp"
#include"lt438.cpp"
#include"lt567.cpp"




using namespace std;
void leetcode_instance();

void leetcode_instance() {

  lt* lt = new lt75();
  lt->run();

  cout << endl;
  cout<<"over"<<endl;
  
}
