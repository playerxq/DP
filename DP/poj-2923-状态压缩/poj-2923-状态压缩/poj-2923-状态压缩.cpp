// poj-2923-状态压缩.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n, C1, C2, weight[11];
int dp[(1 << 11) + 11];
vector<int > Vet;
bool OK(int state, int C1, int C2)
{
	int tmp[11], k = 0;
	for (int i = 0; i < n; i++) {
		if (state & (1 << i)) tmp[k++] = weight[i];//当前状态下哪些被使用
	}
	for (int s = 0; s < (1 << k); s++) {
		int tmp1 = C1, tmp2 = C2;
		for (int i = 0; i < k; i++) {
			if (s & (1 << i)) tmp1 -= tmp[i];
			else tmp2 -= tmp[i];
			if (tmp1 < 0 || tmp2 < 0) break;
		}
		if (tmp1 >= 0 && tmp2 >= 0) return true;
	}
	return false;
}

int getDP()
{
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	int size = (int)Vet.size();
	for (int state = 0; state < (1 << n); state ++) {
		for (int i = 0; i < size; i++) if (!(state & (Vet[i]))) {
			if (dp[state] == 0x3f3f3f3f) continue;
			dp[state | Vet[i]] = min(dp[state | Vet[i]], dp[state] + 1);
		}
	}
	return dp[(1 << n) - 1];
}


int main()
{
	int _case, t = 1;
	cin >> _case;
	while (_case--) {
		cin >> n >> C1 >> C2;
		Vet.clear();
		for (int i = 0; i < n; i++) {
			cin >> weight[i];
		}
		for (int s = 0; s < (1 << n); s++) {//枚举可行状态
			if (OK(s, C1, C2)) Vet.push_back(s);
		}
		cout << "Scenario #" << t++ << ":" << endl;
		cout << getDP() << endl << endl;
	}
	return 0;
}

