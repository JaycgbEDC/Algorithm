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


void Pre_ToPost(ElemType pre[], int l1, int h1, ElemType post[], int l2, int h2)
{
    //满二叉树，已知先序求后序(满二叉树意味着左右子树的结点数必相等)
    int half = (h1 - l1) / 2;
    if(l1 <= h1) {
        post[h2] = pre[l1];
        Pre_ToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1); //转换左子树
        Pre_ToPost(pre, l1 + half +1, h1, post, l2 + half, h2 - 1); //转换右子树
    }
}

int main()
{
    // BiTree T = NULL;
    // FILE *fp;
    // fp = fopen("TestData.txt", "r");
    // CreateBiTree(fp, T);
    // fclose(fp);

    ElemType *pre = "ABCDEFG";
    ElemType post[8];
    Pre_ToPost(pre, 0, 6, post, 0, 6);
    for(int i = 0; i <= 6; i++) {
        cout << post[i] << endl;
    }
    system("pause");
    return 0;
}