int Max_Width(BiTree T)
{
    //求非空二叉树的最大宽度--->层次遍历
    BiTNode *Q[20];
    int front = -1, rear = -1;
    int curl = 0, curw = 0; //curl表示当前层最后一个结点，curw表示当前层宽度
    int max = 0; //最大二叉树宽
    BiTNode *p = T;
    Q[++rear] = p;
    while(front != rear) {
        p = Q[++front];
        curw++;
        if(p->lchild) {
            Q[++rear] = p->lchild;
        }
        if(p->rchild) {
            Q[++rear] = p->rchild;
        }
        if(front == curl) { //当前出栈结点为当层最后一个结点
            curl = rear;
            if(curw > max)
                max = curw;
            curw = 0;
        }
    }
    return max;
}