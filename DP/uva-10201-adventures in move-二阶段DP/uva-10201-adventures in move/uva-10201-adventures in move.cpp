// uva-10201-adventures in move.cpp : 定义控制台应用程序的入口点。
//题意：有t组测试数据，每组数据的开始表示终点的位置，
//然后接下来有若干对数x,y，x表示沿途的加油的位置，y表示每升油的价格。
//每组数据间有一个空行。开始的时候在位置0，油箱里有100升汽油，问最后到达终点，且油箱里还有100升汽油所需的最小花费是多少。

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
int dis;
#define INF 0x7FFFFFFF
typedef struct PPP
{
	int po;
	int pri;
} aa;
aa a[101];
int gas[10001];
int d[10001][201];//d[i][j]  位置i处有j升油
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int dis = 0;
	while(T--)
	{
		scanf("%d",&dis);
		memset(gas,0,sizeof(gas));
		memset(d,-1,sizeof(d));
		getchar();
		int cnt = 0;
		char str[1000];
		while(gets(str))
		{
			if(str[0]=='\0')
				break;
			int po,pri;
			sscanf(str,"%d%d",&po,&pri);
			a[cnt].po = po;
			gas[po] = cnt+1;//po处有cnt号加油站
			a[cnt++].pri = pri;
		}
		d[0][100] = 0;
		if(gas[0])//起点有站
		{
			for(int j = 1;j<=100;j++)
				d[0][100+j] = d[0][100]+j*a[gas[0]-1].pri;
		}
		for(int i = 1;i<=dis;i++)//考虑位置 i
		{
			for(int j = 1;j<=200;j++)
			{
				if(d[i-1][j]!=-1)//可以到i-1处 不加油到i处
				{
					if(d[i][j-1]==-1)
						d[i][j-1] = d[i-1][j];
					else
						d[i][j-1] = min(d[i][j-1],d[i-1][j]);
				}
			}
			if(gas[i])
			{
				for(int j = 200;j>=0;j--)
				{
					if(d[i][j]!=-1)//
					{
						for(int k = 0;k<=200-j;k++)//加油若干
						{
							if(d[i][j+k]==-1)
								d[i][j+k] = d[i][j]+k*a[gas[i]-1].pri;
							else
								d[i][j+k] = min(d[i][j+k],d[i][j]+k*a[gas[i]-1].pri);
						}
					}
				}
			}
		}
		int minn = INF;
		int flag = 0;
		for(int i = 100;i<=200;i++)
			if(d[dis][i]!=-1)
			{
				flag = 1;
				if(d[dis][i]<minn)
					minn = d[dis][i];
			}
		if(flag)
			printf("%d\n",minn);
		else
			printf("Impossible\n");
		if(T)
			printf("\n");
	}
	return 0;
}

