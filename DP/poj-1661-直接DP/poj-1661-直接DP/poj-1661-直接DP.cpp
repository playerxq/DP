// poj-1661-直接DP.cpp : 定义控制台应用程序的入口点。
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
const int inf = 0x3f3f3f3f;
int dp[1010][2];//dp[i][0]为从i号平台左边跳下用时  dp[i][1]为从右边跳下用时
struct NODE
{
	int lx,rx,h;
} plat[1010];
int MAX,N,X,Y,ans;
int cmp(const NODE& a, const NODE& b)
{
	return a.h>b.h;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&N,&X,&Y,&MAX);
		for(int i = 1;i<=N;i++)
		{
			scanf("%d%d%d",&plat[i].lx,&plat[i].rx,&plat[i].h);
			dp[i][0]=dp[i][1]=inf;
		}
		plat[0].lx=X;
		plat[0].rx=X;
		plat[0].h=Y;
		plat[N+1].lx=-20001;
		plat[N+1].rx=20001;
		plat[N+1].h=0;
		sort(plat,plat+N+2,cmp);//按高度降序
		ans = inf;
		dp[0][0]=dp[0][1]=0;
		for(int i = 0;i<=N;i++)
		{
			bool flag1 = false;
			bool flag2 = false;
			for(int j = i+1;j<=N+1;j++)
			{
				if((flag1&&flag2)||(plat[i].h-plat[j].h>MAX))
					break;
				if(plat[j].lx<=plat[i].rx&&plat[j].rx>=plat[i].rx&&plat[j].h!=plat[i].h&&!flag1)
				{
					flag1 = true;
					if(j==N+1)
						ans = min(ans,dp[i][1]);
					else if(dp[i][1]!=inf)
					{
						dp[j][0]=min(dp[j][0],dp[i][1]+plat[i].rx-plat[j].lx);
						dp[j][1] = min(dp[j][1], dp[i][1] + plat[j].rx - plat[i].rx);
					}
				}
				if (plat[j].rx >= plat[i].lx && plat[j].lx <= plat[i].lx
						&& plat[i].h != plat[j].h && !flag2) {
					flag2 = true;
					if (j == N + 1) {
						ans = min(ans, dp[i][0]);
					} else if (dp[i][1] != inf) {
						dp[j][0] = min(dp[j][0], dp[i][0] + plat[i].lx - plat[j].lx);
						dp[j][1] = min(dp[j][1], dp[i][0] + plat[j].rx - plat[i].lx);
					}
				}
			}
		}
		printf("%d\n",ans+Y);
	}
}

