// leetcode-354-最长子序列.cpp : 定义控制台应用程序的入口点。
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

bool cmp(pair<int, int> i, pair<int, int> j) {
	if (i.first == j.first)
		return i.second > j.second;
	return i.first < j.first;
}
class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		int N = envelopes.size();
		vector<int> B;
		sort(envelopes.begin(), envelopes.end(), cmp);
		for (int i = 0; i < N; i++) {
			int lo = 0, hi = B.size() - 1;
			while (lo <= hi) {
				int mid = lo + (hi - lo) / 2;
				if (envelopes[i].second > envelopes[B[mid]].second)
					lo = mid + 1;
				else
					hi = mid - 1;
			}
			if (lo == B.size())
				B.push_back(i);
			else
				B[lo] = i;
		}
		return B.size();
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<pair<int, int>> ve;
	ve.push_back(make_pair(4, 5));
	ve.push_back(make_pair(4, 6));
	ve.push_back(make_pair(6, 7));
	ve.push_back(make_pair(2,3));
	ve.push_back(make_pair(1, 1));
	
	Solution s;
	s.maxEnvelopes(ve);
	return 0;
}

