// hdu-1423-最长公共增序列.cpp : 定义控制台应用程序的入口点。
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
int B[501];
int len1,len2;
int a[501],b[501],c[501];
int dp[501][501];//dp[i][j] a[0:i-1] b[0:j-1]的最长增序列且结尾元素为b[j]
int index;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&len1);
		for(int i = 0;i<len1;i++)
		{
			scanf("%d",&a[i]);
		}
		scanf("%d",&len2);
		for(int i = 0;i<len2;i++)
		{
			scanf("%d",&b[i]);
		}
		memset(dp,0,sizeof(dp));
		for(int i = 1;i<=len1;i++)
		{
			for(int j = 1;j<=len2;j++)
			{
				if(a[i-1]==b[j-1])
				{
					int x,y;
					for(x = i-2;x>=0;x--)
					{
						if(a[x]<a[i-1])
							break;
					}
					if(x<0)
						x=-1;
					for(y = j-2;y>=0;y--)
					{
						if(b[y]<b[j-1])
							break;
					}
					if(y<0)
						y=-1;
					if(dp[i][j]<dp[x+1][y+1]+1)
						dp[i][j]=dp[x+1][y+1]+1;

				}
				if(dp[i-1][j]>dp[i][j])
					dp[i][j]=dp[i-1][j];
				if(dp[i][j-1]>dp[i][j])
					dp[i][j]=dp[i][j-1];
			}
		}
		printf("%d\n",dp[len1][len2]);
		if(T)
			printf("\n");
	}
}

