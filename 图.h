#pragma once
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
using namespace std;
typedef char VertexType[4];
typedef char InFoPtr;
typedef int VRType;
#define INFINTY 65535
#define MaxSizev 50
typedef enum { DG, DN, UG, UN }Graphkind;
typedef struct {
	VRType adj;
	InFoPtr* info;
}ArcNode, AdjMatrix[MaxSizev][MaxSizev];

typedef struct {
	VertexType vex[MaxSizev];
	AdjMatrix arc;
	int vexnum, arcnum;
	Graphkind kind;
}MGraph;//�ڽӾ���

int LocateVertex(MGraph N, VertexType v)//�ڶ��������в��Ҷ���v�������������������
{
	int i;
	for (i = 0; i < N.vexnum; i++)
		if (strcmp(N.vex[i], v) == 0)
			return i;
	return -1;
}

void CreateGraph(MGraph* N)//����ͼ�Ĵ���
{
	int i, j, k, w;
	VertexType v1, v2;
	printf("������������N�Ķ�������������");
	cin >> (*N).vexnum, (*N).arcnum;
	printf("�������%d�������ֵ��<%d���ַ�����\n", N->vexnum, MaxSizev);
	for (i = 0; i < N->vexnum; i++)
	{
		cin >> N->vex[i];
	}
	for (i = 0; i < N->vexnum; i++)
		for (j = 0; j < N->vexnum; j++)
		{
			N->arc[i][j].adj = INFINTY;
			N->arc[i][j].info = NULL;
		}
	printf("������%d�����Ļ�β ��ͷ Ȩֵ(�Կո���Ϊ���):\n", N->arcnum);
	for (k = 0; k < N->arcnum; k++)
	{
		scanf_s("%s%s%d", v1, v2, &w);
		i = LocateVertex(*N, v1);
		j = LocateVertex(*N, v2);
		N->arc[i][j].adj = w;
	}
	N->kind = DN;
}



void DestroyGraph(MGraph* N)//������
{
	int i, j;
	for (i = 0; i < N->vexnum; i++)
		for (j = 0; j < N->vexnum; j++)
			if (N->arc[i][j].adj != INFINTY)
				if (N->arc[i][j].info != NULL)
				{
					free(N->arc[i][j].info);
					N->arc[i][j].info = NULL;
				}
	N->vexnum = 0;
	N->arcnum = 0;
}

void DisplayGraph(MGraph N)//���ͼ
{
	int i, j;
	printf("����������%d������%d���������������ǣ�", N.vexnum, N.arcnum);
	for (i = 0; i < N.vexnum; i++)
		printf("%s", N.vex[i]);
	printf("\n������N�ģ�\n");
	printf("���i=");
	for (i = 0; i < N.vexnum; i++)
		printf("%8d", i);
	printf("\n");
	for (i = 0; i < N.vexnum; i++)
	{
		printf("%8d", i);
		for (j = 0; j < N.vexnum; j++)
			printf("%8d", N.arc[i][j].adj);
		printf("\n");
	}
}