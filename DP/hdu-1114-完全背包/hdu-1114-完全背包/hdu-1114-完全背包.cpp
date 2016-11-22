// hdu-1114-完全背包.cpp : 定义控制台应用程序的入口点。
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
#define maxn 10000
int dp[1000005];
int p[maxn],w[maxn],n,empty,full,tal;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int kase;
	scanf("%d",&kase);
	while(kase--)
	{
		scanf("%d%d",&empty,&full);
		tal = full-empty;//减去本身重量
		scanf("%d",&n);
		for(int i = 0;i<n;i++)
		{
			scanf("%d%d",&p[i],&w[i]);
		}
		for(int i = 0;i<=tal;i++)
			dp[i]=10000000;
		dp[0]=0;
		for(int i = 0;i<n;i++)
		{
			for(int j = w[i];j<=tal;j++)
				dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
		}
		if(dp[tal] == 10000000)  
        printf("This is impossible.\n");  
        else  
        printf("The minimum amount of money in the piggy-bank is %d.\n",dp[tal]); 
	}
}

