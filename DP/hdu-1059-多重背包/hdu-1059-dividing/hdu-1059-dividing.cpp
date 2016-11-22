// hdu-1059-dividing.cpp : 定义控制台应用程序的入口点。
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
int dp[60011];

void init()
{
	memset(dp,0,sizeof(dp));
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int kase = 1;
	int t[7];
    int sum;
	while(scanf("%d",&t[1])!=-1)
	{
		//init();
		sum=t[1];

		for(int i = 2;i<=6;i++)
		{
			scanf("%d",&t[i]);
			sum+=t[i]*i;
		}
		if(sum==0)
			break;
		printf("Collection #%d:\n",kase++);
		if(sum%2==1)
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		else
		{
			int k,l,i;
			sum/=2;
			for(l = 1;l<=sum;l++)
				dp[l]=0;
			for(k = 0;k<=t[1]&&k<=sum;k++)
				dp[k]=1;
			for(int i = 2;i<=6;i++)
			{
				for(l = sum;l>=0;l--)
				{
					if(dp[l]==0)
						continue;
					for(k= 1;k<=t[i]&&l+k*i<=sum;k++)
					{
						if(dp[l+k*i]) break;
						dp[l+k*i]=1;
					}
				}
			}
			if(dp[sum])
				printf("Can be divided.\n\n");
			else
				printf("Can't be divided.\n\n");
		}
	}
}

