// uva-10453-make palindrome.cpp : �������̨Ӧ�ó������ڵ㡣
//����ÿ�����������ٶ���m���ַ���ʹ�����һ�����Ĵ������m�����ѻ��Ĵ����.

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
char str[1010];
int d[1010][1010];//d[i][j]i:j�����ٲ�����
int len;
int dp()
{
	for(int r = 2;r<len;r++)//�������м��
	{
		for(int i = 0,j=r;j<len;i++,j++)
		{
			if(str[i]==str[j])
			{
				d[i][j] = d[i+1][j-1];
			}
			else if(d[i+1][j]<d[i][j-1])//i����Ϊ���
			{
				d[i][j] = d[i+1][j]+1;
			}
			else//j�����
			{
				d[i][j] = d[i][j-1]+1;
			}
		}
	}
	return d[0][len-1];
}
void construct(int i, int j)
{
	if(i==j)
	{
		printf("%c",str[i]);
		return;
	}
	if(i>j)
		return;
	if(str[i]==str[j])
	{
		printf("%c",str[i]);
		construct(i+1,j-1);
		printf("%c",str[j]);
	}
	else 
	{
		if(d[i+1][j] < d[i][j-1])
		{
			printf("%c",str[i]);
			construct(i+1,j);
			printf("%c",str[i]);
		}
		else
		{
			printf("%c",str[j]);
			construct(i,j-1);
			printf("%c",str[j]);
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%s",str)!=EOF)
	{
		memset(d,0,sizeof(d));
		len = strlen(str);
		for (int i = 0; i < len; ++i)
        {
            d[i][i] = 0;
            if (str[i] == str[i+1])
                d[i][i+1] = 0;
            else
                d[i][i+1] = 1;
        }
		int ans = dp();
		printf("%d ",ans);
		construct(0,len-1);
		printf("\n");
	}
	return 0;
}

