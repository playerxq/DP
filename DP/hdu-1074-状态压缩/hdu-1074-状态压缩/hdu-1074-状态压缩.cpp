// hdu-1074-状态压缩.cpp : 定义控制台应用程序的入口点。
//

/*
状态压缩dp
对于到达状态i,枚举所有的作业
假如对于作业k,i中含有作业k已完成，那么i可以由和i状态相同的状态仅仅是k未完成的
状态j=i-(1<<k)来完成k到达,并且j一定比i小，如果状态从0枚举到2^n-1那么j一定是在i之前已经计算过的 
*/
#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=(1<<15)+10;
int n;
int dp[MAX],t[MAX],pre[MAX],dea[20],fin[20];//dp[i]记录到达状态i扣的最少分,t时相应的花去多少天了
char s[20][110];

void output(int x){
	if(!x)return;
	output(x-(1<<pre[x]));
	printf("%s\n",s[pre[x]]);
}

int main(){
	    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%s%d%d",&s[i],&dea[i],&fin[i]);
		int bit=1<<n;
		for(int i=1;i<bit;++i){//枚举到达状态i
			dp[i]=INF;
			for(int j=n-1;j>=0;j--){//先得到尽可能小的状态
				int temp=1<<j;
				if(!(i&temp))continue;//状态i不包含j
				int score=t[i-temp]+fin[j]-dea[j];
				if(score<0)score=0; 
				if(dp[i]>dp[i-temp]+score){
					dp[i]=dp[i-temp]+score;
					t[i]=t[i-temp]+fin[j];//到达状态i花费的时间
					pre[i]=j;//到达状态i的前驱
				} 
			}
		}
		printf("%d\n",dp[bit-1]);
		output(bit-1);//输出完成作业的顺序 
	}
	return 0;
} 

