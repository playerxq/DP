// uva-10723-cyborg genes.cpp : �������̨Ӧ�ó������ڵ㡣
//���������ַ������ҳ��������ַ�����ʹ�ø����������ַ������ǵ������ַ������Ӵ���
//����Ҫ�������ַ�����̣���������ж�������ɷ�����

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
char str1[50];
char str2[50];
int d[50][50];//d[i][j]Ϊ��һ������i  �ڶ�����j���ɵ�s3�ĳ���
int c[50][50];//������
int len1,len2;
int dp()
{
	for(int i = 0;i<50;i++)
	{
		d[i][0] = i;
		c[i][0] = 1;
		d[0][i] = i;
		c[0][i] = 1;
	}
	//��s1[i]=s2[j]��ֻ���s1[i]�ŵ�s3�� ����d[i-1][j-1]�ļ���  ������=c[i-1][j-1]
	//�����ȣ���
	//�����ȷ�s1[i]�ټ���s1[1:i-1]��s2[1:j]�Ľ��  Ҳ�����෴ ȡ����d�Ĵ�С ��d[i][j] = min(d[i-1][j],d[i][j-1])+1
	//���жϵ�ǰ�Ƿ�s1[i]����s2[j]��������˭�ڹ������� ��d[i-1][j],d[i][j-1]��С
	//��d[i-1][j]<d[i][j-1]��ǰ�ȷ�s1[i]��֮��Ȼ  �����  2�ֶ�����  �����ۼ�
	for(int i = 1;i<=len1;i++)
	{
		for(int j = 1;j<=len2;j++)
		{
			if(str1[i]==str2[j])
			{
				d[i][j] = d[i-1][j-1]+1;
				c[i][j] = c[i-1][j-1];
			}
			else
			{
				d[i][j] = min(d[i-1][j],d[i][j-1])+1;
				if(d[i-1][j]<d[i][j-1])
				{
					c[i][j] = c[i-1][j];
				}
				else if(d[i-1][j]>d[i][j-1])
				{
					c[i][j] = c[i][j-1];
				}
				else
					c[i][j] = c[i][j-1]+c[i-1][j];
			}
		}
	}
	return d[len1][len2];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	int ncase = 1;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		gets(str1+1);
		gets(str2+1);
		len1 = strlen(str1+1);
	    len2 = strlen(str2+1);
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		int ans = dp();
		 printf("Case #%d: %d %d\n",ncase++,d[len1][len2],c[len1][len2]);  
	}
	return 0;
}

