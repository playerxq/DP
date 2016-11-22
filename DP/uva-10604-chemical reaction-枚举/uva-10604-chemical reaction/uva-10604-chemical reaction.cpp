// uva-10604-chemical reaction.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define INF 1<<30
int m,k;
typedef struct PP
{
	int g;
	int cost;
} pp;
pp ma[7][7];
int vis[11][11][11][11][11][11];
int d[11][11][11][11][11][11];
int t[11];
int dp(int a, int b , int c,int d1,int e, int f)
{
	if(vis[a][b][c][d1][e][f])
		return d[a][b][c][d1][e][f];
	vis[a][b][c][d1][e][f] = 1;
	d[a][b][c][d1][e][f] = INF;
	for(int i = 1;i<=6;i++)
	{
		for(int j = 1;j<=6;j++)//枚举所有组合
		{
			if(i==j&&t[i]<2) continue;
			if(t[i]>=1&&t[j]>=1)
			{
				t[i]--;
                t[j]--;
                t[ma[i][j].g]++;
                int tmp=dp(t[1],t[2],t[3],t[4],t[5],t[6]);
                if(tmp!=INF) d[a][b][c][d1][e][f] =min(tmp+ma[i][j].cost,d[a][b][c][d1][e][f] );
                t[i]++;
                t[j]++;
                t[ma[i][j].g]--;
			}
		}
	}
	if(d[a][b][c][d1][e][f] == INF)
		return d[a][b][c][d1][e][f] = 0;
	return d[a][b][c][d1][e][f];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	char op[10];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&m);
		memset(ma,0,sizeof(ma));
		memset(t,0,sizeof(t));
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
		for(int i = 1;i<=m;i++)
		{
			for(int j = 1;j<=m;j++)
			{
				scanf("%d%d",&ma[i][j].g,&ma[i][j].cost);
			}
		}
		scanf("%d",&k);
		int temp;
		for(int i = 1;i<=k;i++)
		{
			scanf("%d",&temp);
			t[temp]++;
		}
		int ans=dp(t[1],t[2],t[3],t[4],t[5],t[6]);
        printf("%d\n",ans);
        scanf("%s",op);
	}
	return 0;
}

