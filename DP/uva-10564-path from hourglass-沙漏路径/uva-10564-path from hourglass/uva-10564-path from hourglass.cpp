// uva-10564-path from hourglass.cpp : �������̨Ӧ�ó������ڵ㡣
//����2*n-1��
//��һ����n������n����1����Ȼ���2*n-1����n����һ��ɳ©״
//����ÿ����Ԫ����һ������
//����S������Ӷ��ߵ��ף���ΪS�ж����֣�����������ֵ�����С��·��

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
long long d[40][21][501];//d[i][j][k]�����i��j�к�Ϊk��·����
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
			d[2*n-2][i][a[2*n-2][i]] = 1;//���һ��
		for(int i = 2*n-3;i>=n-1;i--)//��������
		{
			for(int j = 0;j<i-n+2;j++)//ÿһ��
			{
				for(int k = a[i][j];k<=s;k++)//���п��ܲ�������ֵ
				{
					if(d[i+1][j][k-a[i][j]])//(i,j)������(i+1,j)����(i+1,j+1)�õ�
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
				if(j==0)//(i,j)ֻ����(i+1,j)�õ�
				{
					for(int k = a[i][j];k<=s;k++)
					{
						if(d[i+1][j][k-a[i][j]])
						{
							d[i][j][k] = d[i+1][j][k-a[i][j]];
						}
					}
				}
				else if(j==n-i-1)//ֻ����(i+1,j-1)�õ�
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
