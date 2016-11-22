// hdu-1243-LCS变体.cpp : 定义控制台应用程序的入口点。
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
const int maxn = 2005;
char a[maxn];
char b[maxn];
int val[27];
char in_val[maxn];
int n,len1,len2;
int dp[maxn][maxn];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		memset(in_val,0,sizeof(in_val));
		memset(val,0,sizeof(val));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%s",in_val);
		for(int i = 0;i<n;i++)
		{
			int v;
			scanf("%d",&v);
			val[in_val[i]-'a']=v;
		}
		scanf("%s",a);
		scanf("%s",b);
		len1 = strlen(a);
		len2 = strlen(b);
		memset(dp,0,sizeof(dp));
		for(int i = 1;i<=len1;i++)
		{
			for(int j = 1;j<=len2;j++)
			{
				if(a[i-1]==b[j-1])
					dp[i][j]=max(dp[i][j],dp[i-1][j-1]+val[a[i-1]-'a']);
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
				dp[i][j]=max(dp[i][j],dp[i][j-1]);
			}
		}
		printf("%d\n",dp[len1][len2]);
	}
}

