// uva-116-unidirectional TSP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXM 12
#define MAXN 102
int a[MAXM][MAXN];
int d[MAXM][MAXN], vis[MAXM][MAXN];	//�±�һ�ɴ�1��ʼ
int n, m;
int next_row[MAXM][MAXN];	//!!
#define INF 1<<30
int dp(int i, int j)//i ��j�г���
{
	if(j > n) return 0;
	if(vis[i][j]) return d[i][j];
	vis[i][j] = 1;
	int dir[3];
	if(i == 1) dir[0] = 0, dir[1] = 1, dir[2] = -1;//ƽ �� �� ��֤�к���С
	else if(i == m) dir[0] = 1, dir[1] = -1, dir[2] = 0;//�� �� ƽ
	else dir[0] = -1, dir[1] = 0, dir[2] = 1;//�� ƽ ��
	int min = INF;
	for(int k = 0; k<3; k++)//3��������չ
	{ 
		int t; int row=(m+i-1+dir[k])%m+1;	 //��֤�ӵ����������������
		min = min <= (t = dp(row, j+1)+a[i][j])? min : (next_row[i][j] = row, t);	//
	}
	return d[i][j] = min;
}

void print_path(int ibest)
{
	printf("%d", ibest);	//��ӡ���
	int row = ibest;
	for(int j=1; j<n; j++)
	{
		row = next_row[row][j];
		printf(" %d", row);
	}
	printf("\n");
}

int main()
{
	while(scanf("%d%d", &m, &n) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
				scanf("%d", &a[i][j]);
		int ans = INF;
		int ibest; int t;
		for(int i=1; i<=m; i++)
			ans = ans<=(t = dp(i, 1))? ans : (ibest=i, t);
		print_path(ibest);
		printf("%d\n", ans);
	}
}

