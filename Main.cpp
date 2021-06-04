#pragma once;
#include"二叉树.h"
#include"单链表.h"
#include"图.h"
#include"栈.h"
#include"队列.h"
#include"基于单链表的多项式相加.h"
#include<string.h>


int LevelTraver_001(BiTree T)//广度优先遍历二叉树
{
	LinkQueue Q1;
	QElemType e1;
	BiTree p;
	InitQueue(Q1);
	if (T == NULL)return ERROR;
	EnQueue(Q1, T->date);
	while(!QueueEmpty(Q1))
	{
		DeQueue(Q1, e1);
		printf("%c\t", e1);
		p=Point(T, e1);
		if (p->lchild)
		{
			EnQueue(Q1, p->lchild->date);
		}
		if (p->rchild)
		{
			EnQueue(Q1, p->rchild->date);
		}
	}
}

void LinkList_001()//单链表的基本操作及应用
{
	int n1,num1;
	do
	{	
		printf("\n");
		printf("*********************************单链表的基本操作及应用****************************************\n");
		printf("* 1  创建                                                                                     *\n");
		printf("* 2  插入                                                                                     *\n");
		printf("* 3  删除                                                                                     *\n");
		printf("* 4  查找                                                                                     *\n");
		printf("* 5  应用                                                                                     *\n");
		printf("* 6  退出                                                                                     *\n");
		printf("***********************************************************************************************\n");
		printf("请选择：");
		cin >> n1;
		LinkList L1;
		int position1, position2;
		ElemType e1, e2, e3;
		switch (n1) {
		case 1:
			printf("--------创建单链表---------\n");
			printf("请选择链表创建方式：*1 头插法  *2尾插法 3、退出");
			cin >> num1;
			switch (num1)
			{
			case 1:printf("请输入链表元素个数：");
				cin >> num1;
				CreateList_3(L1, num1);
				printf("链表创建成功，所创链表为：\n");
				OutputLink(L1);
				DestroyLinklist(L1);
				break;
			case 2:printf("请输入链表元素个数：");
				cin >> num1;
				CreateList_1(L1, num1);
				printf("链表创建成功，所创链表为：\n");
				OutputLink(L1);
				DestroyLinklist(L1);
				break;
			case 3:break;
			default:printf("无此选项！！！");
				break;
			}
			break;
		case 2:
			printf("--------插入元素-------\n");
			printf("请输入链表元素个数：");
			cin >> num1;
			CreateList_1(L1, num1);
			printf("链表创建成功，所创链表为：\n");
			OutputLink(L1);
			printf("请选择插入的位置:");
			cin >> position1;
			printf("请输入插入的元素:");
			cin >> e1;
			ListInsert(L1, position1, e1);
			printf("插入成功！插入后的链表为：\n");
			OutputLink(L1);
			DestroyLinklist(L1);
			break;
		case 3:
			printf("--------删除元素-------\n");
			printf("请输入链表元素个数：");
			cin >> num1;
			CreateList_1(L1, num1);
			printf("链表创建成功，所创链表为：\n");
			OutputLink(L1);
			printf("请输入需要删除的位置：");
			cin >> position2;
			ListDelete(L1, position2, e2);
			printf("删除成功！删除后的链表为：\n");
			OutputLink(L1);
			DestroyLinklist(L1);
			break;
		case 4:
			printf("--------查找元素-------\n");
			printf("请输入链表元素个数：");
			cin >> num1;
			CreateList_1(L1, num1);
			printf("链表创建成功，所创链表为：\n");
			OutputLink(L1);
			printf("请输入你需要查找的元素:");
			cin >> e3;
			Located(L1, e3);
			DestroyLinklist(L1);
			break;
		case 5:
			printf("--------应用---------\n");
			printf("单链表实现多项式相加。\n");
			PolyNode* L1, * L2;
			int number1, number2;
			printf("请输入第一个多项式的项数：\n");
			cin >> number1;
			CreatPolyn_end(L1, number1);
			printf("请输入第二个多项式的项数\n");
			cin >> number2;
			CreatPolyn_end(L2, number2);
			printf("*****************************************\n");
			printf("第一个多项式为：\n");
			Output(L1);
			printf("第二个多项式为：\n");
			Output(L2);
			printf("*****************************************\n");
			printf("相加结果得：\n");
			AddPolyn_1(L1, L2);
			break;
		case 6: break;
		default:
			printf("ERROR!  %d",n1); break;
		}
	} while (n1 != 6);
	printf("退出单链表相关操作成功！！！\n");
}

void Stack_002()
{
	SElemType e1,e2;
	int n2, number1;
	SqStack S1;
	InitStack(S1);
	do {
		printf("\n");
		printf("**************************************栈的基本操作及应用****************************************\n");
		printf("* 1  进栈                                                                                      *\n");
		printf("* 2  出栈                                                                                      *\n");
		printf("* 3  取栈顶元素                                                                                *\n");
		printf("* 4  八进制转换                                                                                *\n");
		printf("* 5  应用                                                                                      *\n");
		printf("* 6  退出                                                                                      *\n");
		printf("************************************************************************************************\n");
		printf("请选择：");
		cin >> n2;
		switch (n2) {
		case 1:
			printf("--------进栈-------\n");
			printf("请输入进栈元素：");
			cin >> e1;
			Push(S1, e1);
			printf("现栈如下：\n");
			PrintStack_head_end(S1);
			break;
		case 2:
			printf("--------出栈-------\n");
			Pop(S1, e1);
			printf("出栈元素为：%d", e1);
			break;
		case 3:
			printf("--------取栈顶元素-------\n"); 
			e2= GetTop(S1);
			printf("栈顶元素为：%d", e2);
			break;
		case 4:
			printf("--------应用1、八进制转换 -------\n");
			printf("请输入需要转化为八进制数的十进制数：");
			cin >> number1;
			concersion(number1);
			break;
		case 5:printf("--------应用2、-------\n");
			
			break;
		case 6:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n2 != 6);
	printf("退出栈相关操作成功！！！\n");
}

void Queue_003()
{
	LinkQueue LQ1;
	BiTree T1;
	int n3,x1;
	InitQueue(LQ1);

	do {
		printf("\n");
		printf("*************************队列的基本操作及应用*************************\n");
		printf("* 1   入列                                                            *\n");
		printf("* 2   出列                                                            *\n");
		printf("* 3   取队头元素                                                      *\n");
		printf("* 4   取队尾元素                                                      *\n");
		printf("* 5   应用                                                            *\n");
		printf("* 6   退出                                                            *\n");
		printf("**********************************************************************\n");
		printf("请选择：");
		cin >> n3;
		switch (n3) {
		case 1:
			printf("---------入列-------\n");
			printf("请输入入队元素个数：");
			scanf_s("%d", &x1);
			EnQueueMany(LQ1, x1);
			printf("此时队列为：");
			PrintQueue(LQ1);
			break;
		case 2:
			printf("---------出列-------\n");
			QElemType e2;
			printf("请先创建队列\n");
			printf("请输入入队元素个数：");
			scanf_s("%d", &x1);
			EnQueueMany(LQ1, x1);
			DeQueue(LQ1, e2);
			printf("出队元素为：%c\n", e2);
			printf("出队后队列为：");
			PrintQueue(LQ1);
			break;
		case 3:
			printf("---------取队头元素-------\n");
			QElemType e3;
			printf("请先创建队列\n");
			printf("请输入入队元素个数：");
			scanf_s("%d", &x1);
			EnQueueMany(LQ1, x1);
			GetHead(LQ1, e3);
			printf("队头元素为：%c\n", e3);
			printf("此时队列为：");
			PrintQueue(LQ1);
			break;
		case 4:
			printf("---------取队尾元素-------\n");
			printf("请先创建队列\n");
			printf("请输入入队元素个数：");
			scanf_s("%d", &x1);
			EnQueueMany(LQ1, x1);
			GetRear(LQ1, e3);
			printf("队尾元素为：%c\n", e3);
			printf("此时队列为：");
			PrintQueue(LQ1);
			break;
		case 5:
			printf("---------应用-------\n");
			printf("创建二叉树\n");
			CreateBitTree(&T1);
			printf("该二叉树的广度优先遍历为：\n");
			LevelTraver_001(T1);
			break;
		case 6:
			break;
		default:
			printf("ERROR!"); break;
		}
	} while(n3 != 6);
	printf("退出队列相关操作成功！！！\n");
}

void BiTree_004() {
	int n4, Node,Depth1;
	DateType e1;
	BiTree T1,T2;
	do {
		InitBitTree(&T1);
		printf("\n");
		printf("**************二叉树的基本操作及应用***************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  遍历（先/中/后）                             *\n");
		printf("* 3  求结点个数                                   *\n");
		printf("* 4  求树的深度                                   *\n");
		printf("* 5  查找双亲                                     *\n");
		printf("* 6  查找兄弟（左/右）                            *\n");
		printf("* 7  查找孩子（左/右）                            *\n");
		printf("* 8  应用                                         *\n");
		printf("* 9  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		cin >> n4;
		switch (n4) {
		case 1:
			printf("---------创建--------\n");
			CreateBitTree(&T1);
			printf("此二叉树先序遍历为：\n");
			PrintTLR(T1);
			DestroyBitree(&T1);
			break;
		case 2:
			printf("---------遍历（先/中/后）-------\n"); 
			printf("创建二叉树\n");
			CreateBitTree(&T1);
			printf("此二叉树先序遍历为：\n");
			PrintTLR(T1);
			printf("此二叉树中序遍历为：\n");
			InOrderTraverse(T1);
			printf("此二叉树后序遍历为：\n");
			PrintLRT(T1);
			DestroyBitree(&T1);
			break;
		case 3:
			printf("---------求结点个数-------\n");
			printf("创建二叉树\n");
			CreateBitTree(&T1);
			Node=AllNodes(T1);
			printf("结点个数为：%d", Node);
			DestroyBitree(&T1);
			break;
		case 4:
			printf("---------求树的深度-------\n"); 
			printf("创建二叉树\n");
			CreateBitTree(&T1);
			Depth1=Depth_01(T1);
			printf("该二叉树的深度为：%d", Depth1);
			break;
		case 5:
			printf("---------查找双亲-------\n");
			printf("创建二叉树\n");
			CreateBitTree(&T1);
			printf("此二叉树先序遍历为：\n");
			PrintTLR(T1);
			printf("请输入要查找双亲的结点值：");
			cin >> e1;
			T2=Point_parents(T1, e1);
			if (T2 != NULL)
			{
				printf("该结点的双亲结点为：");
				printf("%c", T2->date);
			}
			else
				printf("该结点无双亲结点！");
			DestroyBitree(&T1);
			break;
		case 6:
			printf("---------查找兄弟（左/右）-------\n");
			DateType e8;
			printf("创建二叉树\n");
			CreateBitTree(&T1);
			printf("请输入要查找兄弟的结点值：");
			cin >> e8;
			T2=Point_Brother(T1, e8);
			if (T2 != NULL)
				printf("该节点的兄弟结点为：%c", T2->date);
			else
				printf("该结点无兄弟结点！");
			DestroyBitree(&T1);
			break;
		case 7:
			printf("---------查找孩子（左/右）-------\n"); 
			DateType e5,e6;
			int num1;
			printf("创建二叉树\n");
			CreateBitTree(&T1);
			printf("请输入要查找左/右孩子的父节点的结点值:");
			cin >> e5;
			printf("查找左孩子输入1  查找右孩子输入2\n");
			cin >> num1;
			if (num1 == 1)
			{
				e6=LeftChild(T1, e5);
				printf("该结点的左孩子为：%c", e6);
			}
			else
			{
				e6=RightChild(T1, e5);
				printf("该结点的右孩子为：%c", e6);
			}
			DestroyBitree(&T1);
			break;
		case 8:
			printf("---------应用-------\n"); 
			
			break;
		case 9:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n4 != 9);
	printf("退出二叉树相关操作成功！！！\n");
}

void Graph_005() {
	MGraph N1;
	int n5;
	do {
		printf("\n");
		printf("****************图的基本操作及应用*****************\n");
		printf("* 1  创建（邻接矩阵/邻接表）                      *\n");
		printf("* 2  遍历（深度/广度）                            *\n");
		printf("* 3  定位                                         *\n");
		printf("* 4  找第一个邻接点                               *\n");
		printf("* 5  找下一个邻接点                               *\n");
		printf("* 6  插入（点/边）                                *\n");
		printf("* 7  删除（点/边）                                *\n");
		printf("* 8  应用                                         *\n");
		printf("* 9  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		cin >> n5;
		switch (n5) {
		case 1:
			printf("---------创建（邻接矩阵/邻接表）-------\n");
			CreateGraph(&N1);
			printf("创建的图为：\n");
			DisplayGraph(N1);
			break;
		case 2:
			printf("---------遍历（深度/广度）-------\n"); 
			
			break;
		case 3:
			printf("---------定位-------\n"); 
			VertexType v1;
			int num2;
			printf("请输入要查找的顶点：");
			cin >> v1;
			num2=LocateVertex(N1, v1);
			printf("顶点的位置为：%d", num2);
			break;
		case 4:
			printf("---------找第一个邻接点-------\n"); 
			
			break;
		case 5:
			printf("---------找下一个邻接点-------\n");
			
			break;
		case 6:
			printf("---------插入（点/边）-------\n");
			
			break;
		case 7:
			printf("---------删除（点/边）-------\n"); 
			
			break;
		case 8:
			printf("---------应用-------\n"); break;
		case 9:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n5 != 9);
	printf("退出图相关操作成功！！！\n");
}

int main()
{
	int n;
	do {
		printf("请选择相关操作操作：\n");
		printf("*******************算法与数据结构******************\n");
		printf("* 1  单链表的基本操作及应用                       *\n");
		printf("* 2  栈的基本操作及应用                           *\n");
		printf("* 3  队列的基本操作及应用                         *\n");
		printf("* 4  二叉树的基本操作及应用                       *\n");
		printf("* 5  图的基本操作及应用                           *\n");
		printf("* 6  退出                                         *\n");
		printf("***************************************************\n");
		cin >> n;
		switch (n)
		{
		case 1:LinkList_001(); break;
		case 2:Stack_002(); break;
		case 3:Queue_003(); break;
		case 4:BiTree_004(); break;
		case 5:Graph_005(); break;
		case 6:break;
		default:printf("ERROR！");
			break;
		}
	} while (n!= 6);
	printf("退出成功！！！");
	return 0;
}