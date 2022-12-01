typedef struct SqList
{
    int *data;
    int length;
}SqList;


int Find_Mid(SqList L1, SqList L2) {
    //L1、L2分别是递增序列，查找其所有元素的中位值
    /*
        1. 本题类似归并排序，但是只是找中位数所以不用排序，时间复杂度O(m+n)；
        2. 这题如果说两个顺序表有序且表长相同，就和王道的408一样了，另有解法。
    */
    int lenth1 = L1.length, lenth2 = L2.length;
    int l1 = 0, l2 = 0;
    int mid = (lenth1 + lenth2) / 2, midv = 0;
    while(l1 < lenth1 && l2 < lenth2 && mid >= 0) {
        midv = (L1.data[l1] < L2.data[l2]) ? L1.data[l1++] : L2.data[l2++];
        mid--;
    }
    while (mid >= 0 && l1 < lenth1) {
        midv = L1.data[l1++];
        mid--;
    }
    while (mid >= 0 && l2 < lenth2) {
        midv = L2.data[l2++];
        mid--;
    }
    return midv;
}