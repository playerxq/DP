// uva-562-divide coins.cpp : �������̨Ӧ�ó������ڵ㡣
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
int m;
int c[105];
int d[105*500];//d[i]Ϊ��ǰ������Ӳ���ܷ�����ܶ�Ϊi�Ķ�
int sum;
int minn;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&m);
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		d[0] = 1;
		sum = 0;
		for(int i = 0;i<m;i++)
		{
			scanf("%d",&c[i]);
			sum+=c[i];
		}
		for(int i = 0;i<m;i++)//��ǰ��i��Ӳ���ܷ�����ܶ�Ϊj�Ķ�
		{
			for(int j = sum;j>=c[i];j--)
			{
				if(d[j-c[i]])
					d[j] = 1;
			}
		}
		int i;
		for(i = sum/2;i>=0;i--)
			if(d[i])
				break;
		printf("%d\n",sum-2*i);//i:sum-i�Ĳ�
	}
	return 0;
}

