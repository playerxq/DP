// uva-11137-ingenuous cuprency.cpp : 定义控制台应用程序的入口点。
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
#define M 10005  
int coin[21] = {1 ,8 ,27 ,64 ,125 ,216 ,343 ,512 ,729 ,1000 ,1331 ,1728 ,2197 ,2744 ,  
                3375 ,4096,4913 ,5832 ,6859 ,8000 ,9261};  
long long dp[M];  
int n;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	dp[0] = 1;
	for(int i = 0;i<=20;i++)
	{
		for(int j = coin[i];j<M;j++)
		{
			if(dp[j-coin[i]])
				dp[j] += dp[j-coin[i]];
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",dp[n]);
	}
	return 0;
}

