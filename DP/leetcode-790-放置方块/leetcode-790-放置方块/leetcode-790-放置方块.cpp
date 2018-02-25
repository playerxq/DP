// leetcode-790-∑≈÷√∑ΩøÈ.cpp : Defines the entry point for the console application.
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
	int numTilings(int N) {
		if (N == 1)
			return 1;
		if (N == 2)
			return 2;
		vector<long long> f(N + 1, 0);
		vector<long long> B(N + 1, 0);
		f[1] = 1;
		f[2] = 2;
		B[1] = 1;
		for (int i = 3; i <= N; i++)
		{
			B[i-1] = B[i - 2] % 1000000007 + f[i - 3] % 1000000007;
			B[i-1] = (B[i-1] % 1000000007);
			f[i] = f[i - 1] % 1000000007 + f[i - 2] % 1000000007 + (2 * B[i - 1]) % 1000000007;
			f[i] = (f[i] % 1000000007);
		}
		return f[N];
	}
};
int main()
{
	Solution s;
	int a = s.numTilings(30);
    return 0;
}

