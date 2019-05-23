#include<stdio.h>
using namespace std;


int partition(int *a, int left, int right);
void showArray(int *a, int len);
void quickSort(int*a, int left, int right);


/**
	Structure:left and right help each other
	Pattern: classic flash game "ice and fires"

    6  2  7  1  8  2  4    6
    l                 h   base

    4  2  7  1  8  2  4
    l                 h

    4  2  7  1  8  2  7
          l           h

    4  2  2  1  8  2  7
          l        h

    4  2  2  1  8  8  7
                l  h
      
 **/
int partition(int *a, int left, int right) {
    int base = a[left];
    while(left < right) {
        while(left < right && a[right] >= base) {
            right--;
        }
        a[left] = a[right];
        //showArray(a, 5);
        while(left < right && a[left] < base) {
            left++;
        }
        a[right] = a[left];
        //showArray(a, 5);
    }
    //printf("left is: %d \n", left);
    //printf("right is: %d\n", right);
    a[left] = base;
    return left;
}

void quickSort(int*a, int left, int right) {
    if(left < right) {
    int p = partition(a, left, right);
        quickSort(a, left, p);
        quickSort(a, p+1, right);
    }
    
}

void showArray(int *a, int len) {
       printf("showArray: ");
       for(int i = 0; i < len; i++) {
         printf(" %d", a[i]);
       } 
       printf("\n");
}

void sort_instance() {
    int a[14] = {16,1,33,4,7,44,2,11,2,55,6,24,1,8};
    //int a[2] = {2,1};
    showArray(a, 14);
    //partition(a, 0, 13);
    quickSort(a, 0, 13);
    showArray(a, 14);
}