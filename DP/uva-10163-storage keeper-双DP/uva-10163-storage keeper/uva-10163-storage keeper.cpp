// uva-10163-storage keeper.cpp : �������̨Ӧ�ó������ڵ㡣
//˫DP
/*
���⣺��n���ֿ⣨���100������m������Ա�����30������
//ÿ������Ա��һ������ֵP(��������һ����m��������ʾÿ������Ա������ֵ)��
//ÿ���ֿ�ֻ����һ������Ա���ܣ�����ÿ������Ա���Կ���k���ֿ⣨��������ֿ���䵽�İ�ȫֵֻ��p/k,k=0,1,...��
//,ÿ���¹�˾��Ҫ������Ա���ʣ����õĹ���Ա�Ĺ��ʼ�Ϊ���ǵ�����ֵp�ͣ�
//�ʣ�ʹÿ���ֿ�İ�ȫֵ��ߵ�ǰ���£�ʹ�Ĺ����ܺ���С��������ȫֵ������������ٵĻ��ѡ�
*/
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <climits>  
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
int n,m;
int pi[35];
int d[35][105];//i:m-1���˿���j�����ӵİ�ȫֵ
int c[35][105];//����
int dp_d(int i, int j)
{
	if(d[i][j]!=-1)
		return d[i][j];
	if(j==0)//û��������Ҫ����
		return d[i][j] = INF;
	if(i==m)//û�й���
		return d[i][j] = 0;
	int k = min(pi[i],j);
	for(;k>=0;k--)//ö�ٵ�i���˿��ܵ�������Ŀ
	{
		if(k)
			d[i][j] = max(d[i][j],min(pi[i]/k,dp_d(i+1,j-k)));
		else//��i���˲���
			d[i][j] = max(d[i][j],dp_d(i+1,j));
	}
	return d[i][j];
}
int dp_c(int i, int j)
{
	if(c[i][j]!=-1)
		return c[i][j];
	if(j==0)//û������  ����Ϊ0
		return c[i][j] = 0;
	if(i==m)//û�й��˿��Թ�Ӷ
		return c[i][j] = INF;
	c[i][j] = INF;
	int k = min(pi[i],j);
	for(;k>=0;k--)
	{
		if(k)
		{//��֤����d[0][n]�Ļ�����
			if(d[0][n]<=min(pi[i]/k,d[i+1][j-k]))//��i��keeper����Ӷ
			{
				c[i][j] = min(c[i][j],pi[i]+dp_c(i+1,j-k));
			}
		}
		else
		{
			if(d[0][n]<=d[i+1][j])
				c[i][j] = min(c[i][j],dp_c(i+1,j));
		}
	}
	return c[i][j];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d",&n,&m))
	{
		if(n+m==0)
			break;
		for(int i = 0;i<m;i++)
			scanf("%d",&pi[i]);
		memset(d,-1,sizeof(d));
		memset(c,-1,sizeof(c));
		dp_d(0,n);
		dp_c(0,n);
		if(d[0][n]==0)
        puts("0 0");
        else
        printf("%d %d\n",d[0][n],c[0][n]);
	}
	return 0;
}

