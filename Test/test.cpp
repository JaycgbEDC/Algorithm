#include <iostream>
#include <stdlib.h>
#include "time.h"

using namespace std;

bool IsMeetNum(int n) {
    //判断数n是否在序列中
    if(1 == n)
        return true;
    else if(0 == n % 2)
        return IsMeetNum(n / 2);
    else if(0 == n % 3)
        return IsMeetNum(n / 3);
    else if(0 == n % 5)
        return IsMeetNum(n / 5);
    else
        return false;
}

void PrintMin100() {
    for(int i = 0, j = 1; i < 100; j++) {//j没有上限，限制循环次数的是i
        if(IsMeetNum(j)) {
            cout << j << " ";
            i++;//只有在序列中才输出下一个数
        }
    }
}


int main() {

    PrintMin100();
    cout << endl;

    system("pause");
    return 0;
}