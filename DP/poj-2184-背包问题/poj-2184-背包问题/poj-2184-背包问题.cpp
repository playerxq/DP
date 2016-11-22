// poj-2184-背包问题.cpp : 定义控制台应用程序的入口点。
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
const int MAXN = (100 + 10);
const int M = 100000;
const int inf = 0x3f3f3f3f;

int n, S[MAXN], F[MAXN];
int dp[2 * M  + 2];//dp[i]保存聪明度为i时 娱乐度F的和


int main()
{
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			cin >> S[i] >> F[i];
		}
		for (int i = 0; i < 2 * M + 2; i++) dp[i] = -inf;
		dp[M] = 0;
		for (int i = 1; i <= n; i++) {
			if (S[i] >= 0) {
				for (int j = 2 * M; j >= S[i]; j--) {
					dp[j] = max(dp[j], dp[j - S[i]] + F[i]);
				}
			} else {
				for (int j = 0; j - S[i] <= 2 * M; j++) {
					dp[j] = max(dp[j], dp[j - S[i]] + F[i]);
				}
			}
		}
		int ans = 0;
		for (int i = M; i <= 2 * M; i++) {
			if (dp[i] >= 0) ans = max(ans, dp[i] + i - M);
		}
		cout << ans << endl;
	}
	return 0;
}

