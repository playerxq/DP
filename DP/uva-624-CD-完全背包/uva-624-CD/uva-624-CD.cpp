// uva-624-CD.cpp : �������̨Ӧ�ó������ڵ㡣
//��ȫ����
//d[i][j]ʹ��i����Ʒ������װ��j�Ŀռ�ʱ������a[]��
//d[i][j] = max(d[i-1][j],d[i-1][j-a[i]]+a[i])

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
int V,n;
int a[21];
int d[21][1500];
int p[21][1500];
void print_list(int m, int c)
{
     if (m == 0) return;
     if (m == 1 && p[m][c] > 0) {printf("%d ", a[m]); return;}
     if (p[m][c] > 0)//a[m]ʹ��
     {
         print_list(m-1, c-a[m]);
         printf("%d ", a[m]);//p[m][c] = a[m]
     }
     else print_list(m-1, c);//a[m]û��ʹ��
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d",&V,&n)!=EOF)
	{
		memset(d, 0, sizeof(d));
		memset(p, 0, sizeof(p));
		for(int i = 1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i = 1;i<=n;i++)
		{
			for(int j = 0;j<=V;j++)
			{
				d[i][j] = d[i-1][j];
				p[i][j] = 0;
				if(j>=a[i])
				{
					if(d[i][j]<d[i-1][j-a[i]]+a[i])//ǰi��ֵ����ɵ���ӽ�j��ֵ
					{
						d[i][j] = d[i-1][j-a[i]]+a[i];
						p[i][j] = a[i]; //���һ����ʹ����a[i]  ����p[i][j]>0�����a[i]ʹ����
					}
				}
			}
		}
		print_list(n, V);
		printf("sum:%d\n", d[n][V]);
	}
	return 0;
}

