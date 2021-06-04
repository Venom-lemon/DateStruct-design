#pragma once
#include<iostream>
#define STACK_INIT_SIZE 10000
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define TRUE 1;
using namespace std;
typedef int SElemType;
typedef int Status;

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

Status InitStack(SqStack& S)//��ʼ��
{
	S.base = new SElemType[STACK_INIT_SIZE];
	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

void DestroyStack(SqStack& S)//����ջ
{
	if (S.base) {
		free(S.base);
		S.base = NULL;
		S.top = NULL;
		S.stacksize = 0;
	}
}

Status ClearStack(SqStack& S)//���ջ
{
	if (S.base == S.top)return ERROR;
	S.top = S.base;
	return OK;
}

SElemType	GetTop(SqStack& S)//���ջ��Ԫ��
{
	SElemType e;
	if (S.base == S.top)return ERROR;
	e = *(S.top - 1);
	return e;
}

Status Push(SqStack& S,SElemType e)//����Ԫ��e
{
	if (S.top - S.base > S.stacksize) {
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base)exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

Status PushMany(SqStack& S,int n)//���β�����Ԫ�أ�nΪ�������
{
	SElemType e;
	for (int i = 0; i < n; i++)
	{
		if (S.top - S.base > S.stacksize) {
			S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
			if (!S.base)exit(OVERFLOW);
			S.top = S.base + S.stacksize;
			S.stacksize += STACKINCREMENT;
		}
		printf("�������%d��Ԫ��", i + 1);
		cin >>e;
		*S.top++ = e;
	}

}

Status Pop(SqStack& S, SElemType& e)//ɾ��ջ��Ԫ�ز���e����
{
	if (S.base == S.top)return ERROR;
	e = *--S.top;
	return OK;
}

Status PrintStack_head_end(SqStack S)
{
	if (S.base == S.top)return ERROR;
	SElemType* p=S.base;
	while ( p!=S.top)
	{
		cout << *p<<endl;
		p++;
	}
	return OK;
}

Status PrintStack_end_head(SqStack S)//���ջ���Ӷ��� �׳�ջ���
{
	if (S.base == S.top)return ERROR;
	while (S.top!= S.base)
	{
		int e;
		Pop(S, e);
		cout << e << endl;
	}
}

Status Stackempty(SqStack S)//�ж�ջ�Ƿ�Ϊ��
{
	if (S.base == S.top)return TRUE;
}

void concersion(int N)//����ת��
{
	SqStack S; int e = 0;
	InitStack(S);
	while (N)
	{
		Push(S, N % 8);
		N = N / 8;
	}
	printf("��ʮ��������Ӧ�İ˽���Ϊ��");
	while (S.base!=S.top)
	{
		Pop(S, e);
		cout << e;
	}
}
