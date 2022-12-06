/*有这样的序列：
    1.整数1在序列中
    2.若x在序列中，则2x、3x、5x也在序列中
    3.除此之外没有别的数
    要求：输出该序列最小的100个数，要求采用递归思想
*/

bool IsMeetNum(int n) {
    //判断数n是否在序列中
    if(1 == n)
        return true;
    else if(0 == n % 2)
        return IsMeetNum(n % 2);
    else if(0 == n % 3)
        return IsMeetNum(n % 3);
    else if(0 == n % 5)
        return IsMeetNum(n % 5);
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