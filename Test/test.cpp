#include <iostream>
#include <stdlib.h>

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


BiTNode* Latest_ComnAncestor(BiTNode *T, BiTNode *q1, BiTNode *q2)
{
    //寻找q1和q2的最近公共祖先（假设q1在q2左边）
    BiTNode *s[20], *s1[20];
    int top = -1, top1 = -1;
    BiTNode *p = T, *last;
    while(p || -1 != top) {
        if(p) { //一路向左
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

    BiTNode *p = Latest_ComnAncestor(root, root->rchild->lchild->lchild, root->rchild->lchild->rchild);
    if(p)
        cout << p->data << endl;
    system("pause");
    return 0;
}