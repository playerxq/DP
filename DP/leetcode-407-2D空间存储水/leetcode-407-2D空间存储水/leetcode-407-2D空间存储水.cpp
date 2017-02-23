// leetcode-407-2D空间存储水.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	int m;
	int n;
	int trapRainWater(vector<vector<int>>& heightMap) {
		if (heightMap.size() == 0)
			return 0;
		m = heightMap.size();
		if (m == 1||m==2)
			return 0;
		n = heightMap[0].size();
		if (n == 0 || n == 1 || n == 2)
			return 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
		vector<vector<int>> dir{ { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		vector<vector<int>> visited(m, vector<int>(n, 0));
		int ans = 0, Max = INT_MIN; 
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!(i == 0 || i == m - 1 || j == 0 || j == n - 1)) continue;
				que.push(make_pair(heightMap[i][j], i*n + j));
				visited[i][j] = 1;
			}
		}
		while (!que.empty())
		{
			auto val = que.top(); que.pop();
			int height = val.first, x = val.second / n, y = val.second%n;
			Max = max(Max, height);
			for (auto d : dir)
			{
				int x2 = x + d[0], y2 = y + d[1];
				if (x2 >= m || x2<0 || y2<0 || y2 >= n || visited[x2][y2]) continue;
				visited[x2][y2] = 1;
				if (heightMap[x2][y2] < Max) ans += Max - heightMap[x2][y2];
				que.push(make_pair(heightMap[x2][y2], x2*n + y2));
			}
		}
		return ans;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> ve;
	vector<int> v1;
	v1.push_back(14);
	v1.push_back(20);
	v1.push_back(11);
	v1.push_back(19);
	v1.push_back(19);
	v1.push_back(16);
	ve.push_back(v1);
	vector<int> v2;
	v2.push_back(11);
	v2.push_back(10);
	v2.push_back(7);
	v2.push_back(4);
	v2.push_back(9);
	v2.push_back(6);
	ve.push_back(v2);
	vector<int> v3;
	v3.push_back(17);
	v3.push_back(2);
	v3.push_back(2);
	v3.push_back(6);
	v3.push_back(10);
	v3.push_back(9);
	ve.push_back(v3);
	vector<int> v4;
	v4.push_back(15);
	v4.push_back(9);
	v4.push_back(2);
	v4.push_back(1);
	v4.push_back(4);
	v4.push_back(1);
	ve.push_back(v4);
	vector<int> v5;
	v5.push_back(15);
	v5.push_back(5);
	v5.push_back(5);
	v5.push_back(5);
	v5.push_back(8);
	v5.push_back(7);
	ve.push_back(v5);
	vector<int> v6;
	v6.push_back(14);
	v6.push_back(2);
	v6.push_back(8);
	v6.push_back(6);
	v6.push_back(10);
	v6.push_back(7);
	ve.push_back(v6);
	Solution s;
	s.trapRainWater(ve);
	return 0;
}

