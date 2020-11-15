#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

#define MIN 9999;
#define MAX -9999;

int partition(int *a, int left, int right);
int partition1(int *a, int left, int right);
void showArray(int *a, int len);
void quickSort(int *a, int left, int right);
void countSort(int *a, int len);
int itohashi(int i, int min);
int hashitoi(int i, int min);

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
int partition(int *a, int left, int right)
{
    int base = a[left];
    while (left < right)
    {
        while (left < right && a[right] >= base)
        {
            right--;
        }
        a[left] = a[right];
        //showArray(a, 5);
        while (left < right && a[left] < base)
        {
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

int partition1(int *a, int left, int right)
{
    int x = a[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (a[j] <= x)
        {
            i++;
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    int temp = a[right];
    a[right] = a[i + 1];
    a[i + 1] = temp;
    return i + 1;
}

void quickSort(int *a, int left, int right)
{
    if (left < right)
    {
        int p = partition1(a, left, right);
        showArray(a, 9);
        printf("partition is : %d, ", a[p]);
        int nP = p - 1;
        quickSort(a, left, nP);
        quickSort(a, p + 1, right);
    }
}

void countSort(int *a, int len)
{
    showArray(a, len);
    //1.find max and min
    int min = MIN;
    int max = MAX;
    for (int i = 0; i < len; i++)
    {
        min = (a[i] < min) ? a[i] : min;
    }
    for (int i = 0; i < len; i++)
    {
        max = (a[i] > max) ? a[i] : max;
    }
    printf("min: %d max: %d \n", min, max);
    int hash_size = max - min + 1;
    //2.build hash table
    int *hash_table = (int *)malloc(hash_size * sizeof(int *));
    memset(hash_table, 0, len);
    for (int i = 0; i < len; i++)
    {
        int index = itohashi(a[i], min);
        hash_table[index]++;
    }
    printf("哈希表:");
    showArray(hash_table, 10);
    //3.sort
    for (int i = 1; i < hash_size; i++)
    {
        hash_table[i] = hash_table[i - 1] + hash_table[i];
    }
    printf("次序哈希表:");
    showArray(hash_table, 10);
    int *b = (int *)malloc(len * sizeof(int *));
    for (int j = len - 1; j >= 0; j--)
    {
        int index = hash_table[itohashi(a[j], min)];
        b[index - 1] = a[j];
        hash_table[itohashi(a[j], min)]--;
        showArray(b, 10);
    }
    showArray(b, len);
}

int itohashi(int i, int min)
{
    return i - min;
}

int hashitoi(int i, int min)
{
    return i + min;
}

void showArray(int *a, int len)
{
    printf("showArray: ");
    for (int i = 0; i < len; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
}

void sort_instance()
{
    printf("------------exp1 start------------\n");
    int a[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    quickSort(a, 0, 8);
    printf("\n快速排序实验报告： 时间复杂度为O(nlgn) 空间复杂度为O(nlgn)\n");
    printf("------------exp1 end------------\n");

    printf("\n------------exp2 start------------\n");
    int b[10] = {95, 94, 91, 98, 99, 90, 99, 93, 91, 92};
    countSort(b, 10);
    printf("\n计数排序实验报告： 时间复杂度为O(n) 空间复杂度为O(k)\n");
    printf("------------exp2 end------------\n");
}