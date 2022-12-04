/*求n个结点的二叉树的形态数目（卡特兰数，求出栈情况也是类似公式，记一下）
    n=0--->1
    n=1--->1
    n=2--->2
    n=3--->5
    n=4--->14
*/

//法一：动态规划+辅助数组：O(n^2)、O(n)
int BiTreeShapeNumber_Dp(int n) {
    int dp[n];
    dp[0] = 1;
    for(int i = 1; i <= n; i++) 
        for(int j = 0; j < i; j++)
            dp[i] += dp[j]*dp[i - j - 1];
    return dp[n];
}

//法二：卡特兰数计算公式：O(n)、O(1)
int BiTreeShapeNumber_Catalan(int n) {
    int res = 1;
    for(int i = n + 2; i <= 2*n; i++) 
        res = res*i / (i - n);
    return res;
}