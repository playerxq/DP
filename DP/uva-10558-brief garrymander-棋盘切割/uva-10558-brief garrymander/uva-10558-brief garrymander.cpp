// uva-10558-brief garrymander.cpp : 定义控制台应用程序的入口点。
//一个棋盘，横竖线都是从1到100标号（竖线从左到右标，横线从下到上标），
//输入n表示有n个被标记的格子，是给出这个格子的左下角坐标，然后输入m，在输入m个数，
//表示在这些竖线的地方切开棋盘（其实只切了m-2刀，因为2刀必须是1和100，相当于没有），
//然后输入A，表示你要在横上上切A刀（其实也只是A-2刀，因为2刀必须在横线的1和100）。
//那么就可以把棋盘很多个大小不一的方块（矩形），只要这些方块中有被标记的小格子（1个或多个），
//那么这个方块就是一个选区，我们是要使到选区的个数最多
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <climits>  
#include <algorithm>
using namespace std;
int n,s,tot;
int street[10005];
int avenue[10005];
int d[105][105];//d[i][j] 第i行切了一刀 从i+1行开始切下一刀且再切j刀
int p[105][105];
int street_cut[105];
int num[105][105];//i行下方在j-1:j竖线切割之间小块组成的行数目
int g[105][105];
int solve()
{
	memset(g,0,sizeof(g));
	memset(num,0,sizeof(num));
	memset(d,-1,sizeof(d));
	for(int i = 0;i<n;i++)//对每个小块
	{
		int j;
		for(j = 1;j<s;j++)
		{
			if(street[i]<street_cut[j])//处于第j条street割线左边
			{
				break;
			}
		}
		g[avenue[i]+1][j] = 1;//第j-1:j条割线在avenue[i]+1线下方有小块 合并属于同一个竖线区间的小块
	}
	for(int i = 1;i<101;i++)
	{
		for(int j = 1;j<s;j++)
		{
			num[i][j] = num[i-1][j]+g[i][j];//以两个切割竖线间的行为单位，计算第j-1与第j条竖割线之间含有黑块的行的数目
		}
	}
	return 0;
}
int dp(int i, int j)//i行  还剩j刀 考虑下一刀从i+1行起
{
	if(d[i][j]!=-1)
		return d[i][j];
	d[i][j] = 0;
	if(j==0)
	{
		for(int k = 1;k<s;k++)
		{
			if(num[100][k]-num[i][k])//若干行并做一个小块
				d[i][j]++;
		}
		p[i][j] = 100;
		return d[i][j];
	}
	for(int k = i+1;k<=100-j;k++)//k+1:99需要至少j-1刀  即k = 100-j
	{
		int ans = 0;
		for(int t = 1;t<s;t++)
		{
			if(num[k][t]-num[i][t])
				ans++;
		}
		if(dp(k,j-1)+ans>d[i][j])
			p[i][j] = k;
		d[i][j] = max(d[i][j],dp(k,j-1)+ans);
	}
	return d[i][j];
}
void output(int i, int j)
{
	int k = p[i][j];
	if(k==100)
		return;
	printf(" %d",p[i][j]);
	output(k,j-1);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&n))
	{
		if(n==-1)
			break;
		int st,av;
		for(int i = 0;i<n;i++)
		{
			scanf("%d%d",&st,&av);
			street[i] = st;
			avenue[i] = av;
		}
		scanf("%d",&s);
		int x = 1;
		for(int i = 0;i<s;i++)
		{
			scanf("%d",&street_cut[i]);
		}
		scanf("%d",&tot);
		if(tot==2)//1 100切2刀
		{
			printf("2 1 100\n");
			continue;
		}
		printf("%d 1", tot);
		solve();
		dp(1,tot-2);
		output(1,tot-2);
		printf(" 100\n");
	}
	return 0;
}

