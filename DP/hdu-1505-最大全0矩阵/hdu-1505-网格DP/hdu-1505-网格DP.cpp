// hdu-1505-网格DP.cpp : 定义控制台应用程序的入口点。
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
int map[1002][1002];
int l[1002][1002];
int r[1002][1002];
int h,w;
char c[50];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&h,&w);
		for(int i = 1;i<=w;i++)
			map[0][i]=0;//最上面加一行即没有0
		for(int i = 1;i<=h;i++)
		{
			for(int j = 1;j<=w;j++)
			{
				scanf("%s ",c);
				if(c[0]=='F')
					map[i][j]=map[i-1][j]+1;//当前行以及上部含有的0个数
				else
					map[i][j]=0;
			}
		}
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		//找最大的全0矩阵
		int maxx = -1;
		for(int i = 1;i<=h;i++)
		{
			map[i][0]=map[i][w+1]=-1;
			for(int j = 1;j<=w;j++)
			{
				l[i][j] = r[i][j]= j;
			}
				for(int k = 2;k<=w;k++)
				{
					while(map[i][l[i][k]-1]>=map[i][k])
						l[i][k]=l[i][l[i][k]-1];
				}
				for(int k = w-1;k>=1;k--)
				{
					while(map[i][r[i][k]+1]>=map[i][k])
						r[i][k]=r[i][r[i][k]+1];
				}
				for(int k = 1;k<=w;k++)
				{
					if(map[i][k]*(r[i][k]-l[i][k]+1)>maxx)
						maxx = map[i][k]*(r[i][k]-l[i][k]+1);
				}
		}
		printf("%d\n",maxx*3);
	}
}

