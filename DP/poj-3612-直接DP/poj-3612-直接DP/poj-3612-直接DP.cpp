// poj-3612-直接DP.cpp : 定义控制台应用程序的入口点。
//dp[i][j]表示第i个高度为j时前i个的最小值，很容易想到这样一个递推关系式：dp[i][j] = min(dp[i-1][k] + abs(k-j) * C + (num[i] - j) * (num[i] - j))
//优化
//对于k < j有：dp[i][j]=j*c+(num[i]-j)*(num[i]-j)+min(dp[i-1][k]-k*c) (1<=k<=j)
//k>=j dp[i][j]=-j*c+(num[i]-j)*(num[i]-j)+min(dp[i-1][k]+k*c) (j<k<=m)
//low[j]表示min(dp[i-1][k]-k*c)(1<=k<=j) high[j]=min(dp[i-1][k]+k*c)(j<k<=m) 预处理
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
int n,c;
int h[100010];
int dp[101];
int low[110];
int high[110];
void init()
{
	for(int i = 0;i<h[1];i++)
		dp[i]=inf;
	for(int i = h[1];i<101;i++)
	{
		dp[i]=(i-h[1])*(i-h[1]);
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&c);
	for(int i = 1;i<=n;i++)
	{
		scanf("%d",&h[i]);
	}
	for (int i = 0; i < h[1]; i++) dp[i] = inf;
	for (int i = h[1]; i <= 100; i++) dp[i] = (i-h[1])*(i-h[1]);
	for(int i = 2;i<=n;i++)
	{
		low[0] = inf;
		for (int j = 1; j <= 100; j++) {
			low[j] = min(low[j - 1], dp[j] - j * c);
		}
		high[101] = inf;
		for (int j  = 100; j >= 1; j--) {
			high[j] = min(high[j + 1], dp[j] + j * c);
		}
		memset(dp, 0x3f, sizeof(dp));
		for(int j = h[i];j<101;j++)
		{
			dp[j] = min(low[j] + j * c + (h[i]-j)*(h[i]-j), high[j] - j * c + (h[i]-j)*(h[i]-j));
		}
	}
	int ans = inf;
	for (int i = h[n]; i <101; i++) {
		ans = min(ans, dp[i]);
	}
	printf("%d\n",ans);
}
