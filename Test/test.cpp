#include <iostream>
#include <stdlib.h>

using namespace std;

int Brutal_Min1(int A[], int n) {
    int temp = A[0], min = A[0];
    int flag = 0;//A中是否全为正数标志
    for(int i = 0; i < n; i++) {
        temp = A[i];
        for(int j = i + 1; j <n; j++) {
            temp += A[j];
            if(temp < min)
                min = temp;
        }
        if(A[i] <= 0)
            flag = 1;
    }
    if(flag)
        return min;
    else
        return 0;
}

int main() {
    int a[7] = {10, 20, -10, 8, -30, 20};
    int b = Brutal_Min1(a, 6);
    cout << b << endl;

    system("pause");
    return 0;
}