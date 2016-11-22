// poj-2486-树形DP.cpp : 定义控制台应用程序的入口点。
//
/*
dp[i][j][0]表示从节点i出发,能走j步，最后回到i点的最大值，dp[i][j][1]表示从i点出发走j步最后停留在i的某棵子树上点最大值，于是可以得出一下三种情况:

dp[0][s][j+2]=Max(dp[0][s][j+2],dp[0][t][k]+dp[0][s][j-k]);//从s出发，要回到s，需要多走两步s- >t,t- > s,分配给t子树k步，其他子树j-k步，都返回
dp[1][s][j+2]=Max(dp[1][s][j+2],dp[0][t][k]+dp[1][s][j-k]);//从s到t 再从t到s用2步  t子树内部遍历返回t  其余步数相当于从s走j-k步并不返回s
dp[1][s][j+1]=Max(dp[1][s][j+1],dp[1][t][k]+dp[0][s][j-k]);//先遍历s的其他子树，回到s，s - > t, 遍历t子树，在当前子树t不返回，多走一步.
*/

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = (100 + 10);
const int MAXM = (200 + 20);

int n, m;
int num[MAXN];
int dp[MAXN][MAXM][2];
vector<int > g[MAXN];

void dfs(int u, int father)//从u出发
{
	for (int i = 0; i <= m; i++) {//走i步
		dp[u][i][0] = dp[u][i][1] = num[u];
	}
	for (int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i];
		if (v == father) continue;
		dfs(v, u);
		for (int j = m; j >= 0; j--) {
			for (int k = 0; k <= j; k++) {
				//s返回，t返回
				dp[u][j + 2][0] = max(dp[u][j + 2][0], dp[v][k][0] + dp[u][j - k][0]);
				//s不返回,t返回
				dp[u][j + 2][1] = max(dp[u][j + 2][1], dp[v][k][0] + dp[u][j - k][1]);
				//s返回，t不返回
				dp[u][j + 1][1] = max(dp[u][j + 1][1], dp[u][k][0] + dp[v][j - k][1]);
			}
		}
	}
}

int main()
{
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= n; i++) {
			cin >> num[i];
		}
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, -1);
		cout << dp[1][m][1] << endl;
	}
	return 0;
}

