#include<iostream>
using namespace std;


struct shishen{
    int level;
    int star;
    shishen *partner;
    //shishen(int _level, int _star):level(_level),star(_star){}
}*heitongzi,guhuoniao,schema[3];

struct yuhun{
    int star;
    int pos;
    //yuhun(int _star, int _pos):star(_star),pos(_pos){}
    // yuhun(int _star, int _pos){
    //     star = _star;
    //     pos = _pos;
    // }
}zhennv,poshi,*y;

/* majority usage of struct */
void struct_instance() {
    struct yuhun zhennv;
    y->star = 77;
    printf("%d\n",y->star);

}