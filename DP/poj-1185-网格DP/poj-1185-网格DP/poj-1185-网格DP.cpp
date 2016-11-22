// poj-1185-����DP.cpp : �������̨Ӧ�ó������ڵ㡣
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
int dp[2][1025][1025];//dp[i][j][k]Ϊ��i��״̬j i-1��״̬k�ķ����� dp[i][j][k]=max(..,dp[i-1][k][l]+num[j])(ö��lΪi-2�е�״̬);
int num[1025];//ÿ��״̬��1����Ŀ  ��һ���з����ڱ���Ŀ
int n,m;
int map[101][11];
vector<int> ve;
vector<int> state[101];//ÿһ�еĺϷ�״̬
bool ok(int state, int r)
{
	for(int c = 0;c<m;c++)
	{
		if(map[r][c]==0&&(state&(1<<c)))
			return false;
	}
	return true;
}
void init()
{
	ve.clear();
	int pre = -1;
	for(int i = 0;i<(1<<(m));i++)//��ÿ�����ܵ�״̬
	{
		int j;
		pre = -1;
		for(j = 0;j<m;j++)
		{
			if(i&(1<<j))
			{
				if(pre==-1)
					pre=j;
				else
				{
					if(abs(j-pre)<=2)
					{
						break;
					}
					else
					{
						pre = j;
						continue;
					}
				}
			}
		}
		if(j==m)
			ve.push_back(i);
	}
	memset(num,0,sizeof(num));
	for(int i = 0;i<ve.size();i++)
	{
		for(int j = 0;j<m;j++)
		{
			if(ve[i]&(1<<j))
				num[ve[i]]++;
		}
	}
	for(int i = 0;i<n;i++)
		state[i].clear();
	for(int r = 0;r<n;r++)
	{
		for(int i = 0;i<ve.size();i++)
		{
			if(ok(ve[i],r))
				state[r].push_back(ve[i]);
		}
	}
}

bool ok1(int sta1,int sta2)
{
	if(sta1&sta2)
		return false;
	return true;
}
char str[11];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	memset(map,0,sizeof(map));
	for(int i = 0;i<n;i++)
	{
		scanf("%s",str);
		for(int j = 0;j<m;j++)
		{
			if(str[j]=='P')
				map[i][j]=1;
			else
				map[i][j]=0;
		}
	}
	init();
	int maxx = -1;
	for(int i = 0;i<state[0].size();i++)
	{
		dp[0][state[0][i]][0]=num[state[0][i]];
		if(dp[0][state[0][i]][0]>maxx)
			maxx = dp[0][state[0][i]][0];
	}
	if(n==1)
	{
		printf("%d\n",maxx);
		return 0;
	}
	maxx = -1;
	for(int i = 0;i<state[1].size();i++)
	{
		for(int j = 0;j<state[0].size();j++)
		{
			if(ok1(state[1][i],state[0][j]))
			{
				dp[1][state[1][i]][state[0][j]]=max(dp[1][state[1][i]][state[0][j]],dp[0][state[0][j]][0]+num[state[1][i]]);
				if(dp[1][state[1][i]][state[0][j]]>maxx)
					maxx = dp[1][state[1][i]][state[0][j]];
			}
		}
	}
	if(n==2)
	{
		printf("%d\n",maxx);
		return 0;
	}
	maxx = -1;
	for(int r = 2;r<n;r++)
	{
		memset(dp[r&1],0,sizeof(dp[r&1]));
		for(int i = 0;i<state[r].size();i++)
		{
			for(int j = 0;j<state[r-1].size();j++)
			{
				if(ok1(state[r][i],state[r-1][j]))
				{
					for(int k = 0;k<state[r-2].size();k++)
					{
						if(ok1(state[r][i],state[r-2][k])&&ok1(state[r-1][j],state[r-2][k]))
						{
							dp[r&1][state[r][i]][state[r-1][j]]=max(dp[r&1][state[r][i]][state[r-1][j]],dp[(r-1)&1][state[r-1][j]][state[r-2][k]]+num[state[r][i]]);
							if(r==n-1)
								if(dp[r&1][state[r][i]][state[r-1][j]]>maxx)
									maxx = dp[r&1][state[r][i]][state[r-1][j]];
						}
					}
				}
			}
		}
	}
	printf("%d\n",maxx);
}

