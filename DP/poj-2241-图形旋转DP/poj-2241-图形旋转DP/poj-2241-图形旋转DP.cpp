// poj-2241-图形旋转DP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200;
struct Node {
	int x, y, z;
} node[MAXN];

int n, m, dp[MAXN];
int num[3];


int cmp(const Node &p, const Node &q)
{
	if (p.x != q.x) {
		return p.x > q.x;
	}
	return p.y > q.y;
}

int main()
{
	int t = 1;
	while (cin >> m && m != 0) {
		n = 0;
		while (m--) {
			cin >> num[0] >> num[1] >> num[2];
			sort(num, num + 3);
			//对每块砖头  枚举6种旋转 底长高的不同排列
			node[n].x = num[0], node[n].y = num[1], node[n].z = num[2];
			node[n + 1].x = num[0], node[n + 1].y = num[2], node[n + 1].z = num[1];
			node[n + 2].x = num[1], node[n + 2].y = num[0], node[n + 2].z = num[2];
			node[n + 3].x = num[1], node[n + 3].y = num[2], node[n + 3].z = num[0];
			node[n + 4].x = num[2], node[n + 4].y = num[0], node[n + 4].z = num[1];
			node[n + 5].x = num[2], node[n + 5].y = num[1], node[n + 5].z = num[0];
			n += 6;
		}
		sort(node, node + n, cmp);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			dp[i] = node[i].z;
			for (int j = 0; j < i; j++) {
				if (node[j].x > node[i].x && node[j].y > node[i].y) {
					dp[i] = max(dp[i], dp[j] + node[i].z);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, dp[i]);
		}
		cout << "Case " << t++ << ": maximum height = " << ans << endl;
	}
	return 0;
}

