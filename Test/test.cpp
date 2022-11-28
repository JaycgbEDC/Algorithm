#include <iostream>

using namespace std;

struct BiTNode
{
    int data;
    BiTNode *lchild, *rchild;

    BiTNode(int data)
    {
        this->data = data;
        this->lchild = this->rchild = nullptr;
    }
};

void PrintAncestor(BiTNode *T, char x)
{
    //打印x的所有祖先
    BiTNode *s[20];
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
                printf("%d\n", s[top]->data);
                top--;
            }
            exit(1);
        }
        else
        { //当前结点为空
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

int main()
{
    /* 构造下面的树
          1
        /   \
       /     \
      2       3
       \     / \
        4   5   6
           / \
          7   8
    */

    BiTNode *root = new BiTNode(1);
    root->lchild = new BiTNode(2);
    root->rchild = new BiTNode(3);
    root->lchild->rchild = new BiTNode(4);
    root->rchild->lchild = new BiTNode(5);
    root->rchild->rchild = new BiTNode(6);
    root->rchild->lchild->lchild = new BiTNode(7);
    root->rchild->lchild->rchild = new BiTNode(8);

    PrintAncestor(root, 4);

    return 0;
}