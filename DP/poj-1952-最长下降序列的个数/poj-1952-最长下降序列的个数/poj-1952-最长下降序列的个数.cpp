// poj-1952-最长下降序列的个数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = (5000 + 50);
int n, num[MAXN]; 
int dp[MAXN], Count[MAXN];

int main()
{
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			cin >> num[i];
			dp[i] = Count[i] = 1;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (num[i] < num[j] && dp[i] < dp[j] + 1) {//原来i结尾的序列长度小于将i作为j后接元素形成序列的长度，则i应作为j结尾的序列的最后的新元素 即i结尾的序列个数等于j结尾序列个数
					dp[i] = dp[j] + 1;
					Count[i] = Count[j];
				} else if (num[i] < num[j] && dp[i] == dp[j] + 1) {//相等时 原来i结尾的序列个数应加上将i后接到j上形成的序列个数
					Count[i] += Count[j];
				}
			}
			//为了避免重复计算的情况
			for (int j = 1; j < i; j++) {
				if (num[j] == num[i]) Count[j] = 0;//前面有相同结尾的元素 清0
			}
		}
		int ans1 = 0, ans2 = 0;
		for (int i = 1; i <= n; i++) {
			ans1 = max(ans1, dp[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (dp[i] == ans1) ans2 += Count[i];
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}

