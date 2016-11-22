// poj-2486-����DP.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
dp[i][j][0]��ʾ�ӽڵ�i����,����j�������ص�i������ֵ��dp[i][j][1]��ʾ��i�������j�����ͣ����i��ĳ�������ϵ����ֵ�����ǿ��Եó�һ���������:

dp[0][s][j+2]=Max(dp[0][s][j+2],dp[0][t][k]+dp[0][s][j-k]);//��s������Ҫ�ص�s����Ҫ��������s- >t,t- > s,�����t����k������������j-k����������
dp[1][s][j+2]=Max(dp[1][s][j+2],dp[0][t][k]+dp[1][s][j-k]);//��s��t �ٴ�t��s��2��  t�����ڲ���������t  ���ಽ���൱�ڴ�s��j-k����������s
dp[1][s][j+1]=Max(dp[1][s][j+1],dp[1][t][k]+dp[0][s][j-k]);//�ȱ���s�������������ص�s��s - > t, ����t�������ڵ�ǰ����t�����أ�����һ��.
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

void dfs(int u, int father)//��u����
{
	for (int i = 0; i <= m; i++) {//��i��
		dp[u][i][0] = dp[u][i][1] = num[u];
	}
	for (int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i];
		if (v == father) continue;
		dfs(v, u);
		for (int j = m; j >= 0; j--) {
			for (int k = 0; k <= j; k++) {
				//s���أ�t����
				dp[u][j + 2][0] = max(dp[u][j + 2][0], dp[v][k][0] + dp[u][j - k][0]);
				//s������,t����
				dp[u][j + 2][1] = max(dp[u][j + 2][1], dp[v][k][0] + dp[u][j - k][1]);
				//s���أ�t������
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

