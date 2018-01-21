// leetcode-768-数组重排2.cpp : Defines the entry point for the console application.
//
// leetcode-769-数组重排1.cpp : Defines the entry point for the console application.
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
	int maxChunksToSorted(vector<int>& arr) {
		int n = arr.size();
		if (!n)
			return 0;
		if (n == 1)
			return 1;
		vector<int> mx(n, 0);
		vector<int> mi(n, 0);
		mx[0] = arr[0];
		for (int i = 1; i < n; i++)
		{
			mx[i] = max(mx[i - 1], arr[i]);
		}
		mi[n - 1] = arr[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			mi[i] = min(mi[i + 1], arr[i]);
		}
		int res = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (mx[i] <= mi[i + 1])
				res++;
		}
		return res + 1;
	}
};

int main()
{
	Solution s;
	vector<int> ve = { 2,2,1,1};
	s.maxChunksToSorted(ve);
	return 0;
}



