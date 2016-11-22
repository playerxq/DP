// poj-2264-�ϲ��ַ���.cpp : �������̨Ӧ�ó������ڵ㡣
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
char str1[101];
char str2[101];
int mark[101];
int mark1[101];
int pos[101];
char str[110];
char ans[220];
int dp[101][101];
int p[101][101];
int len1,len2,len,idx;

void get_ans(int i, int j,int idx)
{
	if(idx<0)
		return;
	if(p[i][j]==0)
	{
		str[idx--]=str1[i-1];
		mark[i-1]=mark1[j-1]=1;//i-1���ǹ�������һ����
		pos[i-1]=j-1;//i-1���Ĺ�������Ӧ�ڵڶ�������j-1��
		get_ans(i-1,j-1,idx);
		return;
	}
	else if(p[i][j]==-1)
	{
		get_ans(i-1,j,idx);
		return;
	}
	else
	{
		get_ans(i,j-1,idx);
		return;
	}
}
void LCS()
{
	memset(dp,0,sizeof(dp));
	memset(p,0,sizeof(p));
	memset(mark,0,sizeof(mark));
	memset(mark1,0,sizeof(mark1));
	memset(str,0,sizeof(str));
	memset(ans,0,sizeof(ans));
	for(int i = 1;i<=len1;i++)
	{
		for(int j = 1;j<=len2;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				if(dp[i][j]<dp[i-1][j-1]+1)
				{
					dp[i][j]=dp[i-1][j-1]+1;
					p[i][j]=0;
				}
			}
			if(dp[i][j]<dp[i-1][j])
			{
				dp[i][j]=dp[i-1][j];
				p[i][j]=-1;
			}
			if(dp[i][j]<dp[i][j-1])
			{
				dp[i][j]=dp[i][j-1];
				p[i][j]=1;
			}
		}
	}
	len = dp[len1][len2];
	idx = len-1;
	get_ans(len1,len2,idx);
}
void combin()
{
	idx=0;
	int i,j=0;
	bool ok = false;
	for(i = 0;i<len2;i++)//��2��ÿ��Ԫ��
	{
		if(mark1[i])//�ǹ����� ������
			continue;
		for(;j<len1;j++)//��1�����ҵ����ʵ�λ��
		{
			if(mark[j]==1&&pos[j]>i)//���һ��������
			{
				ok = true;
				break;
			}
			else
			{
				ans[idx++]=str1[j];
			}
		}
		if(ok)
		{
			ans[idx++]=str2[i];
			ok = false;
		}
		else
		{
			break;
		}
	}
	for(;j<len1;j++)
		ans[idx++]=str1[j];
	for(;i<len2;i++)
		ans[idx++]=str2[i];
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%s",str1)!=EOF)
	{
		scanf("%s",str2);
		len1 = strlen(str1);
		len2 = strlen(str2);
		LCS();
		combin();
		printf("%s\n",ans);
	}
}
