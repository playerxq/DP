// uva-674-coin change.cpp : �������̨Ӧ�ó������ڵ㡣
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
int n;
int d[8000][5];//d[i][j]Ϊʹ��a[j]-a[4]����ֵ���Թ���i�ķ�����
int a[5] = {50,25,10,5,1};
void dp()//
{
	for(int i = 0;i<8000;i++)
		d[i][4] = 1;//ֻʹ��1
	for(int i = 0;i<5;i++)
		d[0][i] = 1;//�γ�0
	for(int i = 1;i<8000;i++)
	{
		for(int j = 4;j>=0;j--)
		{
			d[i][j] = d[i][j+1];
			if(i>=a[j])
			{
				d[i][j]+=d[i-a[j]][j];
			}
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	dp();
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",d[n][0]);
	}
	return 0;
}

