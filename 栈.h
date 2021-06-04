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

Status InitStack(SqStack& S)//初始化
{
	S.base = new SElemType[STACK_INIT_SIZE];
	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

void DestroyStack(SqStack& S)//销毁栈
{
	if (S.base) {
		free(S.base);
		S.base = NULL;
		S.top = NULL;
		S.stacksize = 0;
	}
}

Status ClearStack(SqStack& S)//清空栈
{
	if (S.base == S.top)return ERROR;
	S.top = S.base;
	return OK;
}

SElemType	GetTop(SqStack& S)//获得栈顶元素
{
	SElemType e;
	if (S.base == S.top)return ERROR;
	e = *(S.top - 1);
	return e;
}

Status Push(SqStack& S,SElemType e)//插入元素e
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

Status PushMany(SqStack& S,int n)//依次插入多个元素，n为插入个数
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
		printf("请输入第%d个元素", i + 1);
		cin >>e;
		*S.top++ = e;
	}

}

Status Pop(SqStack& S, SElemType& e)//删除栈顶元素并用e返回
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

Status PrintStack_end_head(SqStack S)//输出栈。从顶到 底出栈输出
{
	if (S.base == S.top)return ERROR;
	while (S.top!= S.base)
	{
		int e;
		Pop(S, e);
		cout << e << endl;
	}
}

Status Stackempty(SqStack S)//判断栈是否为空
{
	if (S.base == S.top)return TRUE;
}

void concersion(int N)//进制转换
{
	SqStack S; int e = 0;
	InitStack(S);
	while (N)
	{
		Push(S, N % 8);
		N = N / 8;
	}
	printf("该十进制数对应的八进制为：");
	while (S.base!=S.top)
	{
		Pop(S, e);
		cout << e;
	}
}
