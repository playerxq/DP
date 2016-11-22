// uva-10564-path from hourglass.cpp : 定义控制台应用程序的入口点。
//给你2*n-1行
//第一行有n个，第n行有1个，然后第2*n-1行有n个，一个沙漏状
//里面每个单元都有一个数字
//给你S，问你从顶走到底，和为S有多少种，并输出其中字典序最小的路径

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
int n,s;
int a[40][21];
long long d[40][21][501];//d[i][j][k]到达第i行j列合为k的路径数
void rever()
{
	for(int i = 0;i<n-1;i++)
	{
		for(int j = 0;j<n-i;j++)
		{
			int temp = a[i][j];
			a[i][j] = a[2*n-2-i][j];
			a[2*n-2-i][j] = temp;
		}
	}
}
void dfs(int x, int y, int sum) {  
    if (x >= 2 * (n - 1))  
        return ;  
   
    if (x < n - 1) {  
        if (y && d[x + 1][y - 1][sum - a[x][y]]) {  
            printf("L");  
            dfs(x + 1, y - 1, sum - a[x][y]);  
        }  
        else if (d[x + 1][y][sum - a[x][y]]) {  
            printf("R");  
            dfs(x + 1, y, sum - a[x][y]);  
        }  
    }  
    else {  
        if (d[x + 1][y][sum - a[x][y]]) {  
            printf("L");  
            dfs(x + 1, y, sum - a[x][y]);  
        }  
        else if (d[x + 1][y + 1][sum - a[x][y]]) {  
            printf("R");  
            dfs(x + 1, y + 1, sum - a[x][y]);  
        }  
    }  
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d",&n,&s))
	{
		if(n==0&&s==0)
			break;
		memset(a,-1,sizeof(a));
		int flag = 1;
		for(int i = 0;i<2*n-1;i++)
		{
			if(flag)
			{
				for(int j = 0;j<n-i;j++)
				{
					scanf("%d",&a[i][j]);
					if(i==n-1)
						flag = 0;
				}
			}
			else
			{
				for(int j = 0;j<i-n+2;j++)
					scanf("%d",&a[i][j]);
			}
		}
		memset(d,0,sizeof(d));
		for(int i = 0;i<n;i++)
			d[2*n-2][i][a[2*n-2][i]] = 1;//最后一行
		for(int i = 2*n-3;i>=n-1;i--)//从下向上
		{
			for(int j = 0;j<i-n+2;j++)//每一列
			{
				for(int k = a[i][j];k<=s;k++)//所有可能产生的数值
				{
					if(d[i+1][j][k-a[i][j]])//(i,j)可以由(i+1,j)或者(i+1,j+1)得到
					{
						d[i][j][k] = d[i+1][j][k-a[i][j]];
					}
					if(d[i+1][j+1][k-a[i][j]])
					{
						d[i][j][k] += d[i+1][j+1][k-a[i][j]];
					}
				}
			}
		}
		for(int i = n-2;i>=0;i--)
		{
			for(int j = 0;j<n-i;j++)
			{
				if(j==0)//(i,j)只能由(i+1,j)得到
				{
					for(int k = a[i][j];k<=s;k++)
					{
						if(d[i+1][j][k-a[i][j]])
						{
							d[i][j][k] = d[i+1][j][k-a[i][j]];
						}
					}
				}
				else if(j==n-i-1)//只能由(i+1,j-1)得到
				{
					for(int k = a[i][j];k<=s;k++)
					{
						if(d[i+1][j-1][k-a[i][j]])
						{
							d[i][j][k] = d[i+1][j-1][k-a[i][j]];
						}
					}
				}
				else
				{
					for(int k = a[i][j];k<=s;k++)
					{
						if(d[i+1][j-1][k-a[i][j]])
						{
							d[i][j][k] = d[i+1][j-1][k-a[i][j]];
						}
						if(d[i+1][j][k-a[i][j]])
						{
							d[i][j][k] += d[i+1][j][k-a[i][j]];
						}
					}
				}
			}
		}
		long long ans = 0;
		int index_i = -1;
		for(int i = 0;i<n;i++)
		{
			if(d[0][i][s])
			{
				ans+=d[0][i][s];
				if(index_i == -1)
					index_i = i;
			}
		}
		printf("%lld\n",ans);
		if(ans==0)
			printf("\n");
		else
		{
			printf("%d ",index_i);
			dfs(0,index_i,s);
			printf("\n");
		}
	}
	return 0;
}
