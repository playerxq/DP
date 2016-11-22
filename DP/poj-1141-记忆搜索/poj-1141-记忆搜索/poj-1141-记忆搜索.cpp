// poj-1141-记忆搜索.cpp : 定义控制台应用程序的入口点。
//dp[i][j]表示从第i个数字到第j个数字最少要插入的字符数，dp[i][j] = dp[i][k] + dp[k + 1][j]
//str[i] ==‘（’ && str[j] == ')' ||  str[i] == '[' && str[j] == ']'时，有dp[i][j] = dp[i + 1][j - 1]
#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = (100 + 10);
const int inf = 0x3f3f3f3f;
char str[MAXN];
int dp[MAXN][MAXN];
int n;
int path[MAXN][MAXN];
void Solve(int i, int j)
{
	if (i > j) return;
	if (i == j) {
		if (str[i] == '[' || str[i] == ']') {
			printf("[]");
		} else 
			printf("()");
		return;
	}
	if (path[i][j] == -1) {//i,j为括号对称
		printf("%c", str[i]);
		Solve(i + 1, j - 1);
		printf("%c", str[j]);
	} else {
		Solve(i, path[i][j]);
		Solve(path[i][j] + 1, j);
	}
}


int main()
{
	while (gets(str)) {
		n = strlen(str);
		if (n == 0) {
			puts("");
			continue;
		}
		memset(dp, 0, sizeof(dp));
		memset(path, 0, sizeof(path));
		for (int i = 0; i < n; i++) dp[i][i] = 1;
		for (int l = 1; l < n; l++) {
			for (int i = 0; i < n - l; i++) {//i+l<n
				int j = i + l;
				dp[i][j] = inf;
				if ((str[i] == '(' && str[j] == ')') || (str[i] == '[' && str[j] == ']')) {
					if (dp[i][j] > dp[i + 1][j - 1]) {
						dp[i][j] = dp[i + 1][j - 1];
						path[i][j] = -1;
					}
				}
				for (int k = i; k < j; k++) {
					if (dp[i][j] > dp[i][k] + dp[k + 1][j]) {
						dp[i][j] = dp[i][k] + dp[k + 1][j];
						path[i][j] = k;
					}
				}
			}
		}
		Solve(0, n - 1);
		puts("");
	}
	return 0;
}

