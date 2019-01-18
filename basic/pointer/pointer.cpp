#include <iostream>
using namespace std;

/* method declaration */
void swap1(int* i, int* j);
void swap2(int* i, int* j);
void swap3(int &i, int &j);

/* method implements */
void pointer_instance() {
    /* basic usage of pointer. */
        // int i = 1;
        // int *p;
        // p = &i;
        // printf("pointer p's value is %d, the variable's value which p point to is %d\n",p, *p);
    /* pointer initialization */
        // int j = 1;
        // for(int i = 0; i < 100; i++) {
        //     int *p;

        //     /* right. */
        //         p = &j;

        //     /* error, because pointer p hasn't initialize, there are many mistakes when p is initialized as OS working area.*/
        //         *p = j;

        //     printf("%d\n", p);
        // }

    /* pass by reference and pass by value */
    int a = 1, b = 2;
    int* a1,* b1;
    a1 = &a;
    b1 = &b;
    //swap(a,b);//it's very strange that this method don't need method declaration.why???
    // swap3(a,b);
    // printf("a= %d,b= %d\n",a,b);
    // swap1(a1,b1);
    // swap2(a1,b1);
    // printf("a= %d,b= %d\n",*a1,*b1);
}

/* pass by value,doesn't works in c(because just swap the dumplications), but does works in c++ */
void swap(int i ,int j){
    int temp;
    temp = i;
    i = j;
    j=temp;
}

/* pass by reference */
void swap1(int* i, int* j) {
    int temp = 1;
    temp = *i;
    *i = *j;
    *j = temp;
}

/* pass by value,doesn't works both in c and c++(because just swap the dumplications)*/
void swap2(int* i, int* j) {
    int *temp = i;
    i = j;
    j = temp;
}

/* pass by c++ reference(lightweight substitude of pointer), it works in c++ perfectly. */
void swap3(int &i, int &j) {
    int temp;
    temp = i;
    i = j;
    j = temp;
}