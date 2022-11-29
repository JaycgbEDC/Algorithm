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

int main()
{
    BiTree T = NULL;
    FILE *fp;
    fp = fopen("TestData.txt", "r");
    CreateBiTree(fp, T);
    fclose(fp);

    BiTNode *head = NULL, *pre = NULL;
    Leaf_To_List(T, head, pre);
    while(head) {
        cout << head->data <<endl;
        head = head->rchild;
    }

    system("pause");
    return 0;
}