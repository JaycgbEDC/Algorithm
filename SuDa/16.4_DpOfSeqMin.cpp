/*给定一整数数组A，要求：
    1. 找出连续子串的和的最小值。
    2. 若A中全部为正数，输出0，否则输出最小值
    3. 分析算法的时间复杂度
*/

//法一：暴力求解，遍历每一种可能。
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