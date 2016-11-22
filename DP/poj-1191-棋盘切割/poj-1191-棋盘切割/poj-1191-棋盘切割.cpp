// poj-1191-棋盘切割.cpp : 定义控制台应用程序的入口点。
//dp[x1][y1][x2][y2][k]为区域切k刀的值  枚举第一刀  横切或者竖切
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
double ans = 1LL<<60;
int sum[9][9], array[9][9];
double dp[9][9][9][9][16];
int vis[9][9][9][9][16];
int n;

double getSum(int x1, int y1, int x2, int y2)
{
	double tmp = sum[x2][y2] - (sum[x1 - 1][y2] + sum[x2][y1 - 1] - sum[x1 - 1][y1 - 1]);
	return tmp * tmp;
}
double dfs(int x1, int y1, int x2, int y2, int k)
{
	if (k == 0) {
		return getSum(x1, y1, x2, y2);
	}
	if(vis[x1][y1][x2][y2][k])
		return dp[x1][y1][x2][y2][k];
	vis[x1][y1][x2][y2][k]=1;
	double ans = 1LL << 60;
	for(int i = x1;i<x2;i++)
	{
		ans = min(ans, dfs(x1, y1, i, y2, k - 1) + getSum(i + 1, y1, x2, y2));
        ans = min(ans, dfs(i + 1, y1, x2, y2, k - 1) + getSum(x1, y1, i, y2));
	}
	for (int i = y1; i < y2; i++) {
        ans = min(ans, dfs(x1, y1, x2, i, k - 1) + getSum(x1, i + 1, x2, y2));
        ans = min(ans, dfs(x1, i + 1, x2, y2, k - 1) + getSum(x1, y1, x2, i));
    }
	return dp[x1][y1][x2][y2][k]=ans;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while (cin >> n) {
		double aver = 0.0;
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				scanf("%d", &array[i][j]);
				aver += array[i][j];
				sum[i][j] = array[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			}
		}
		aver /= n;
		for (int i = 1; i <= 8; i++) 
			for (int j = 1; j <= 8; j++) 
				for (int k = 1; k <= 8; k++) 
					for (int l = 1; l <= 8; l++) 
						for (int p = 0; p <= 15; p++)
							dp[i][j][k][l][p] = 0;
		double ans = dfs(1, 1, 8, 8, n - 1);
		printf("%.3lf\n", sqrt(ans / n - aver * aver));
	}
	return 0;
}

