// leetcode-546-线性记忆化.cpp : 定义控制台应用程序的入口点。
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
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	int removeBoxes(vector<int>& boxes) {
		int n = boxes.size();
		int memo[100][100][100] = { 0 };
		//vector<vector<vector<int>>> memo(n,vector<vector<int>>(n, vector<int>(n,0)));
		return dfs(boxes, memo, 0, n - 1, 0);
	}

	int dfs(vector<int>& boxes, int memo[100][100][100], int l, int r, int k){
		if (l>r) return 0;
		if (memo[l][r][k] != 0) return memo[l][r][k];

		memo[l][r][k] = dfs(boxes, memo, l, r - 1, 0) + (k + 1)*(k + 1);
		for (int i = l; i<r; i++){
			if (boxes[i] == boxes[r]){
				memo[l][r][k] = max(memo[l][r][k], dfs(boxes, memo, l, i, k + 1) + dfs(boxes, memo, i + 1, r - 1, 0));
			}
		}
		return memo[l][r][k];
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

