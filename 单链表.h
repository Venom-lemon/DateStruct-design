#pragma once
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#define ERROR 0
#define OK 1
using namespace std;
typedef int ElemType;
typedef int Status;

typedef struct LNode {
	ElemType date;
	struct LNode* next;
} LNode, * LinkList;

int length(LinkList L) //������ͳ��
{
	LNode* p;
	p = L -> next;
	int j = 0;
	while (p!=NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}

void OutputLink(LinkList L)//�������
{
	LNode* p;
	for (p = L->next; p != NULL; p = p->next)
	{
		printf("%d\t", p->date);
	}
}

void CreateList_1(LinkList& L, int n)//��������-β�巨
{
	int i;
	LinkList p, r;
	L = (LinkList)malloc(sizeof(LNode));
	r = L;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		printf("�������%dԪ��:", i + 1);
		cin >> p->date;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	OutputLink(L);//�������������
}

void CreateList_2(LinkList& L)//��������--���ƶ������Ĵ���
{
	ElemType ch;
	cin >> ch;
	if (ch == '#')
	{
		L = NULL;
	}
	else
	{
		L = (LinkList)malloc(sizeof(LNode));
		if (!L)exit(-1);
		L->date = ch;
		CreateList_2(L->next);
	}
}

Status CreateList_3(LinkList& L, int n)//ͷ�巨
{
	int i;
	LinkList s;
	L = new LNode;
	L->next = NULL;
	for (i = 0; i < n; i++)
	{
		s = new LNode;
		if (!s)return ERROR;
		printf("�������%dԪ��:", i + 1);
		cin >> s->date;
		s->next = L->next;
		L->next = s;
	}
	return OK;
}

Status GetElem_L(LinkList L, int i, ElemType& e)//���ָ��λ�õ�Ԫ��
{
	int j=1; LNode* p;							
	p = L->next;							//����i��Ԫ�ش���ʱ����ֵ����e������OK,���򷵻�ERROR
	while (p && j < i) 
	{
		p = p->next; ++j;
	}
	if (!p || j > i)return ERROR;
	e = p->date; 
	return OK;
}

Status ListInsert(LinkList& L, int i, ElemType e)//����Ԫ��
{
	int j;
	LinkList s,p;
	p = L; j = 0;
	while (p && j < i - 1) { p = p->next; ++j; }
	if (!p || j > i - 1)return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->date = e; s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList& L, int i, ElemType& e)//ɾ��ָ��Ԫ��
{
	int j;
	LNode* p,*q;
	p = L; j = 0;
	while (p->next && j < i - 1) {
		p = p->next; ++j;
	}
	if ((!p->next) || j > i - 1)return ERROR;
	q = p->next; p->next = q->next;
	e = q->date; free(q);
	return OK;
}

void DestroyLinklist(LinkList& L)//��������
{
	LNode* q=L;
	while (q)
	{
		q = L->next;
		free(L);
		L = q;
	}
}

void ClearList(LinkList& L)//�������
{
	LNode* p, * q;
	p = L->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}

void Located(LNode* L, ElemType x)//����ָ��Ԫ��λ�� 
{
	int i=0,j=1; 
	LinkList p;
	p = L->next;
	while (p)
	{
		i++;
		if (p->date == x)
		{
			j = 0;
		}
		p = p->next;
	}
	if(j)
		printf("�������޴����ݣ�����\n");
	else
	{
		printf("��Ԫ�ص�λ��Ϊ��%d\n",i);
	}
}
