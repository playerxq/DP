// poj-1037-递推.cpp : 定义控制台应用程序的入口点。
//dp[i][j][0]表示序列长度为i，以j开始并且前两位下降的合法序列数目;

//dp[i][j][1]表示序列长度为i, 以j开始并且前两位上升的合法序列数目;
//dp[i][j][0] += dp[i-1][k][1] ( 1 <= k < j ), dp[i][j][1] += dp[i-1][k][0] ( j <= k <= i)，
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
const int MAXN = (20 + 2);
long long dp[MAXN][MAXN][2]; //0 down, 1 up
int N, K;
int ans[MAXN];
bool mark[MAXN];
long long C;

void Init()
{
	memset(dp, 0, sizeof(dp));
	dp[1][1][0] = dp[1][1][1] = 1;
	for (int i = 2; i < MAXN; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k < j; k++) {
				dp[i][j][0] += dp[i - 1][k][1];
			}
			for (int k = j; k < i; k++) {
				dp[i][j][1] += dp[i - 1][k][0];
			}
		}
	}
}
void Solve(int N, long long C)
{
	int n = N, flag = 0, now = 1, len = 0;
	long long sum = 0;
	//枚举长度为n的串的起点
	for (int i = 1; i <= N; i++) {
		if (sum + dp[n][i][0] + dp[n][i][1] >= C) {
			C -= sum;
			ans[++len] = i;
			now = i;
			break;
		}
		sum += dp[n][i][0] + dp[n][i][1];
	}
	if (C <= dp[n][now][0]) flag = 1;
	else C -= dp[n][now][0], flag = 0;
	while (--N > 0) {
		if (flag == 0) {
			for (int i = now; i <= N; i++) {
				if (dp[N][i][0] >= C) {
					now = i;
					ans[++len] = i;
					break;
				}
				C -= dp[N][i][0];
			}
		} else {
			for (int i = 1; i < now; i++) {
				if (dp[N][i][1] >= C) {
					now = i;
					ans[++len] = i;
					break;
				}
				C -= dp[N][i][1];
			}
		}
		flag ^= 1;
	}
	memset(mark, false, sizeof(mark));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mark[j] == false) {
				ans[i]--;
				if (ans[i] == 0) {
					mark[j] = true;
					if (i == n) {
						printf("%d\n", j);
					 } else
						 printf("%d ", j);
					 break;
				}
			}
		}
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Init();
	scanf("%d", &K);
	while (K--) {
		scanf("%d%lld", &N, &C);
		Solve(N, C);
	}
	return 0;
}

