// uva-10280-old wine into bottle.cpp : �������̨Ӧ�ó������ڵ㡣
//������L���ƣ��Լ�n�־�ƿ�����ڸ���ÿ�־�ƿ����С���������������
//ÿ�־�ƿ����ʹ�����޶�Σ��ʣ�����װ�ƣ�����ʹ��ʣ�µľƣ���δ��װ����ƿ�еľƣ�����


/*
����һ��ƿ�ӣ����ǲ�������k��ƿ��ȥװ�ƣ���ô�ܹ���ȫװ�µķ�Χ����[k*min,k*max]��
����k���������Ƿ������������������˵�ļ���ǹ̶��ģ�ͬʱ����ĳ������ڲ������ӣ�
�������ǲ��룬��ĳһ��ʱ������������໥֮����н���������ʣ�µĸ�������ͻḲ�ǵ��������е�������
������տ�ʼ��������������Ϊ��k����������k*max>=(k+1)*min�����k>=min/(max-min)��
��������x>=k*min��ʱ�򣬾�һ����ȫ��װ��ȥ����������x>=min*min/(max-min)��

ʣ�µĹ������ǰ�ƿ�Ӱ���ͬ���ݻ����max-min+1��ƿ�ӣ�Ȼ������ȫ������dp
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
#define N 450000
int d[N];
int vis[N];
int bottle[N];
int v,n;
typedef struct PPP
{
	int mina;
	int maxa;
} pp;
pp a[101];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&v);
		v = v*1000;
		scanf("%d",&n);
		int k = 0x3f3f3f3f;
		for(int i = 0;i<n;i++)//ȡ��С�Ŀ��Ա�ȫװ�ľƵĽ���
		{
			scanf("%d%d",&a[i].mina,&a[i].maxa);
			if(k>=a[i].mina*a[i].mina/(a[i].maxa-a[i].mina))
				k=a[i].mina*a[i].mina/(a[i].maxa-a[i].mina);
		}
		if(v>=k)
		{
			printf("0\n");  
            if(T)  
				printf("\n"); 
		}
		else
		{
			memset(d,0,sizeof(d));
			memset(vis,0,sizeof(vis));
			int cnt = 0;
			for(int i = 0;i<n;i++)//�õ����е���ƿ��
			{
				for(int k = a[i].mina;k<=a[i].maxa;k++)
				{
					if(vis[k]==0)
					{
						vis[k] = 1;
						bottle[cnt++] = k;
					}
				}
			}
			for(int i = 0;i<cnt;i++)//����ȫ����
			{
				for(int j = bottle[i];j<=v;j++)
				{
					d[j] = max(d[j],d[j-bottle[i]]+bottle[i]);
				}
			}
			printf("%d\n",v-d[v]);
			if(T)  
				printf("\n"); 
		}
	}
	return 0;
}

