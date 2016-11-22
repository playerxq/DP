// poj-3042-ֱ��DP.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
dp[i][j][0]��ʾi��j֮���Ѿ��߹�������������i�����Сֵ��dp[i][j][1]��ʾ������j�㣬���Ƕ�����i�㣬���ܴ�i +1 - > i, Ҳ���ܴ�j - i,����

dp[i][j][0] = min(dp[i + 1][j][0]  + (n - (j - i) ) * (pos[i + 1] - pos[i]), dp[i + 1][j][1] + (n - (j - i)) * (pos[j] - pos[i]));

ͬ����ڵ�ǰ��j�㣬Ҳ���Եõ�����Ӧ�ķ��̣�dp[i][j][1] = min(dp[i][j-1][1] + (n - (j - i)) * (pos[j] - pos[j - 1), dp[i][j - 1][0] + (n - (j - i)) * (pos[j] - pos[i])).
*/
#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = (1000 + 10);
int N, L, pos[MAXN];
int dp[MAXN][MAXN][2];

int main()
{
	while (cin >> N >> L) {
		int p = -1;
		for (int i = 0; i < N; i++) {
			cin >> pos[i];
			if (pos[i] == L) p = i;
		}
		sort(pos, pos + N);
		if (p == -1) {
			pos[N++] = L;
			sort(pos, pos + N);
			for (int i = 0; i < N; i++) {
				if (pos[i] == L) p = i;
			}
		}
		memset(dp, 0x3f, sizeof(dp));
		dp[p][p][0] = dp[p][p][1] = 0;
		for (int i = p; i >= 0; i--) {
			for (int j = p; j < N; j++) {
				dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][0] + (N - (j - i)) * (pos[i + 1] - pos[i]));
				dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][1] + (N - (j - i)) * (pos[j] - pos[i]));
				dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + (N - (j - i)) * (pos[j] - pos[j - 1]));
				dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + (N - (j - i)) * (pos[j] - pos[i]));
			}
		}
		cout << min(dp[0][N - 1][0], dp[0][N - 1][1]) << endl;
	}
	return 0;
}

