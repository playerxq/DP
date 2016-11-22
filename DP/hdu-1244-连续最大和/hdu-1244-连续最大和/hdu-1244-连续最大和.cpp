// hdu-1244-连续最大和.cpp : 定义控制台应用程序的入口点。
//
//dp[i][j]表示前i个数中完整的选j段所能构成的最大值
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
int sum[1001];
int len[20];
int a[1001];
int dp[1001][22];
int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m, i, j, k;
    while (scanf("%d",&n),n)
    {
        scanf("%d",&m);
        for (i=1; i<=m; i++)
            scanf("%d",&len[i]);
        for (i=1; i<=n; i++)
            scanf("%d",&a[i]);
        sum[0] = 0;
        sum[1] = a[1];
        for (i=2; i<=n; i++)
            sum[i] = sum[i-1]+ a[i];
        memset(dp,0,sizeof(dp));
        for (i=1; i<=n; i++)
        {
            for (j=1; j<=m && j<=i; j++)
            {
               dp[i][j] = max(dp[i][j],dp[i-1][j]);//
               if (i >=len[j])
                   dp[i][j] = max(dp[i][j],dp[i-len[j]][j-1]+sum[i]-sum[i-len[j]]);//
             }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}

