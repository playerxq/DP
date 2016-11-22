// poj-1088-记忆化搜索.cpp : 定义控制台应用程序的入口点。
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
int vis[101][101];
int dp[101][101];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int map[101][101],maxx,r,c;
int ok(int i, int j)
{
	return ((i>=0&&i<=r-1)&&(j>=0&&j<=c-1));
}
int dfs(int i, int j)
{
	if(vis[i][j])
		return dp[i][j];
	vis[i][j]=1;
	int maxx = 0;
	for(int d = 0;d<4;d++)
	{
		int nx = i+dir[d][0];
		int ny = j + dir[d][1];
		if(ok(nx,ny)&&map[nx][ny]<map[i][j])
		{
			maxx = max(maxx,dfs(nx,ny));
		}
	}
	dp[i][j]=1+maxx;
	return dp[i][j];
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&r,&c);
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	for(int i = 0;i<r;i++)
	{
		for(int j = 0;j<c;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	maxx = 0;
	for(int i = 0;i<r;i++)
	{
		for(int j = 0;j<c;j++)
		{
			maxx = max(maxx,dfs(i,j));
		}
	}
	printf("%d\n",maxx);
}

