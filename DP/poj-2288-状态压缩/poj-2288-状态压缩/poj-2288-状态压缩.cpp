// poj-2288-状态压缩.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
long long val[14];
long long dp[14][14][(1 << 14) + 1];
long long ways[14][14][(1 << 14) + 1];
bool map[14][14];

void getDP()
{
	memset(ways, 0, sizeof(ways));
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j && map[i][j]) {
				dp[i][j][(1 << i) + (1 << j)] = val[i] + val[j] + val[i] * val[j];
		 		ways[i][j][(1 << i) + (1 << j)] = 1;
			}
		}
	}
	for (int s = 0; s < (1 << N); s++) {
		//当前在点j
		for (int j = 0; j < N; j++) if (s & (1 << j)) {
			//上一个点在点i
			for (int i = 0; i < N; i++) if (i != j && (s & (1 << i)) && map[i][j]) {
				if (dp[i][j][s] == -1) continue;
				for (int k = 0 ; k < N; k++) if (k != i && k != j && !(s & (1 << k))) {//枚举从j的扩展点k
					if (map[j][k]) {
						long long tmp = dp[i][j][s] + val[k] + val[j] * val[k];
						if (map[i][k]) {
							tmp += val[i] * val[j] * val[k];
						}
						if (dp[j][k][s + (1 << k)] < tmp) {
							dp[j][k][s + (1 << k)] = tmp;
							ways[j][k][s + (1 << k)] = ways[i][j][s];//相同最小值的个数  此时完全由s扩展而来
						} else if (dp[j][k][s + (1 << k)] == tmp) {
							ways[j][k][s + (1 << k)] += ways[i][j][s];//s扩展的最小值可以加到目标上
						}
					}
				}
			}
		}
	}
}
				 


int main()
{
	int Case;
	cin >> Case;
	while (Case--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) cin >> val[i];
		memset(map, false, sizeof(map));
		while (M--) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			map[u][v] = map[v][u] = true;
		}
		if (N == 1) {
			cout << val[0] << " " << 1 << endl;
			continue;
		}
		getDP();
		long long ans1 = -1, ans2 = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) if (i != j) {
				if (dp[i][j][(1 << N) - 1] > ans1) {
					ans1 = dp[i][j][(1 << N) - 1];
					ans2 = ways[i][j][(1 << N) - 1];
				} else if (dp[i][j][(1 << N) - 1] == ans1) {
					ans2 += ways[i][j][(1 << N) - 1];
				}
			}
		}
		if (ans1 == -1) {
			cout <<  0 << " " << 0 << endl;
		} else 
			cout << ans1 << " " << ans2 / 2 << endl;
	}
	return 0;
}

