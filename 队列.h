#pragma once
#include<iostream>
#define OK 1
#define ERROR 0
#define TRUE 1;
using namespace std;
typedef char QElemType;
typedef int Status;

typedef struct QNode {
	QElemType date;
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue& Q)//���г�ʼ��
{
	Q.front = Q.rear =(QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
}
 
Status DestroyQueue(LinkQueue& Q)//��������
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

int QueueEmpty(LinkQueue Q)//�ж϶����Ƿ�Ϊ��
{
	if (Q.rear == Q.front)
		return 1;
	else
		return 0;
}

Status GetHead(LinkQueue Q, QElemType& e)
{
	QNode* s;
	if (Q.front == Q.rear)
		return 0;
	else
	{
		s = Q.front->next;
		e = s->date;
		return 1;
	}
}

Status GetRear(LinkQueue Q, QElemType& e)
{
	if (Q.front == Q.rear)
		return ERROR;
	else
	{
		e = Q.rear->date;
		return 1;
	}
}

Status EnQueue(LinkQueue& Q, QElemType e)//���
{
	QNode* p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);
	p->date = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status EnQueueMany(LinkQueue& Q, int n)//���
{
	QNode* p;
	QElemType e;
	for(int i=0;i<n;i++)
	{
		printf("�������%d��Ԫ��", i + 1);
	cin >> e;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);
	p->date = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	}
	return OK;
}

Status DeQueue(LinkQueue& Q, QElemType& e)//���Ӳ�����Ԫ��
{
	QNode* p;
	if (Q.front == Q.rear)return ERROR;
	p = Q.front->next;
	e = p->date;
	Q.front->next = p->next;
	if (Q.rear == p)Q.rear = Q.front;
	free(p);
	return OK;
}

Status PrintQueue(LinkQueue &Q)//�������
{
	while (Q.front!=Q.rear)
	{
		QElemType e;
		DeQueue(Q, e);
		cout << e;
		printf("\t");
	}
	return OK;
}