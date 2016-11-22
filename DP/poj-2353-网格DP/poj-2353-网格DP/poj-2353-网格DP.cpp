// poj-2353-网格DP.cpp : 定义控制台应用程序的入口点。
//dp[i][j]表示到第i层第j个房间的最小值,于是有dp[i][j] = min(dp[i- 1][j], dp[i][j - 1], dp[i][j + 1]) + num[i][j]
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
const int MAXN = (500 + 10);
const int MAXM = (100 + 10);
int M, N, num[MAXM][MAXN];
int dp[MAXM][MAXN];
pair<int, int > path[MAXM][MAXN];

void Solve(int x, int y)
{
	if (x == 1) {
		cout << y << endl;
		return;
	}
	Solve(path[x][y].first, path[x][y].second);
	cout << y << endl;
}

int main()
{
	while (cin >> M >> N) {
		for (int i = 1; i <= M; i++) 
			for (int j = 1; j <= N; j++)
				cin >> num[i][j];
		memset(dp, 0x3f, sizeof(dp));
		for (int i = 1; i <= N; i++) {
			dp[1][i] = num[1][i];
		}
		for (int i = 2; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				if (dp[i][j] > dp[i - 1][j] + num[i][j]) {
					dp[i][j] = dp[i - 1][j] + num[i][j];
					path[i][j].first = i - 1;//记录(i,j)位置的上一个位置
					path[i][j].second = j;
				}
			}
			for (int j = 2; j <= N; j++) {
				if (dp[i][j] > dp[i][j - 1] + num[i][j]) {
					dp[i][j] = dp[i][j - 1] + num[i][j];
					path[i][j].first = i;
					path[i][j].second = j - 1;
				}
			}
			for (int j = N - 1; j >= 1; j--) {
				if (dp[i][j] > dp[i][j + 1] + num[i][j]) {
					dp[i][j] = dp[i][j + 1] + num[i][j];
					path[i][j].first = i;
					path[i][j].second = j + 1;
				}
			}
		}
		/*
		for (int i = 1 ; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}*/
		int col = -1, ans = 0x3f3f3f3f;
		for (int i = 1; i <= N; i++) {
			if (dp[M][i] < ans) ans = dp[M][i], col = i;
		}
	//	cout << M << " " << col << endl;
		Solve(M, col);
	}
	return 0;
}

