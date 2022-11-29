void Pre_ToPost(ElemType pre[], int l1, int h1, ElemType post[], int l2, int h2)
{
    //满二叉树，已知先序求后序
    int half = (h1 - l1) / 2;
    if(l1 <= h1) {
        post[h2] = pre[l1];
        Pre_ToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1); //转换左子树
        Pre_ToPost(pre, l1 + half +1, h1, post, l2 + half, h2 - 1); //转换右子树
    }
}