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
int n,m;
int a[11];
int d[1000001];//d[i]Ϊ��ʣi��ʯ��ʱ��ʤ��  0ΪS 1ΪO
int _min(int a, int b)
{
	return a<b?a:b;
}
int dp()
{
	for(int i = 1;i<=n;i++)//��ǰʣ��i��ʯ��ʱ��ȡ���˵�ʤ�����
	{
		for(int j = 0;j<m;j++)//һ��ȡ����
		{
			if(i>=a[j]&&!d[i-a[j]])
			{
				d[i] = 1;
				break;
			}
		}
	}
	return d[n];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&m);
		for(int i = 0;i<m;i++)
			scanf("%d",&a[i]);
		memset(d,0,sizeof(d));
		int res = dp();
		if(res)
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}
	return 0;
}