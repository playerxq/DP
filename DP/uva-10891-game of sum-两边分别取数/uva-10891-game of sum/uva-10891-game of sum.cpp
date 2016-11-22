// uva-10891-game of sum.cpp : 定义控制台应用程序的入口点。
//有n个数字排成一条直线，两个人每次可以从两端（左或右）中的任意一端取走一个或若干个数（获得价值为取走数之和）， 
//但是他取走的方式一定要让他在游戏结束时价值尽量的高，
//算一下在游戏结束时，先取数的人价值与后取数人价值只差
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
int n;
int a[110];
int data[110];
int d[110][110][2];//d[i][j][k]  i:j第k个人取得最优价值
int vis[110][110][2];
int dp(int i, int j, int k)
{
	if(vis[i][j][k])
		return d[i][j][k];
	if(i>j)
	{
		vis[i][j][k] = 1;
		d[i][j][k] = 0;
		return 0;
	}
	int res=-2000000000;  
	for(int r = 1;r<j-i+2;r++)
	{
		res = max(res,data[j]-data[i-1]-dp(i+r,j,k^1));//从i端依次去除1,2...j-i+1个数
		res = max(res,data[j]-data[i-1]-dp(i,j-r,k^1));//从j端依次去除1,2...j-i+1个数
	}	
	vis[i][j][k] = 1;
	d[i][j][k] = res;
	return res;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		memset(a,0,sizeof(a));
		memset(data,0,sizeof(data));
		int sum = 0;
		for(int i = 0;i<n;i++)
		{
			scanf("%d",&a[i]);
			data[i]+=(data[i-1]+a[i]); 
			sum+=a[i];
		}
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		dp(0,n-1,0);
		printf("%d\n",2*d[0][n-1][0]-sum);//d[0][n-1][0]-(sum-d[0][n-1][0])
	}
	return 0;
}

