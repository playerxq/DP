// hdu-1493-骰子递推.cpp : 定义控制台应用程序的入口点。
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
double p[7];
int des[10]={5,12,22,29,33,38,42,46,50,55};
double dp[61][11];
int vis[61][11];
double dfs(int d, int step)//step步到达d处
{
	if(d<0)
		return 0;
	if(step==0&&d>0)
		return dp[d][step]=0;
	if(step==0&&d==0)
		return vis[0][0]=dp[0][0]=1;
	if(vis[d][step])
		return dp[d][step];
	vis[d][step]=1;
	{
		dp[d][step]=dfs(d-1,step-1)*p[1]+dfs(d-2,step-1)*p[2]+dfs(d-3,step-1)*p[3]+dfs(d-4,step-1)*p[4]+dfs(d-5,step-1)*p[5]+dfs(d-6,step-1)*p[6];
	}
	return dp[d][step];
}
void solve()//求pp[d]
{
	for(int i = 0;i<10;i++)
	{
		double sum = 0;
		for(int step = 0;step<11;step++)
		{
			memset(dp,0,sizeof(dp));
			memset(vis,0,sizeof(vis));
			sum+=dfs(des[i],step)*100;
		}
		printf("%d: %.1lf%%\n",des[i],sum);
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(p,0,sizeof(p));
		for(int i = 1;i<=6;i++)
			scanf("%lf",&p[i]);
		solve();
		if(T)
			printf("\n");
	}
}

