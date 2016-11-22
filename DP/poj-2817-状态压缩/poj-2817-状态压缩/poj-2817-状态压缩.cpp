// poj-2817-状态压缩.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1 << 11][11];//dp[s][i]即当前串状态s 以i串结尾
int num[11][11];
int n, ans;
char str[11][11];

void Init()
{
	memset(num, 0, sizeof(num));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int len1 = strlen(str[i]), len2 = strlen(str[j]);
			int MAX = 0, cnt = 0;
			for (int k = 0; k < len1; k++) {//k为起始偏移  即从第一个串的第k个位置开始比对
				cnt = 0;
				for (int l = 0; l < len2 && k + l < len1; l++) {//
					if (str[i][k + l] == str[j][l]) cnt++;
				}
				MAX = max(MAX, cnt);//记录最大的匹配数目
			}
			for (int k = 0; k < len2; k++) {
				cnt = 0;
				for (int l = 0; l < len1 && k + l < len2; l++) {
					if (str[i][l] == str[j][k + l]) cnt++;
				}
				MAX = max(MAX, cnt);
			}
			num[i][j] = num[j][i] = MAX;
		}
	}
}

void getDP()
{
	memset(dp, 0, sizeof(dp));
	for (int s = 0; s < (1 << n); s++) {//状态s
		for (int i = 0; i < n; i++) {//找到s中的某个串i
			if (s & (1 << i)) {
				for (int j = 0; j < n; j++) {
					if (! ( s & (1 << j))) {//串j在s中未使用  尝试放到i下面
						dp[s | (1 << j)][j] = max(dp[s | (1 << j)][j], dp[s][i] + num[i][j]);
					}
				}
			}
		}
	}
	ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[(1 << n) - 1][i]);//n串全用情况下枚举最后一个串
	}
}

int main()
{
	while (cin >> n && n > 0) {
		for (int i = 0; i < n; i++) {
			cin >> str[i];
		}
		Init();
		getDP();
		cout << ans << endl;
	}
	return 0;
}

