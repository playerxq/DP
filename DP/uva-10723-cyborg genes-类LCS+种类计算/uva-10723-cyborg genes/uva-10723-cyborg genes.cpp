// uva-10723-cyborg genes.cpp : 定义控制台应用程序的入口点。
//给出两个字符串，找出第三个字符串，使得给出的两个字符串都是第三个字符串的子串，
//现在要求所得字符串最短，并且输出有多少种组成方法。

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
int d[50][50];//d[i][j]为第一个串到i  第二个到j构成的s3的长度
int c[50][50];//方案数
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
	//若s1[i]=s2[j]则只需把s1[i]放到s3中 继续d[i-1][j-1]的计算  方案数=c[i-1][j-1]
	//若不等，则
	//可以先放s1[i]再计算s1[1:i-1]与s2[1:j]的结果  也可以相反 取决于d的大小 即d[i][j] = min(d[i-1][j],d[i][j-1])+1
	//而判断当前是放s1[i]还是s2[j]则依赖于谁在公共串中 即d[i-1][j],d[i][j-1]大小
	//若d[i-1][j]<d[i][j-1]当前先放s1[i]反之亦然  若相等  2种都可以  方案累加
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

