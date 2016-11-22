// uva-709-formatting text.cpp : �������̨Ӧ�ó������ڵ㡣
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
#define INF 0x3f3f3f3f
using namespace std;
char str[10005];
int n;
char word[10005][85];
int d[10005][85],len[10005],top;
int dp(int i, int j)//��i���������Ϊj
{
	if(d[i][j]!=-1)
		return d[i][j];
	d[i][j] = INF;
	if(i==top)//û�е���
	{
		if(j==0)
			return d[i][j] = 0;
		else
			return d[i][j];
	}
	if(j==0)//��ռ
		d[i][j] = min(d[i][j],500+dp(i+1,0));
	if(j+len[i]==n)
	{
		return d[i][j] = min(d[i][j],dp(i+1,0));
	}
	else
	{
		int x = j+len[i]+1;//����һ���ո�
		for(int k = x;k<n;k++)
		{
			if(k+len[i+1]>n)
				break;
			d[i][j] = min(d[i][j],dp(i+1,k)+(k-x)*(k-x));//ö����һ��λ��
		}
	}
	return d[i][j];
}
void output(int i, int j)
{
	if(i==top)
	{
		printf("\n");
		return;
	}
	printf("%s",word[i]);
	if(j==0&&d[i][j]==500+d[i+1][0])
	{
		printf("\n");
		output(i+1,0);
	}
	else if(j+len[i]==n&&d[i][j]==d[i+1][0])
	{
		printf("\n");
		output(i+1,0);
	}
	else
	{
		int x = j+len[i]+1;//����һ���ո�
		printf(" ");
		for(int k = x;k<n;k++)
		{
			if(k+len[i+1]>n)
				break;
			if(d[i][j] == dp(i+1,k)+(k-x)*(k-x))
			{
				for(int t = x;t<=k-1;t++)
					printf(" ");
				output(i+1,k);
				break;
			}
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&n))
	{
		if(!n)
			break;
		getchar();
		top = 0;
		while(gets(str))
		{
			if(!str[0])
				break;
			int i = 0;
			for(;str[i]==' ';i++);
			for(;str[i];)//�ָ��
			{
				sscanf(str+i,"%s",word[top]);
				for(;str[i]!=' '&&str[i];i++);
				for(;str[i]==' ';i++);
				len[top] = strlen(word[top]);
				top++;
			}
		}
		len[top] = 0;
		memset(d,-1,sizeof(d));
		dp(0,0);
		output(0,0);
	}
	return 0;
}

