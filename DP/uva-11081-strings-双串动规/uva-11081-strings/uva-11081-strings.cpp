// uva-11081-strings.cpp : �������̨Ӧ�ó������ڵ㡣
//

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
char str1[100];
char str2[100];
char str3[100];
int len1, len2, len3;
int d1[100][100][100];//d1[i][j][k]˵����k���ַ������ڵ�һ���� ������s1[i]����1:i-1��d1[i-1][j][k]
int d2[100][100][100];//ͬ��  �ڶ���
int d[100][100][100];
int dp()
{
	memset(d1,0,sizeof(d1));
    memset(d2,0,sizeof(d2));
    memset(d,0,sizeof(d));
	for(int i = 0;i<=len1;i++)
	{
		for(int j = 0;j<=len2;j++)
		{
			d1[i][j][0] = 1;
			d2[i][j][0] = 1;
			d[i][j][0] = 1;
		}
	}
	for(int k = 1;k<=len3;k++)
	{
		for(int i = 0;i<=len1;i++)
		{
			for(int j = 0;j<=len2;j++)
			{
				if(i)
				{
					d1[i][j][k] = d1[i-1][j][k];//���Ե�һ����ǰi-1��
					if(str1[i]==str3[k])
						d1[i][j][k] += d[i-1][j][k-1];//��k�����Ե�һ���ĵ�i�� ��ǰk-1��Ϊ1,2������
					d1[i][j][k]%=10007;
				}
				if(j)
				{
					d2[i][j][k] = d2[i][j-1][k];
					if(str2[j]==str3[k])
						d2[i][j][k] += d[i][j-1][k-1];
					d2[i][j][k]%=10007;
				}
				d[i][j][k] = (d1[i][j][k]+d2[i][j][k])%10007;
			}
		}
	}
	printf("%d\n",d[len1][len2][len3]);
	return 0;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		scanf("%s%s%s",str1+1,str2+1,str3+1);
		len1 = strlen(str1 + 1);  
		len2 = strlen(str2 + 1);  
		len3 = strlen(str3 + 1); 
		dp();
	}
	return 0;
}

