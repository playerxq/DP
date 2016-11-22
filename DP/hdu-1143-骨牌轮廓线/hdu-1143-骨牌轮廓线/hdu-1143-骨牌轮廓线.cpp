// hdu-1143-骨牌轮廓线.cpp : 定义控制台应用程序的入口点。


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
const int maxn=40;
const int ST = 17;//0表示有骨牌 1表示没有 一行至多30个格子 
int dp[35][5][ST];//dp[i][j][k]表示推到(i,j)时且(i,j)未判断时 上一行(i-1,j)到本行(i,j-1)组成的(i,1):(i,j-1)+(i-1,j):(i-1,w)共w个数组成状态k 的数目
int h,w;
void solve()
{
	for(int i = 1;i<=h+1;i++)
	{
		for(int j = 1;j<=w;j++)
		{
			for(int k = 0;k<(1<<(w+1));k++)
				dp[i][j][k]=0;
		}
	}
	dp[1][1][0]=1;
	for(int i = 1;i<=h;i++)
	{
		for(int j = 1;j<=w;j++)//考察当前行的每个位置
		{
			for(int k = 0;k<(1<<(w+1));k++)
			{
				if(k&(1<<j))//k的第j位恰为上一行j位 
				{
					//置0则对(i,j+1)来说第j位为0 其余位与k一样
					if(j<w)
						dp[i][j+1][k^(1<<j)]+=dp[i][j][k];//j+1位的k状态是1:i的完全状态
					else
						dp[i+1][1][k^(1<<j)]+=dp[i][j][k];//j= 1时k恰好是上一行的整行状态
				}
				else//上一行有牌
				{
					if(k&(1<<(j-1)))//j-1位恰为本行的前一个位置的状态
					{
						//与前一个位置一起放一个骨牌 即位置清0
						if(j<w)
							dp[i][j+1][k^(1<<(j-1))]+=dp[i][j][k];//其余位不变
						else
							dp[i+1][1][k^(1<<(j-1))]+=dp[i][j][k];//其余位不变
					}
					//当前位置保持1 为空的
					if(j<w)
						dp[i][j+1][k|(1<<(j))]+=dp[i][j][k];
					else
						dp[i+1][1][k|(1<<(j))]+=dp[i][j][k];
				}
			}
		}
	}
	printf("%d\n",dp[h+1][1][0]);//j=1时k恰好是上一行的整行状态
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&h)!=EOF)
	{
		if(h==-1)
			break;
		if(h==0)
		{
			printf("1\n");
			continue;
		}
		if(h==1)
		{
			printf("0\n");
			continue;
		}
		w=3;
		solve();
	}
}





