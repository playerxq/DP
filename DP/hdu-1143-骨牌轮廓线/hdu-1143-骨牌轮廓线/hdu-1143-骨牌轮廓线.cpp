// hdu-1143-����������.cpp : �������̨Ӧ�ó������ڵ㡣


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
const int maxn=40;
const int ST = 17;//0��ʾ�й��� 1��ʾû�� һ������30������ 
int dp[35][5][ST];//dp[i][j][k]��ʾ�Ƶ�(i,j)ʱ��(i,j)δ�ж�ʱ ��һ��(i-1,j)������(i,j-1)��ɵ�(i,1):(i,j-1)+(i-1,j):(i-1,w)��w�������״̬k ����Ŀ
int h,w;
void solve()
{
	for(int i = 1;i<=h+1;i++)
	{
		for(int j = 1;j<=w;j++)
		{
			for(int k = 0;k<(1<<(w+1));k++)
				dp[i][j][k]=0;
		}
	}
	dp[1][1][0]=1;
	for(int i = 1;i<=h;i++)
	{
		for(int j = 1;j<=w;j++)//���쵱ǰ�е�ÿ��λ��
		{
			for(int k = 0;k<(1<<(w+1));k++)
			{
				if(k&(1<<j))//k�ĵ�jλǡΪ��һ��jλ 
				{
					//��0���(i,j+1)��˵��jλΪ0 ����λ��kһ��
					if(j<w)
						dp[i][j+1][k^(1<<j)]+=dp[i][j][k];//j+1λ��k״̬��1:i����ȫ״̬
					else
						dp[i+1][1][k^(1<<j)]+=dp[i][j][k];//j= 1ʱkǡ������һ�е�����״̬
				}
				else//��һ������
				{
					if(k&(1<<(j-1)))//j-1λǡΪ���е�ǰһ��λ�õ�״̬
					{
						//��ǰһ��λ��һ���һ������ ��λ����0
						if(j<w)
							dp[i][j+1][k^(1<<(j-1))]+=dp[i][j][k];//����λ����
						else
							dp[i+1][1][k^(1<<(j-1))]+=dp[i][j][k];//����λ����
					}
					//��ǰλ�ñ���1 Ϊ�յ�
					if(j<w)
						dp[i][j+1][k|(1<<(j))]+=dp[i][j][k];
					else
						dp[i+1][1][k|(1<<(j))]+=dp[i][j][k];
				}
			}
		}
	}
	printf("%d\n",dp[h+1][1][0]);//j=1ʱkǡ������һ�е�����״̬
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&h)!=EOF)
	{
		if(h==-1)
			break;
		if(h==0)
		{
			printf("1\n");
			continue;
		}
		if(h==1)
		{
			printf("0\n");
			continue;
		}
		w=3;
		solve();
	}
}





