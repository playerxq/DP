// uva-10401-injured queen problem.cpp : 定义控制台应用程序的入口点。
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
const int MAXN = 15+5;
char str[MAXN];
int boa[MAXN];
long long dp[MAXN][MAXN];
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
    while (scanf("%s", str) != EOF)
    {
        int n = strlen(str);
        for (int i = 0; i < n; i++)//遍历所有列
        {
            if (str[i] == '?')
                boa[i+1] = 0;//boa[i]为第i列boa[i]行有皇后
            else if ('1' <= str[i] && str[i] <= '9')
                boa[i+1] = str[i]-'0';
            else if ('A' <= str[i] && str[i] <= 'F')
                boa[i+1] = str[i]-'A'+10;
        }
        memset(dp, 0, sizeof(dp));
        if (boa[1])//第一列有皇后于boa[1]行处
            dp[boa[1]][1] = 1;
        else
            for (int i = 1; i <= n; i++)//其他所有位置都可以放置
                dp[i][1] = 1;
        for (int c = 2; c <= n; c++)//对每一列
        {
            if (boa[c])//当前列有皇后  则只能放一个 且只能由前一列相应范围外的行来扩展
            {
                for (int i = 1; i <= n; i++)
                {
                    if (boa[c]-1 <= i && i <= boa[c]+1)
                        continue;
                    dp[boa[c]][c] += dp[i][c-1];
                }
                continue;
            }
			//当前列没有皇后  则每行可以放置皇后依前一列的相应行而定
            for (int r = 1; r <= n; r++)
                for (int i = 1; i <= n; i++)//前一列所有行
                {
                    if (r-1 <= i && i <= r+1)
                        continue;
                    dp[r][c] += dp[i][c-1];
                }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
            ans += dp[i][n];
        printf("%lld\n", ans);
    }
    return 0;
}