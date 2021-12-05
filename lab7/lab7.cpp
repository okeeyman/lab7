#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

#define MAXINT 32767

queue <int> q;

void BFS(int v, int** M, int* Dist, int Size)
{
	int i;
	q.push(v); Dist[v] = 0;
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		printf("%d ", v + 1);
		for (i = 0; i < Size; i++)
		{
			if ((Dist[i] > Dist[v] + M[v][i]) && (M[v][i] > 0))
			{
				q.push(i);
				Dist[i] = Dist[v] + M[v][i];
			}
		}
	}
}

void main()
{
	int** G = NULL, i = 0, j = 0, S = 0, * Distance = NULL, N, Ves, O;
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	printf("������� ����������� ������� ���������: "); scanf("%d", &S);
	printf("�������:\n1-���� ����������, 2-���� ������������: "); scanf("%d", &Ves);
	printf("�������:\n1-���� �����������������, 2-���� ���������������: "); scanf("%d", &O);
	while (S <= 0 || (Ves < 1 || Ves>2) || (O < 1 || O>2))
	{
		printf("����������� �������� ���������! ������� ������������� ����� (��� ��, ��� ��� ����������):\n");
		scanf("%d%d%d", &S, &Ves, &O);
	}
	G = (int**)malloc(S * sizeof(int));
	Distance = (int*)malloc(S * sizeof(int));
	for (i = 0; i < S; i++)
		Distance[i] = MAXINT;
	for (i = 0; i < S; i++)
	{
		G[i] = (int*)malloc(S * sizeof(int));
		for (j = 0; j < S; j++)
		{
			if (Ves == 1)
				G[i][j] = rand() % 10;
			else
				G[i][j] = rand() % 2;
			G[i][i] = 0;
		}
	}
	for (i = 0; i < S; i++)
	{
		printf("\n%4d|", i + 1);
		for (j = 0; j < S; j++)
		{
			if (O == 1)
				G[j][i] = G[i][j];
			printf("%2d", G[i][j]);
		}
	}
	printf("\n\n� ����� ������� ������ ����� � ������? "); scanf("%d", &N);
	while (N<1 || N>S)
	{
		printf("����������� �������� �����! ������� ����� ������������� ����� � �������� ������� ������� ���������: ");
		scanf("%d", &N);
	}
	printf("������� ������ ����� � ������ (�������� ������������� ������� � ����� � ����������� ����������):\n");

	BFS(N - 1, G, Distance, S);

	printf("\n������ ���������� �� ��������� ������� �� ���� ���������: ");
	for (i = 0; i < S; i++)
		printf("%d ", Distance[i]);
	printf("\n");
	free(Distance);
	free(G);
}