bool IsTree_Similar(BiTree T1, BiTree T2)
{
    //判断两颗二叉树是否相似
    if(NULL == T1 && NULL == T2) //都为空则相似
        return true;
    else if(T1 && T2) { //都不为空，则比较左右分别是否相似
        bool l = IsTree_Similar(T1->lchild, T2->lchild);
        bool r = IsTree_Similar(T1->rchild, T2->rchild);
        return l & r;
    }
    else //其他情况不相似
        return false;
}