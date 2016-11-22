// hdu-1561-树形DP.cpp : 定义控制台应用程序的入口点。
//dp[ i ] [ j ]  以节点i为root，取j个（包括i，即dp[i][1]=V[i]）所能得到的最大值

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
	for(i=0;i<len;i++){//对n的每个后继
		if(left>1)	dfs(son[n][i],left-1);//后继取left-1个
		for(j=left;j>=1;j--)
			for(k=1;k<=j;k++)
				if(dp[n][j+1]<dp[n][j+1-k]+dp[son[n][i]][k])//n为根取j+1个 	第i个孩子取k个 剩余j+1-k个
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
		//当j=0时作为超级根  将森林虚拟成单根树
		for(i=1;i<=N;i++){//对第i个城堡
			scanf("%d%d",&j,&v[i]);//j为i的前驱
			son[j].push_back(i);
		}
		dfs(0,M+1);//相当于从0根找M+1个
		printf("%d\n",dp[0][M+1]);
	}
	return 0;
}


