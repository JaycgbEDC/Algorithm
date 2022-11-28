void PrintAncestor(BiTree T, char x)
{
    //打印x的所有祖先
    BiTNode *s[MaxSize];
    int top = -1;
    BiTNode *p = T, *last;
    if (NULL == p || x == p->data) //处理第一个元素
        return;
    while (p || -1 != top)
    {
        if (p && x != p->data)
        { //当前非空且非x结点方可入栈
            s[++top] = p;
            p = p->lchild;
        }
        else if (p && x == p->data)
        { //当前非空且为x直接退栈
            while (-1 != top)
            {
                printf("%c\n", s[top]->data);
                top--;
            }
            return;
        }
        else
        {
            p = s[top];
            if (p->rchild && last != p->rchild)
                p = p->rchild;
            else
            {
                top--;
                last = p;
                p = NULL;
            }
        }
    }
}