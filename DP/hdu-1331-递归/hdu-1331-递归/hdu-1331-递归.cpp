// hdu-1331-递归.cpp : 定义控制台应用程序的入口点。
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
int a,b,c,a1,b1,c1;
long long dp[21][21][21];
int vis[21][21][21];
int solve(int a,int b, int c)
{
	if(a<=0||b<=0||c<=0)
	{
		return 1;
	}
	if(vis[a][b][c])
		return dp[a][b][c];
	vis[a][b][c]=1;
	if(a<b&&b<c)
		dp[a][b][c]=solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c);
	else
		dp[a][b][c]=solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);
	return dp[a][b][c];
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		if(a==-1&&b==-1&&c==-1)
			break;
		if(a<=0||b<=0||c<=0)
        {
            printf("w(%d, %d, %d) = %d\n",a,b,c,1);
            continue;
        }
		a1 = a;
		b1 = b;
		c1 = c;
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		if(a>20||b>20||c>20)
		{
			a = b = c = 20;
		}
		printf("w(%d, %d, %d) = %d\n",a1,b1,c1,solve(a,b,c));
	}
}

