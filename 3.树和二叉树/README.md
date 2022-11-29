# 算法加入以下代码即可运行

```cpp
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




int main()
{
    BiTree T = NULL;
    FILE *fp;
    fp = fopen("TestData.txt", "r");
    CreateBiTree(fp, T);
    fclose(fp);

    system("pause");
    return 0;
}
```

## 测试数据

AB^^^：

```C
/*
		A
	       /
	      B
*/
```
