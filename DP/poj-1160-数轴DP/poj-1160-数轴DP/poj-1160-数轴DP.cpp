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
int dp[330][330];
int sum[330][330];//��i����ׯ����j����ׯ����һ���ʾֵľ���ͣ���Ȼ�����ʾֽ�����i,j���е�λ�����
int p,v;
int pos[330];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&v,&p);
	for(int i = 1;i<=v;i++)
		scanf("%d",&pos[i]);
	for(int i = 1;i<=v;i++)
		sum[i][i]=0;
	for(int i = 1;i<=v;i++)
	{
		for(int j = i+1;j<=v;j++)
		{
			sum[i][j]=sum[i][j-1]+pos[j]-pos[(i+j)/2];
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i <= v; i++) {
		dp[1][i] = sum[1][i];
	}
	for (int i = 2; i <= p; i++) {
		for (int j = 1; j <= v; j++) {
			for (int k = 1; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + sum[k + 1][j]);
			}
		}
	}
	printf("%d\n", dp[p][v]);
}