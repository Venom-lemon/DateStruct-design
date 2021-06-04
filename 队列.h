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

Status InitQueue(LinkQueue& Q)//队列初始化
{
	Q.front = Q.rear =(QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
}
 
Status DestroyQueue(LinkQueue& Q)//队列销毁
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

int QueueEmpty(LinkQueue Q)//判断队列是否为空
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

Status EnQueue(LinkQueue& Q, QElemType e)//入队
{
	QNode* p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);
	p->date = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status EnQueueMany(LinkQueue& Q, int n)//入队
{
	QNode* p;
	QElemType e;
	for(int i=0;i<n;i++)
	{
		printf("请输入第%d个元素", i + 1);
	cin >> e;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);
	p->date = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	}
	return OK;
}

Status DeQueue(LinkQueue& Q, QElemType& e)//出队并返回元素
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

Status PrintQueue(LinkQueue &Q)//输出队列
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