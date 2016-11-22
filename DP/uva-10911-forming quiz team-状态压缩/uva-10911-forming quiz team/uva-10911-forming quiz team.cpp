// uva-10911-forming quiz team.cpp : �������̨Ӧ�ó������ڵ㡣
//����2*n���㣬����Щ�����n�ԣ�ʹ�����е��������ľ���֮�;���С

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
#define INF 1000000000
int n;
char str[100];
double d[70000];
typedef struct PPP
{
	double x;
	double y;
} pp;
pp a[20];
char s[30];
double sqr(double a, double b)
{
    return (a - b) * (a - b);
}
double dp(int st)
{
	if(d[st]>-1)
		return d[st];
	double temp,minn;
	minn = INF;
	for(int i = 0;i<2*n;i++)//ö�ٵ�ǰ״̬���������
	{
		if((1<<i)&st)
		{
			for(int j = i+1;j<2*n;j++)
			{
				if((1<<j)&st)
				{
					temp = dp(st^(1<<i)^(1<<j))+d[(1<<i)+(1<<j)];
					if(temp<minn)
						minn = temp;
				}
			}
		}
	}
	return d[st] = minn;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ncase = 1;
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		getchar();
		for(int i = 0;i<2*n;i++)//2n����
		{
			gets(str);
			sscanf(str,"%s%lf%lf",s,&a[i].x,&a[i].y);
		}
		d[0] = 0;
		for(int i = 1; i < (1 << 2*n); i ++)
			d[i] = -2;
		for(int i = 0; i < 2*n; i ++)//��Եľ���Ԥ����
			for(int j = i + 1; j < 2*n; j ++)
				d[(1 << i) + (1 << j)] = sqrt(sqr(a[i].x, a[j].x) + sqr(a[i].y, a[j].y));
		printf("Case %d: ", ncase++);
		double res = dp((1 << 2*n) - 1);
		printf("%.2f\n", res);
	}
	return 0;
}

