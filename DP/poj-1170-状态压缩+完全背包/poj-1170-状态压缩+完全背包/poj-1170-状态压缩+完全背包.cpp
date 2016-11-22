// poj-1170-״̬ѹ��+��ȫ����.cpp : �������̨Ӧ�ó������ڵ㡣
//ÿ����Ʒ���5��������6����״̬ѹ������״̬stateʱ��ÿ����Ʒ����

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
int dp[200000];
int state[] = {1, 6, 36, 216, 2196, 7776, 46656, 279936};
int b,s,S,ans;
struct GOOD
{
	int code,amount,price,state;
} goods[200000];
int map[1000];
void Init()
{
	memset(map, -1, sizeof(map));
	memset(dp, 0x3f, sizeof(dp));
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Init();
	scanf("%d",&b);
	for(int i = 0;i<b;i++)
	{
		scanf("%d%d%d",&goods[i].code,&goods[i].amount,&goods[i].price);
		goods[i].state = state[i];
		map[goods[i].code]=i;//��Ӧ
		S+=goods[i].state*goods[i].amount;//Ŀ��״̬
		ans+=goods[i].price*goods[i].amount;//�������ֵ
	}
	scanf("%d",&s);
	for(int i = 0;i<s;i++)
	{
		int t;
		goods[i+b].state=0;
		scanf("%d",&t);
		for(int j = 0;j<t;j++)
		{
			int ind,num;
			scanf("%d%d",&ind,&num);
			if(map[ind]==-1)
				continue;
			goods[i+b].state+=goods[map[ind]].state*num;
		}
		scanf("%d",&goods[i+b].price);
	}
	dp[0]=0;
	for(int i = 0;i<=S;i++)
	{
		for(int j = 0;j<(b+s);j++)
		{
			dp[i+goods[j].state]=min(dp[i+goods[j].state],dp[i]+goods[j].price);
		}
	}
	ans = min(ans,dp[S]);
	printf("%d\n",ans);
}
