#pragma once;
#include"������.h"
#include"������.h"
#include"ͼ.h"
#include"ջ.h"
#include"����.h"
#include"���ڵ�����Ķ���ʽ���.h"
#include<string.h>


int LevelTraver_001(BiTree T)//������ȱ���������
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

void LinkList_001()//������Ļ���������Ӧ��
{
	int n1,num1;
	do
	{	
		printf("\n");
		printf("*********************************������Ļ���������Ӧ��****************************************\n");
		printf("* 1  ����                                                                                     *\n");
		printf("* 2  ����                                                                                     *\n");
		printf("* 3  ɾ��                                                                                     *\n");
		printf("* 4  ����                                                                                     *\n");
		printf("* 5  Ӧ��                                                                                     *\n");
		printf("* 6  �˳�                                                                                     *\n");
		printf("***********************************************************************************************\n");
		printf("��ѡ��");
		cin >> n1;
		LinkList L1;
		int position1, position2;
		ElemType e1, e2, e3;
		switch (n1) {
		case 1:
			printf("--------����������---------\n");
			printf("��ѡ����������ʽ��*1 ͷ�巨  *2β�巨 3���˳�");
			cin >> num1;
			switch (num1)
			{
			case 1:printf("����������Ԫ�ظ�����");
				cin >> num1;
				CreateList_3(L1, num1);
				printf("�������ɹ�����������Ϊ��\n");
				OutputLink(L1);
				DestroyLinklist(L1);
				break;
			case 2:printf("����������Ԫ�ظ�����");
				cin >> num1;
				CreateList_1(L1, num1);
				printf("�������ɹ�����������Ϊ��\n");
				OutputLink(L1);
				DestroyLinklist(L1);
				break;
			case 3:break;
			default:printf("�޴�ѡ�����");
				break;
			}
			break;
		case 2:
			printf("--------����Ԫ��-------\n");
			printf("����������Ԫ�ظ�����");
			cin >> num1;
			CreateList_1(L1, num1);
			printf("�������ɹ�����������Ϊ��\n");
			OutputLink(L1);
			printf("��ѡ������λ��:");
			cin >> position1;
			printf("����������Ԫ��:");
			cin >> e1;
			ListInsert(L1, position1, e1);
			printf("����ɹ�������������Ϊ��\n");
			OutputLink(L1);
			DestroyLinklist(L1);
			break;
		case 3:
			printf("--------ɾ��Ԫ��-------\n");
			printf("����������Ԫ�ظ�����");
			cin >> num1;
			CreateList_1(L1, num1);
			printf("�������ɹ�����������Ϊ��\n");
			OutputLink(L1);
			printf("��������Ҫɾ����λ�ã�");
			cin >> position2;
			ListDelete(L1, position2, e2);
			printf("ɾ���ɹ���ɾ���������Ϊ��\n");
			OutputLink(L1);
			DestroyLinklist(L1);
			break;
		case 4:
			printf("--------����Ԫ��-------\n");
			printf("����������Ԫ�ظ�����");
			cin >> num1;
			CreateList_1(L1, num1);
			printf("�������ɹ�����������Ϊ��\n");
			OutputLink(L1);
			printf("����������Ҫ���ҵ�Ԫ��:");
			cin >> e3;
			Located(L1, e3);
			DestroyLinklist(L1);
			break;
		case 5:
			printf("--------Ӧ��---------\n");
			printf("������ʵ�ֶ���ʽ��ӡ�\n");
			PolyNode* L1, * L2;
			int number1, number2;
			printf("�������һ������ʽ��������\n");
			cin >> number1;
			CreatPolyn_end(L1, number1);
			printf("������ڶ�������ʽ������\n");
			cin >> number2;
			CreatPolyn_end(L2, number2);
			printf("*****************************************\n");
			printf("��һ������ʽΪ��\n");
			Output(L1);
			printf("�ڶ�������ʽΪ��\n");
			Output(L2);
			printf("*****************************************\n");
			printf("��ӽ���ã�\n");
			AddPolyn_1(L1, L2);
			break;
		case 6: break;
		default:
			printf("ERROR!  %d",n1); break;
		}
	} while (n1 != 6);
	printf("�˳���������ز����ɹ�������\n");
}

void Stack_002()
{
	SElemType e1,e2;
	int n2, number1;
	SqStack S1;
	InitStack(S1);
	do {
		printf("\n");
		printf("**************************************ջ�Ļ���������Ӧ��****************************************\n");
		printf("* 1  ��ջ                                                                                      *\n");
		printf("* 2  ��ջ                                                                                      *\n");
		printf("* 3  ȡջ��Ԫ��                                                                                *\n");
		printf("* 4  �˽���ת��                                                                                *\n");
		printf("* 5  Ӧ��                                                                                      *\n");
		printf("* 6  �˳�                                                                                      *\n");
		printf("************************************************************************************************\n");
		printf("��ѡ��");
		cin >> n2;
		switch (n2) {
		case 1:
			printf("--------��ջ-------\n");
			printf("�������ջԪ�أ�");
			cin >> e1;
			Push(S1, e1);
			printf("��ջ���£�\n");
			PrintStack_head_end(S1);
			break;
		case 2:
			printf("--------��ջ-------\n");
			Pop(S1, e1);
			printf("��ջԪ��Ϊ��%d", e1);
			break;
		case 3:
			printf("--------ȡջ��Ԫ��-------\n"); 
			e2= GetTop(S1);
			printf("ջ��Ԫ��Ϊ��%d", e2);
			break;
		case 4:
			printf("--------Ӧ��1���˽���ת�� -------\n");
			printf("��������Ҫת��Ϊ�˽�������ʮ��������");
			cin >> number1;
			concersion(number1);
			break;
		case 5:printf("--------Ӧ��2��-------\n");
			
			break;
		case 6:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n2 != 6);
	printf("�˳�ջ��ز����ɹ�������\n");
}

void Queue_003()
{
	LinkQueue LQ1;
	BiTree T1;
	int n3,x1;
	InitQueue(LQ1);

	do {
		printf("\n");
		printf("*************************���еĻ���������Ӧ��*************************\n");
		printf("* 1   ����                                                            *\n");
		printf("* 2   ����                                                            *\n");
		printf("* 3   ȡ��ͷԪ��                                                      *\n");
		printf("* 4   ȡ��βԪ��                                                      *\n");
		printf("* 5   Ӧ��                                                            *\n");
		printf("* 6   �˳�                                                            *\n");
		printf("**********************************************************************\n");
		printf("��ѡ��");
		cin >> n3;
		switch (n3) {
		case 1:
			printf("---------����-------\n");
			printf("���������Ԫ�ظ�����");
			scanf_s("%d", &x1);
			EnQueueMany(LQ1, x1);
			printf("��ʱ����Ϊ��");
			PrintQueue(LQ1);
			break;
		case 2:
			printf("---------����-------\n");
			QElemType e2;
			printf("���ȴ�������\n");
			printf("���������Ԫ�ظ�����");
			scanf_s("%d", &x1);
			EnQueueMany(LQ1, x1);
			DeQueue(LQ1, e2);
			printf("����Ԫ��Ϊ��%c\n", e2);
			printf("���Ӻ����Ϊ��");
			PrintQueue(LQ1);
			break;
		case 3:
			printf("---------ȡ��ͷԪ��-------\n");
			QElemType e3;
			printf("���ȴ�������\n");
			printf("���������Ԫ�ظ�����");
			scanf_s("%d", &x1);
			EnQueueMany(LQ1, x1);
			GetHead(LQ1, e3);
			printf("��ͷԪ��Ϊ��%c\n", e3);
			printf("��ʱ����Ϊ��");
			PrintQueue(LQ1);
			break;
		case 4:
			printf("---------ȡ��βԪ��-------\n");
			printf("���ȴ�������\n");
			printf("���������Ԫ�ظ�����");
			scanf_s("%d", &x1);
			EnQueueMany(LQ1, x1);
			GetRear(LQ1, e3);
			printf("��βԪ��Ϊ��%c\n", e3);
			printf("��ʱ����Ϊ��");
			PrintQueue(LQ1);
			break;
		case 5:
			printf("---------Ӧ��-------\n");
			printf("����������\n");
			CreateBitTree(&T1);
			printf("�ö������Ĺ�����ȱ���Ϊ��\n");
			LevelTraver_001(T1);
			break;
		case 6:
			break;
		default:
			printf("ERROR!"); break;
		}
	} while(n3 != 6);
	printf("�˳�������ز����ɹ�������\n");
}

void BiTree_004() {
	int n4, Node,Depth1;
	DateType e1;
	BiTree T1,T2;
	do {
		InitBitTree(&T1);
		printf("\n");
		printf("**************�������Ļ���������Ӧ��***************\n");
		printf("* 1  ����                                         *\n");
		printf("* 2  ��������/��/��                             *\n");
		printf("* 3  �������                                   *\n");
		printf("* 4  ���������                                   *\n");
		printf("* 5  ����˫��                                     *\n");
		printf("* 6  �����ֵܣ���/�ң�                            *\n");
		printf("* 7  ���Һ��ӣ���/�ң�                            *\n");
		printf("* 8  Ӧ��                                         *\n");
		printf("* 9  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		cin >> n4;
		switch (n4) {
		case 1:
			printf("---------����--------\n");
			CreateBitTree(&T1);
			printf("�˶������������Ϊ��\n");
			PrintTLR(T1);
			DestroyBitree(&T1);
			break;
		case 2:
			printf("---------��������/��/��-------\n"); 
			printf("����������\n");
			CreateBitTree(&T1);
			printf("�˶������������Ϊ��\n");
			PrintTLR(T1);
			printf("�˶������������Ϊ��\n");
			InOrderTraverse(T1);
			printf("�˶������������Ϊ��\n");
			PrintLRT(T1);
			DestroyBitree(&T1);
			break;
		case 3:
			printf("---------�������-------\n");
			printf("����������\n");
			CreateBitTree(&T1);
			Node=AllNodes(T1);
			printf("������Ϊ��%d", Node);
			DestroyBitree(&T1);
			break;
		case 4:
			printf("---------���������-------\n"); 
			printf("����������\n");
			CreateBitTree(&T1);
			Depth1=Depth_01(T1);
			printf("�ö����������Ϊ��%d", Depth1);
			break;
		case 5:
			printf("---------����˫��-------\n");
			printf("����������\n");
			CreateBitTree(&T1);
			printf("�˶������������Ϊ��\n");
			PrintTLR(T1);
			printf("������Ҫ����˫�׵Ľ��ֵ��");
			cin >> e1;
			T2=Point_parents(T1, e1);
			if (T2 != NULL)
			{
				printf("�ý���˫�׽��Ϊ��");
				printf("%c", T2->date);
			}
			else
				printf("�ý����˫�׽�㣡");
			DestroyBitree(&T1);
			break;
		case 6:
			printf("---------�����ֵܣ���/�ң�-------\n");
			DateType e8;
			printf("����������\n");
			CreateBitTree(&T1);
			printf("������Ҫ�����ֵܵĽ��ֵ��");
			cin >> e8;
			T2=Point_Brother(T1, e8);
			if (T2 != NULL)
				printf("�ýڵ���ֵܽ��Ϊ��%c", T2->date);
			else
				printf("�ý�����ֵܽ�㣡");
			DestroyBitree(&T1);
			break;
		case 7:
			printf("---------���Һ��ӣ���/�ң�-------\n"); 
			DateType e5,e6;
			int num1;
			printf("����������\n");
			CreateBitTree(&T1);
			printf("������Ҫ������/�Һ��ӵĸ��ڵ�Ľ��ֵ:");
			cin >> e5;
			printf("������������1  �����Һ�������2\n");
			cin >> num1;
			if (num1 == 1)
			{
				e6=LeftChild(T1, e5);
				printf("�ý�������Ϊ��%c", e6);
			}
			else
			{
				e6=RightChild(T1, e5);
				printf("�ý����Һ���Ϊ��%c", e6);
			}
			DestroyBitree(&T1);
			break;
		case 8:
			printf("---------Ӧ��-------\n"); 
			
			break;
		case 9:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n4 != 9);
	printf("�˳���������ز����ɹ�������\n");
}

void Graph_005() {
	MGraph N1;
	int n5;
	do {
		printf("\n");
		printf("****************ͼ�Ļ���������Ӧ��*****************\n");
		printf("* 1  �������ڽӾ���/�ڽӱ�                      *\n");
		printf("* 2  ���������/��ȣ�                            *\n");
		printf("* 3  ��λ                                         *\n");
		printf("* 4  �ҵ�һ���ڽӵ�                               *\n");
		printf("* 5  ����һ���ڽӵ�                               *\n");
		printf("* 6  ���루��/�ߣ�                                *\n");
		printf("* 7  ɾ������/�ߣ�                                *\n");
		printf("* 8  Ӧ��                                         *\n");
		printf("* 9  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		cin >> n5;
		switch (n5) {
		case 1:
			printf("---------�������ڽӾ���/�ڽӱ�-------\n");
			CreateGraph(&N1);
			printf("������ͼΪ��\n");
			DisplayGraph(N1);
			break;
		case 2:
			printf("---------���������/��ȣ�-------\n"); 
			
			break;
		case 3:
			printf("---------��λ-------\n"); 
			VertexType v1;
			int num2;
			printf("������Ҫ���ҵĶ��㣺");
			cin >> v1;
			num2=LocateVertex(N1, v1);
			printf("�����λ��Ϊ��%d", num2);
			break;
		case 4:
			printf("---------�ҵ�һ���ڽӵ�-------\n"); 
			
			break;
		case 5:
			printf("---------����һ���ڽӵ�-------\n");
			
			break;
		case 6:
			printf("---------���루��/�ߣ�-------\n");
			
			break;
		case 7:
			printf("---------ɾ������/�ߣ�-------\n"); 
			
			break;
		case 8:
			printf("---------Ӧ��-------\n"); break;
		case 9:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n5 != 9);
	printf("�˳�ͼ��ز����ɹ�������\n");
}

int main()
{
	int n;
	do {
		printf("��ѡ����ز���������\n");
		printf("*******************�㷨�����ݽṹ******************\n");
		printf("* 1  ������Ļ���������Ӧ��                       *\n");
		printf("* 2  ջ�Ļ���������Ӧ��                           *\n");
		printf("* 3  ���еĻ���������Ӧ��                         *\n");
		printf("* 4  �������Ļ���������Ӧ��                       *\n");
		printf("* 5  ͼ�Ļ���������Ӧ��                           *\n");
		printf("* 6  �˳�                                         *\n");
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
		default:printf("ERROR��");
			break;
		}
	} while (n!= 6);
	printf("�˳��ɹ�������");
	return 0;
}