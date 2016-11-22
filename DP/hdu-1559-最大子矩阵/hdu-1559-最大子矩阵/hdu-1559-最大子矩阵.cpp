// hdu-1559-最大子矩阵.cpp : 定义控制台应用程序的入口点。
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
int m,n,x,y;
int map[1001][1001];
int sum[1001];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&m,&n,&x,&y);
		memset(map,0,sizeof(map));
		for(int i = 1;i<=m;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		for(int i = 1;i<=m;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				map[i][j]+=map[i-1][j];
			}
		}
		int maxx = -1;
		for(int i = 1;i<=m;i++)
		{
			memset(sum,0,sizeof(sum));
			for(int j = 1;j<=n;j++)
			{
				if(i+x-1<m&&j+y-1<n)
				{
					if(j==1)
					{
						for(int k = 1;k<=y;k++)
						{
							sum[1]+=map[i+x-1][k]-map[i-1][k];
						}
					}
					else
					{
						sum[j]=sum[j-1]-(map[i+x-1][j-1]-map[i-1][j-1])+(map[i+x-1][j+y-1]-map[i-1][j+y-1]);
						if(sum[j]>maxx)
							maxx=sum[j];
					}
				}
			}
		}
		printf("%d\n",maxx);
	}
}

