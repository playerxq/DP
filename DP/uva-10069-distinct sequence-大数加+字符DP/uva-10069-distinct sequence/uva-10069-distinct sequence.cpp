// uva-10069-distinct sequence.cpp : �������̨Ӧ�ó������ڵ㡣
//��ĸ�����ҳ��ж��ٸ��Ӵ�Ϊ�������ִ�
//d[i][j] = d[i][j-1];
//if(b[i] == a[j]) d[i][j] += d[i-1][j-1];
//d[i][j]Ϊ�Ӵ�ǰi���ַ���ɵĴ���ĸ��ǰj���ַ���ɵĴ��г��ֵĴ��� j>=i  ����������ַ���ͬ ��d[i-1][j-1]�������d[i][j-1]
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
char X[10001];
char Z[101];
int lenx,lenz;
char d[101][10001][102];//z�г���i����X�г���j���Ӵ���Ŀ  ������10^100
void add(char* src1, char* src2,char* des)//�߾��ȼ� src1+src2 = des
{
	int len1 = strlen(src1);
	int len2 = strlen(src2);
	int len = max(len1,len2);
	memset(des,0,(len+2)*sizeof(des[0]));
	for(int i = len1-1,j = len;i>=0;i--,j--)
		des[j] += src1[i]-'0';
	for(int i = len2-1,j = len;i>=0;i--,j--)
		des[j] += src2[i]-'0';
	for(int i = len;i>0;des[i]+='0',i--)
		if(des[i]>9)
		{
			des[i]-=10;
			des[i-1]++;
		}
	if(des[0]==0)
	{
		for(int i = 0;i<len;i++)
			des[i] = des[i+1];
		des[len] = 0;
	}
	else
		des[0] = '1';//������10^100
}
void dp()
{
	for(int i = 1;i<=lenz;i++)
	{
		strcpy(d[i][i-1], "0");
		for(int j = i;j<=lenx;j++)
		{
			if(X[j-1]==Z[i-1])
			{
				add(d[i-1][j-1],d[i][j-1],d[i][j]);
			}
			else
				strcpy(d[i][j],d[i][j-1]);
		}
	}
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
		gets(X);
		gets(Z);
		lenx = strlen(X);
		lenz = strlen(Z);
		for(int i=0; i<=lenx; ++i)  
            strcpy(d[0][i], "1");
		dp();
		printf("%s\n",d[lenz][lenx]);
	}
	return 0;
}

