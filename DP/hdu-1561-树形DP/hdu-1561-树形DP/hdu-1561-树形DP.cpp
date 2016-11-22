// hdu-1561-����DP.cpp : �������̨Ӧ�ó������ڵ㡣
//dp[ i ] [ j ]  �Խڵ�iΪroot��ȡj��������i����dp[i][1]=V[i]�����ܵõ������ֵ

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

int N,M,v[223];
vector<int>son[223];

int dp[223][223];

void dfs(int n,int left){
	int i,j,k,len=son[n].size();
	dp[n][1]=v[n];
	for(i=0;i<len;i++){//��n��ÿ�����
		if(left>1)	dfs(son[n][i],left-1);//���ȡleft-1��
		for(j=left;j>=1;j--)
			for(k=1;k<=j;k++)
				if(dp[n][j+1]<dp[n][j+1-k]+dp[son[n][i]][k])//nΪ��ȡj+1�� 	��i������ȡk�� ʣ��j+1-k��
					dp[n][j+1]=dp[n][j+1-k]+dp[son[n][i]][k];
	}
}

int main()
{
	int i,j,k;
	while(scanf("%d%d",&N,&M),N||M)
	{
		memset(v,0,sizeof(v));
		memset(dp,0,sizeof(dp));
		for(i=0;i<=N;i++)	son[i].clear();
		//��j=0ʱ��Ϊ������  ��ɭ������ɵ�����
		for(i=1;i<=N;i++){//�Ե�i���Ǳ�
			scanf("%d%d",&j,&v[i]);//jΪi��ǰ��
			son[j].push_back(i);
		}
		dfs(0,M+1);//�൱�ڴ�0����M+1��
		printf("%d\n",dp[0][M+1]);
	}
	return 0;
}


