#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define MaxSize 100
typedef char DateType;
using namespace std;

typedef struct Node {
	DateType date;
	struct Node* lchild, * rchild;
}BitNode, * BiTree;

void InitBitTree(BiTree* T)//初始化
{
	*T = NULL;
}

void DestroyBitree(BiTree* T)//销毁二叉树
{
	if (*T)
	{
		if ((*T)->lchild)
			DestroyBitree(&((*T)->lchild));
		if ((*T)->rchild)
			DestroyBitree(&((*T)->rchild));
		free(*T);
		*T = NULL;
	}
}

int i = 1;
void CreateBitTree(BiTree* T)//创建二叉树
{
	DateType ch;
	cin >> ch;
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BitNode));
		if (!(*T))
			exit(-1);
		(*T)->date = ch;
		CreateBitTree(&((*T)->lchild));
		CreateBitTree(&((*T)->rchild));
	}
}

BiTree Point(BiTree T, DateType e)//返回二叉树指定节点的指针
{
	BiTree Q[MaxSize];
	int front = 0, rear = 0;
	BitNode* p;
	if (T)
	{
		Q[rear] = T;
		rear++;
		while (front != rear)
		{
			p = Q[front];
			front++;
			if (p->date == e)
				return p;
			if (p->lchild)
			{
				Q[rear] = p->lchild;
				rear++;
			}
			if (p->rchild)
			{
				Q[rear] = p->rchild;
				rear++;
			}
		}
	}
	return NULL;
}

BiTree Point_parents(BiTree T, DateType e)//返回二叉树指定节点的指针
{
	BiTree Q[MaxSize];
	int front = 0, rear = 0;
	BitNode* p;
	if (T)
	{
		Q[rear] = T;
		rear++;
		if (T->lchild)
		{
			Q[rear] = T->lchild;
			rear++;
		}
		if (T->rchild)
		{
			Q[rear] = T->rchild;
			rear++;
		}
		while (front != rear)
		{
			p = Q[front];
			front++;
			if ((p->lchild!=NULL&&(p->lchild->date == e))||(p->rchild!=NULL&&(p->rchild->date==e)))
				return p;
			if (p->lchild)
			{
				Q[rear] = p->lchild;
				rear++;
			}
			if (p->rchild)
			{
				Q[rear] = p->rchild;
				rear++;
			}
		}
	}
	return NULL;
}

BiTree Point_Brother(BiTree T, DateType e)//返回二叉树指定节点的指针
{
	BiTree Q[MaxSize];
	int front = 0, rear = 0;
	BitNode* p;
	if (T)
	{
		Q[rear] = T;
		rear++;
		if (T->lchild)
		{
			Q[rear] = T->lchild;
			rear++;
		}
		if (T->rchild)
		{
			Q[rear] = T->rchild;
			rear++;
		}
		while (front != rear)
		{
			p = Q[front];
			front++;
			if ((p->lchild != NULL && (p->lchild->date == e)) )
				return p->rchild;
			else if((p->rchild != NULL && (p->rchild->date == e)))
				return p->lchild;
			if (p->lchild)
			{
				Q[rear] = p->lchild;
				rear++;
			}
			if (p->rchild)
			{
				Q[rear] = p->rchild;
				rear++;
			}
		}
	}
	return NULL;
}

int Depth_01(BiTree T)//二叉树的深度
{
	if (T == NULL) {
		return 0;
	}
	else {
		if(Depth_01(T->lchild)>Depth_01(T->rchild))return Depth_01(T->lchild)+1;
		else 
			return Depth_01(T->rchild)+1;
	}
}

int InSertChild(BiTree p, int LR, BiTree c)//二叉树插入操作
{
	if (p)
	{
		if (LR == 0)
		{
			c->rchild = p->lchild;
			p->lchild = c;
		}
		else
		{
			c->rchild = p->rchild;
			p->rchild = c;
		}
		return 1;
	}
	return 0;
}

DateType LeftChild(BiTree T, DateType e)//返回二叉树左孩子结点元素值
{
	BiTree p;
	if (T)
	{
		p = Point(T, e);
		if (p && p->lchild)
			return p->lchild->date;
	}
	return 0;
}

DateType RightChild(BiTree T, DateType e)//返回二叉树右孩子结点元素值
{
	BiTree p;
	if (T)
	{
		p = Point(T, e);
		if (p && p->rchild)
			return p->rchild->date;
	}
	return 0;
}



int DeleteLeftChild(BiTree p, int LR)//二叉树左删除操作
{
	if (p)
	{
		if (LR == 0)
			DestroyBitree(&(p->lchild));
		else
			DestroyBitree(&(p->rchild));
		return 1;
	}
	return 0;
}

void PrintLevel(BiTree T)//按层次输出二叉树
{
	BiTree Queue[MaxSize];
	int front, rear;
	if (T == NULL)
		return;
	front = -1;
	rear = 0;
	Queue[rear] = T;
	while (front != rear)
	{
		front++;
		printf("%4c", Queue[front]->date);
		if (Queue[front]->lchild != NULL)
		{
			rear++;
			Queue[rear] = Queue[front]->lchild;
		}
		if (Queue[front]->rchild != NULL)
		{
			rear++;
			Queue[rear] = Queue[front]->rchild;
		}
	}
}

void PrintTLR(BiTree T)//先序遍历递归算法
{
	if (T!=NULL)
	{
		printf("%4c", T->date);
		PrintTLR(T->lchild);
		PrintTLR(T->rchild);
	}
}

void PrintLRT(BiTree T)//后续遍历递归算法
{
	if (T != NULL)
	{

		PrintLRT(T->lchild);
		PrintLRT(T->rchild);
		printf("%4c", T->date);
	}
}

void Visit(BiTree T, BiTree pre, char e, int i)
{
	if (T == NULL && pre == NULL)
	{
		printf("\n对不起！你还没有建立二叉树，先建立在进行访问！\n");
		return;
	}
	if (T == NULL)
		return;
	else if (T->date == e)
	{
		if (pre != NULL)
		{
			printf("%2c的双亲结点是：%2c\n", e, pre->date);
			printf("%2c结点在%2c层上\n", e, i);
		}
		else
			printf("%2c位于第一层，无双亲结点！\n", e);
	}
	else
	{
		Visit(T->lchild, T, e, i + 1);
		Visit(T->rchild, T, e, i + 1);
	}
}

void InOrderTraverse(BiTree T)//中序遍历非递归
{
	BiTree stack[MaxSize];
	int top;
	BitNode* p;
	top = 0;
	p = T;
	while (p != NULL || top > 0)
	{
		while (p != NULL)
		{
			stack[top++] = p;
			p = p->lchild;
		}
		if (top > 0)
		{
			p = stack[--top];
			printf("%2c", p->date);
			p = p->rchild;
		}
	}
}

void PostOrderTraverse(BiTree T)//后序遍历非递归
{
	BiTree stack[MaxSize];
	int top;
	BitNode* p, * q;
	top = 0;
	p = T; q = NULL;
	while (p != NULL || top > 0)
	{
		while (p != NULL)
		{
			stack[top++] = p;
			p = p->lchild;
		}
		if (top > 0)
		{
			p = stack[top - 1];
			if (p->rchild == NULL || p->rchild == q)
			{
				printf("%2c", p->date);
				q = p;
				p = NULL;
				top--;
			}
			else
				p = p->rchild;
		}
	}
}

int LeafNum(BiTree T)//统计二叉树叶子结点个数

{
	if (!T)
	{
		return 0;
	}
	else if (!T->lchild && !T->rchild)
		return 1;
	else
		return LeafNum(T->lchild) + LeafNum(T->rchild);
}

int NotLeafNum(BiTree T)//统计二叉树非叶子结点个数
{
	if (!T)
		return 0;
	else if (!T->lchild && !T->rchild)
		return 1;
	else
		return NotLeafNum(T->lchild) + NotLeafNum(T->rchild) + 1;
}

int AllNodes(BiTree T)//统计二叉树结点个数
{
	if (!T)
		return 0;
	else if (!T->lchild && !T->rchild)
		return 1;
	else
		return AllNodes(T->lchild) + AllNodes(T->rchild) + 1;
}

BiTree BSTSearch(BiTree T, DateType x)//二叉排序树的查找
{
	BiTree p;
	if (T != NULL)
	{
		p = T;
		while (p != NULL)
		{
			if (p->date == x)
			{
				return p;
			}
			else if (x < p->date)
				p = p->lchild;
			else
				p = p->rchild;
		}
	}
	return NULL;
}