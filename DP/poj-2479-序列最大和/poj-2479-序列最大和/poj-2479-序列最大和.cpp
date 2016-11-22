// poj-2479-序列最大和.cpp : 定义控制台应用程序的入口点。
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
const int MAXN = (50000 + 50);
const long long  inf = 1LL << 60;
int n;
long long dp1[MAXN], dp2[MAXN];
long long num[MAXN],ans;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 1;i<=n;i++)
			scanf("%lld",&num[i]);
		dp1[1]=num[1];
		for(int i = 2;i<=n;i++)
			dp1[i]=max(dp1[i-1]+num[i],num[i]);
		for(int i = 2;i<=n;i++)
			dp1[i]=max(dp1[i-1],dp1[i]);
		dp2[n]=num[n];
		for(int i = n-1;i>=1;i--)
			dp2[i]=max(dp2[i+1]+num[i],num[i]);
		for(int i = n-1;i>=1;i--)
			dp2[i]=max(dp2[i+1],dp2[i]);
		ans = -inf;
		for(int i = 1;i<n;i++)
		{
			if(dp1[i]+dp2[i+1]>ans)
				ans = dp1[i]+dp2[i+1];
		}
		printf("%lld\n",ans);
	}
}

