void Leaf_To_List(BiTree T, BiTNode *&head, BiTNode *&pre) //head是单链表头节点的引用，pre是前驱结点的引用
{
    //二叉树叶节点从左到右连成单链表--->前序遍历
    if(T) {
        if(NULL == T->lchild && NULL == T->rchild) {
            if(NULL == pre)
                head = T;
            else
                pre->rchild = T;
            pre = T;
        }
        Leaf_To_List(T->lchild, head, pre);
        Leaf_To_List(T->rchild, head, pre);
    }
}