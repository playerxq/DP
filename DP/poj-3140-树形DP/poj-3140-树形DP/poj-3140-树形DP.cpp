// poj-3140-树形DP.cpp : 定义控制台应用程序的入口点。
//dp[u]表示以u为根的所有子树的和，则有ans = min(ans, (sum - dp[u]) - dp[u])

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = (100000 + 10);
const int MAXM = (1000000 + 100);
typedef long long ll;
template< class T > inline T getMIN(const T &a, const T &b)
{
	return a < b ? a : b;
}

template< class T > inline T ABS(const T &a)
{
	return a < 0 ? -a : a;
}

struct Edge {
	int v, next;
} edge[MAXM << 1];

int NE, head[MAXN];

void Insert(int u, int v)
{
	edge[NE].v = v;
	edge[NE].next = head[u];
	head[u] = NE++;
}

int N, M;
ll ans, sum;
ll num[MAXN], dp[MAXN];

ll dfs(int u, int father) 
{
	dp[u] = num[u];
	for (int i = head[u]; i != -1; i = edge[i].next) {
		int v = edge[i].v;
		if (v == father) continue;
		dp[u] += dfs(v, u);
	}
	ans = getMIN(ans, ABS(sum - dp[u] - dp[u]));
	return dp[u];
}
	
int main()
{
	int t = 1;
	while (~scanf("%d %d", &N, &M)) {
		if (N == 0 && M ==0) break;
		sum = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &num[i]);
			sum += num[i];
		}
		NE = 0;
		memset(head, -1, sizeof(head));
		while (M--) {
			int u, v;
			scanf("%d %d", &u, &v);
			Insert(u, v);
			Insert(v, u);
		}
		ans = 1LL << 60;
		dfs(1, -1);
		cout << "Case " << t++ << ": " << ans << endl;
	}
	return 0;
}

