// uva-10154-weights and measures.cpp : �������̨Ӧ�ó������ڵ㡣
//�м�ֻ�ڹ꣬ÿֻ�ڹ���һ����������������
//ÿֻ�ڹ���Ա�С����������������������������������������һ�������ж���ֻ�ڹ����һ��
//��Ȼ��
//���һ������С���ڹ��������һ����������ڹ꣬��ô�����������ڹ�Ҳ��Ȼ���������������С���ڹ꣬
//���һ��ܹ�ʹ�����ڹ��Ϸ����ӳ���������

//�Ȱ��ڹ갴��������ʣ�µ���������������ǽ��������ˡ�
//���ڵ�ǰ���ڹ�i�����f[j]+w[i]<s[i]��f[j]+w[i]<f[j+1]����ô���ǾͿ��Ը���f[j+1]�ˣ�
//ͬʱ���j+1��maxҪ��Ļ�������Ҳ��Ҫͬʱ����max�ˡ�
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
typedef struct Tur
{
	int wei;
	int cap;
} tur;
#define INF 1000000000
tur a[5700];
int f[5700];//f[j]��ʾ�ڹ�һ����j����ʱ����������������ô��Ȼһ��ʼf[0]Ӧ��Ϊ0��������Ķ�ӦΪINF��
int b[5700];
int cmp(const void* _a, const void* _b)
{
	tur* a = (tur*)_a;
	tur* b = (tur*)_b;
	return a->cap-b->cap;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int w,s;
	int cnt = 0;
	while(scanf("%d%d",&w,&s)!=EOF)
	{
		a[cnt].wei = w;
		a[cnt++].cap = s;
	}
	qsort(a,cnt,sizeof(a[0]),cmp);//������������
	for(int i = 0;i<cnt;i++)
		f[i] = INF;
	f[0] = 0;
	int maxn = 0;
	for(int i = 0;i<cnt;i++)
	{
		for(int j = maxn;j>=0;j--)
		{
			if(f[j]+a[i].wei<a[i].cap&&f[j]+a[i].wei<f[j+1])//����i���ڹ�ŵ�ĳ������Ϊj�Ĵ��� ���Ƿ�����չ��j+1�Ĵ�
			{
				f[j+1] = f[j]+a[i].wei;
				if(j+1>maxn)
					maxn = j+1;
			}
		}
	}
	printf("%d\n",maxn);
	return 0;
}

