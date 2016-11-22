// uva-10163-storage keeper.cpp : 定义控制台应用程序的入口点。
//双DP
/*
题意：有n个仓库（最多100个），m个管理员（最多30个），
//每个管理员有一个能力值P(接下来的一行有m个数，表示每个管理员的能力值)，
//每个仓库只能由一个管理员看管，但是每个管理员可以看管k个仓库（但是这个仓库分配到的安全值只有p/k,k=0,1,...）
//,每个月公司都要给看管员工资，雇用的管理员的工资即为他们的能力值p和，
//问，使每个仓库的安全值最高的前提下，使的工资总和最小。输出最大安全值，并且输出最少的花费。
*/
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
#define INF 0x3f3f3f3f
int n,m;
int pi[35];
int d[35][105];//i:m-1号人看管j个箱子的安全值
int c[35][105];//工资
int dp_d(int i, int j)
{
	if(d[i][j]!=-1)
		return d[i][j];
	if(j==0)//没有箱子需要看管
		return d[i][j] = INF;
	if(i==m)//没有工人
		return d[i][j] = 0;
	int k = min(pi[i],j);
	for(;k>=0;k--)//枚举第i个人看管的箱子数目
	{
		if(k)
			d[i][j] = max(d[i][j],min(pi[i]/k,dp_d(i+1,j-k)));
		else//第i个人不看
			d[i][j] = max(d[i][j],dp_d(i+1,j));
	}
	return d[i][j];
}
int dp_c(int i, int j)
{
	if(c[i][j]!=-1)
		return c[i][j];
	if(j==0)//没有箱子  工资为0
		return c[i][j] = 0;
	if(i==m)//没有工人可以雇佣
		return c[i][j] = INF;
	c[i][j] = INF;
	int k = min(pi[i],j);
	for(;k>=0;k--)
	{
		if(k)
		{//保证最优d[0][n]的基础上
			if(d[0][n]<=min(pi[i]/k,d[i+1][j-k]))//第i个keeper被雇佣
			{
				c[i][j] = min(c[i][j],pi[i]+dp_c(i+1,j-k));
			}
		}
		else
		{
			if(d[0][n]<=d[i+1][j])
				c[i][j] = min(c[i][j],dp_c(i+1,j));
		}
	}
	return c[i][j];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d",&n,&m))
	{
		if(n+m==0)
			break;
		for(int i = 0;i<m;i++)
			scanf("%d",&pi[i]);
		memset(d,-1,sizeof(d));
		memset(c,-1,sizeof(c));
		dp_d(0,n);
		dp_c(0,n);
		if(d[0][n]==0)
        puts("0 0");
        else
        printf("%d %d\n",d[0][n],c[0][n]);
	}
	return 0;
}

