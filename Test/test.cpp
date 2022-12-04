#include <iostream>
#include <stdlib.h>
#include "time.h"

using namespace std;

int BiTreeShapeNumber_Dp(int n) {
    int res = 1;
    for(int i = n + 2; i <= 2*n; i++) 
        res = res*i / (i - n);
    return res;
}

int main() {
    clock_t start, finish;
    double  duration;
    int a = 4;
    start = clock();
    int b = BiTreeShapeNumber_Dp(a);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    cout << b << endl;

    system("pause");
    return 0;
}