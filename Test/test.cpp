#include <iostream>
#include <stdlib.h>
#include "time.h"

using namespace std;

int DpByArray(int A[], int n) {
    int temp = 0;//记录连续子串最小
    int min = A[0];
    for(int i = 0; i < n; i++) {
        if(temp + A[i] <= A[i])
            temp = temp + A[i];
        else
            temp = A[i];
        if(temp < min)
         min = temp;
    }
    return min;
}

int main() {
    clock_t start, finish;
    double  duration;
    int a[7] = {10, 20, -10, 8, -30, 20};
    start = clock();
    int b = DpByArray(a, 6);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    cout << b << endl;

    system("pause");
    return 0;
}