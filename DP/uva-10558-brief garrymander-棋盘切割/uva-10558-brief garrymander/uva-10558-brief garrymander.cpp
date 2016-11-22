// uva-10558-brief garrymander.cpp : �������̨Ӧ�ó������ڵ㡣
//һ�����̣������߶��Ǵ�1��100��ţ����ߴ����ұ꣬���ߴ��µ��ϱ꣩��
//����n��ʾ��n������ǵĸ��ӣ��Ǹ���������ӵ����½����꣬Ȼ������m��������m������
//��ʾ����Щ���ߵĵط��п����̣���ʵֻ����m-2������Ϊ2��������1��100���൱��û�У���
//Ȼ������A����ʾ��Ҫ�ں�������A������ʵҲֻ��A-2������Ϊ2�������ں��ߵ�1��100����
//��ô�Ϳ��԰����̺ܶ����С��һ�ķ��飨���Σ���ֻҪ��Щ�������б���ǵ�С���ӣ�1����������
//��ô����������һ��ѡ����������Ҫʹ��ѡ���ĸ������
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
int n,s,tot;
int street[10005];
int avenue[10005];
int d[105][105];//d[i][j] ��i������һ�� ��i+1�п�ʼ����һ��������j��
int p[105][105];
int street_cut[105];
int num[105][105];//i���·���j-1:j�����и�֮��С����ɵ�����Ŀ
int g[105][105];
int solve()
{
	memset(g,0,sizeof(g));
	memset(num,0,sizeof(num));
	memset(d,-1,sizeof(d));
	for(int i = 0;i<n;i++)//��ÿ��С��
	{
		int j;
		for(j = 1;j<s;j++)
		{
			if(street[i]<street_cut[j])//���ڵ�j��street�������
			{
				break;
			}
		}
		g[avenue[i]+1][j] = 1;//��j-1:j��������avenue[i]+1���·���С�� �ϲ�����ͬһ�����������С��
	}
	for(int i = 1;i<101;i++)
	{
		for(int j = 1;j<s;j++)
		{
			num[i][j] = num[i-1][j]+g[i][j];//�������и����߼����Ϊ��λ�������j-1���j��������֮�京�кڿ���е���Ŀ
		}
	}
	return 0;
}
int dp(int i, int j)//i��  ��ʣj�� ������һ����i+1����
{
	if(d[i][j]!=-1)
		return d[i][j];
	d[i][j] = 0;
	if(j==0)
	{
		for(int k = 1;k<s;k++)
		{
			if(num[100][k]-num[i][k])//�����в���һ��С��
				d[i][j]++;
		}
		p[i][j] = 100;
		return d[i][j];
	}
	for(int k = i+1;k<=100-j;k++)//k+1:99��Ҫ����j-1��  ��k = 100-j
	{
		int ans = 0;
		for(int t = 1;t<s;t++)
		{
			if(num[k][t]-num[i][t])
				ans++;
		}
		if(dp(k,j-1)+ans>d[i][j])
			p[i][j] = k;
		d[i][j] = max(d[i][j],dp(k,j-1)+ans);
	}
	return d[i][j];
}
void output(int i, int j)
{
	int k = p[i][j];
	if(k==100)
		return;
	printf(" %d",p[i][j]);
	output(k,j-1);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&n))
	{
		if(n==-1)
			break;
		int st,av;
		for(int i = 0;i<n;i++)
		{
			scanf("%d%d",&st,&av);
			street[i] = st;
			avenue[i] = av;
		}
		scanf("%d",&s);
		int x = 1;
		for(int i = 0;i<s;i++)
		{
			scanf("%d",&street_cut[i]);
		}
		scanf("%d",&tot);
		if(tot==2)//1 100��2��
		{
			printf("2 1 100\n");
			continue;
		}
		printf("%d 1", tot);
		solve();
		dp(1,tot-2);
		output(1,tot-2);
		printf(" 100\n");
	}
	return 0;
}

