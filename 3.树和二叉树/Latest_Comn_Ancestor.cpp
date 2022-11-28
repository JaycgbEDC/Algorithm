BiTNode* Latest_ComnAncestor(BiTree T, BiTNode *q1, BiTNode *q2)
{
    //寻找q1和q2的最近公共祖先（假设q1在q2左边）
    BiTNode *s[20], *s1[20];
    int top = -1, top1 = -1;
    BiTNode *p = T, *last;
    while(p || -1 != top) {
        if(p) {
            s[++top] = p;
            p = p->lchild;
        }
        else {
            p = s[top];
            if (p && p == q1) //找到q1，将s中的祖先复制到辅助栈s1中
                for (int i = 0; i <= top; i++)
                    s1[++top1] = s[i];
            if(p->rchild && p->rchild != last)
                p = p->rchild;
            else {
                top--;
                if (p && p == q2){ //找到q2
                    int i;
                    for (i = 0; i <= top && i <= top1 && s[i] == s1[i]; i++);
                    if (i > 0)
                        return s[i - 1];
                }
                last = p;
                p = NULL;
            }
        }
    }
    return NULL;
}