#include <iostream>
#include <stdlib.h>

using namespace std;


typedef char ElemType;
typedef struct BiTNode
{
	ElemType data; 
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, *BiTree;	


void CreateBiTree(FILE *fp, BiTree &T)
{
	char ch;

	fscanf(fp, "%c", &ch);
	
	if(ch == '^')
		T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		if(!T)
			exit(EOVERFLOW);
		T->data = ch;
		CreateBiTree(fp, T->lchild);
		CreateBiTree(fp, T->rchild);
	}
    return;
}


int Max_Width(BiTNode *T)
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

int main()
{
    BiTree T = NULL;
    FILE *fp;
    fp = fopen("TestData.txt", "r");
    CreateBiTree(fp, T);
    fclose(fp);

    int a = Max_Width(T);
    cout << a << endl;
    system("pause");
    return 0;
}