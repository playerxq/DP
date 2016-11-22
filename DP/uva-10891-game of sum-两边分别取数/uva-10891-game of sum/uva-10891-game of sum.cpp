// uva-10891-game of sum.cpp : �������̨Ӧ�ó������ڵ㡣
//��n�������ų�һ��ֱ�ߣ�������ÿ�ο��Դ����ˣ�����ң��е�����һ��ȡ��һ�������ɸ�������ü�ֵΪȡ����֮�ͣ��� 
//������ȡ�ߵķ�ʽһ��Ҫ��������Ϸ����ʱ��ֵ�����ĸߣ�
//��һ������Ϸ����ʱ����ȡ�����˼�ֵ���ȡ���˼�ֵֻ��
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
int n;
int a[110];
int data[110];
int d[110][110][2];//d[i][j][k]  i:j��k����ȡ�����ż�ֵ
int vis[110][110][2];
int dp(int i, int j, int k)
{
	if(vis[i][j][k])
		return d[i][j][k];
	if(i>j)
	{
		vis[i][j][k] = 1;
		d[i][j][k] = 0;
		return 0;
	}
	int res=-2000000000;  
	for(int r = 1;r<j-i+2;r++)
	{
		res = max(res,data[j]-data[i-1]-dp(i+r,j,k^1));//��i������ȥ��1,2...j-i+1����
		res = max(res,data[j]-data[i-1]-dp(i,j-r,k^1));//��j������ȥ��1,2...j-i+1����
	}	
	vis[i][j][k] = 1;
	d[i][j][k] = res;
	return res;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		memset(a,0,sizeof(a));
		memset(data,0,sizeof(data));
		int sum = 0;
		for(int i = 0;i<n;i++)
		{
			scanf("%d",&a[i]);
			data[i]+=(data[i-1]+a[i]); 
			sum+=a[i];
		}
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		dp(0,n-1,0);
		printf("%d\n",2*d[0][n-1][0]-sum);//d[0][n-1][0]-(sum-d[0][n-1][0])
	}
	return 0;
}

