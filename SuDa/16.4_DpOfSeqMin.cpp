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

//法二：借助辅助数组，采用动态规划思想
int DpByArray(int A[], int n) {
    int d[n];//记录每个位置连续子串的和的最小值
    int min = A[0];
    d[0] = A[0];
    for(int i = 1; i < n; i++) {
        if(d[i - 1] + A[i] < A[i])
            d[i] = d[i - 1] + A[i];
        else
            d[i] = A[i];
    }
    for(int i = 0; i < n; i++)
        if(d[i] < min)
            min = d[i];
    return min;
}

//法三：联机算法，不需要辅助空间的动态规划
int DpWithoutArray(int A[], int n) {
    int temp = 0;//记录连续子串最小
    int min = A[0];
    for(int i = 0; i < n; i++) {
        if(temp + A[i] <= temp)
            temp = temp + A[i];
        else
            temp = A[i];
        if(temp < min)
         min = temp;
    }
    return min;
}