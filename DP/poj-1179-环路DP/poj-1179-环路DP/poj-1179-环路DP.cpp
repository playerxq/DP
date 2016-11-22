// poj-1179-��·DP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = (55 + 5);
const long long inf = (1LL << 60);
template<class T > inline T getMax(const T &a, const T &b)
{
	return a > b ? a : b;
}

template<class T > inline T getMin(const T &a, const T &b)
{
	return a < b ? a : b;
}

int n;
char opt[MAXN];
long long num[MAXN];
pair<long long, long long > dp[MAXN][MAXN]; // first = MAX, second = MIN;
vector<int >VV;

pair<long long, long long > dfs(int l, int r)
{
	if (l == r) return make_pair(num[l % n], num[r % n]);//ֱ�ӷ��ظõ��ֵ
	if (dp[l % n][r % n].first != inf) {
		return dp[l % n][r % n];
	}
	long long MAX = -inf, MIN = inf;
	for (int i = l; i < r; i++) {//ö�ٶϿ�λ��
		long long res = 0;
		pair<long long, long long > p1 = dfs(l, i), p2 = dfs(i + 1, r);
		if (opt[(i + 1) % n] == 't') {//�Ͽ���Ϊ�ӷ�
			res = p1.first + p2.first;
			MAX = getMax(res, MAX);
			res = p1.second + p2.second;
			MIN = getMin(res, MIN);
		} else {//Ϊ�˷�
			res = p1.first * p2.first;
			MAX = getMax(MAX, res);
			res = p1.second * p2.second;
			MAX = getMax(MAX, res);
			res = p1.first * p2.second;
			MIN = getMin(res, MIN);
			res = p1.second * p2.first;
			MIN = getMin(MIN, res);
		}
	}
	return dp[l % n][r % n] = make_pair(MAX, MIN);
}

int main()
{
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) 
				dp[i][j].first = dp[i][j].second = inf;
		for (int i = 0; i < n; i++) {
			cin >> opt[i] >> num[i];
		}
		long long ans = -inf;
		for (int i = 0; i < n; i++) {
			long long tmp = dfs(i, i + n - 1).first;//ö�ٻ������
			if (tmp > ans) {
				ans = tmp;
				VV.clear();
				VV.push_back(i + 1);
			} else if (tmp == ans) {
				VV.push_back(i + 1);
			}
		}
		printf("%lld\n", ans);
		for (int i = 0; i < (int)VV.size(); i++) {
			if ( i == (int)VV.size()) {
				printf("%d\n", VV[i]);
			} else 
				printf("%d ", VV[i]);
		}
	}
	return 0;
}

