// poj-2173-直接DP.cpp : 定义控制台应用程序的入口点。
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
double dp[101][41][41];//dp[i][j][k]为第一头牛在j处到第i头牛在k处
int N;
double ans;
int pos[101][41][2];
double get_dis(int x1, int y1, int x2, int y2)
{
	return sqrt(double(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(int i = 1;i<=N;i++)
	{
		scanf("%d",&pos[i][0][0]);
		for(int j = 1;j<=pos[i][0][0];j++)
		{
			scanf("%d%d",&pos[i][j][0],&pos[i][j][1]);
		}
	}
	for(int i = 0;i<101;i++)
		for(int j = 0;j<41;j++)
			for(int k = 0;k<41;k++)
				dp[i][j][k]=400000.0;
	for(int i = 1;i<=pos[1][0][0];i++)//枚举第一头牛位置
	{
		for(int j = 1;j<=pos[2][0][0];j++)//第二头牛位置
		{
			dp[2][i][j]=get_dis(pos[1][i][0],pos[1][i][1],pos[2][j][0],pos[2][j][1]);
		}
	}
	for(int i = 3;i<=N;i++)
	{
		for(int j = 1;j<=pos[1][0][0];j++)
		{
			for(int k = 1;k<=pos[i][0][0];k++)
			{
				for(int l = 1;l<=pos[i-1][0][0];l++)
				{
					dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][l]+get_dis(pos[i][k][0],pos[i][k][1],pos[i-1][l][0],pos[i-1][l][1]));
				}
			}
		}
	}
	ans = 400000.0;
	for(int i = 1;i<=pos[1][0][0];i++)
	{
		for(int j = 1;j<=pos[N][0][0];j++)
		{
			if(dp[N][i][j]+get_dis(pos[1][i][0],pos[1][i][1],pos[N][j][0],pos[N][j][1])<ans)
				ans = dp[N][i][j]+get_dis(pos[1][i][0],pos[1][i][1],pos[N][j][0],pos[N][j][1]);
		}
	}
	printf("%d\n",(int)(ans*100));
}
