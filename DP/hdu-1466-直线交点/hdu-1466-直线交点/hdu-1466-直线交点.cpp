// hdu-1466-ֱ�߽���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
int res[25][200];
int len[25];
int n;
void init()
{
	res[0][len[0]++]=0;
	res[1][len[1]++]=0;
	res[2][len[2]++]=0;
	res[2][len[2]++]=1;
	for(int i = 3;i<21;i++)
	{
		res[i][len[i]++]=0;//ȫƽ�����
		//��i������ǰi-1��û��ƽ���� ���²���i-1������+(i-1)���ߵ����н������
		//��i������ǰi-1������һ��ƽ���� ���²���2*(i-2)������+(i-2)��������������
		//������
		//��i����ǰi-1������i-2��ƽ���� �²���(i-1)*1������+1��ֱ���������
		//ȫ��ƽ��  �������µĽ���
		for(int j = i-1;j>=1;j--)
		{
			for(int t = 0;t<len[j];t++)
			{
				int k;
				for(k = 0;k<len[i];k++)
				{
					if(res[i][k]==res[j][t]+(i-j)*j)
						break;
				}
				if(k==len[i])
				{
					res[i][len[i]++]=res[j][t]+(i-j)*j;
				}
			}
		}
		sort(res[i],res[i]+len[i]);
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	init();
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0;i<len[n];i++)
		{
			printf("%d",res[n][i]);
			if(i<len[n]-1)
				printf(" ");
		}
		printf("\n");
	}
}

