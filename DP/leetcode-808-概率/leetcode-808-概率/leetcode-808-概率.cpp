// leetcode-808-¸ÅÂÊ.cpp : Defines the entry point for the console application.
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
	unordered_map<int, unordered_map<int, double>> store;
	double dfs(int A, int B)
	{
		if (A == 0 && B != 0)
			return 1;
		else if (A == 0 && B == 0)
			return 0.5;
		else if (A != 0 && B == 0)
			return 0;
		if (store[A][B] != 0)
			return store[A][B];
		double prob = 0;
		prob += 0.25 * dfs(A - min(A, 100), B);
		prob += 0.25 * dfs(A - min(A, 75), B - min(B, 25));
		prob += 0.25 * dfs(A - min(A, 50), B - min(B, 50));
		prob += 0.25 * dfs(A - min(A, 25), B - min(B, 75));
		store[A][B] = prob;
		return prob;
	}
	double soupServings(int N) {
		if (N >= 5000)
			return 1;
		return dfs(N,N);
	}
};
int main()
{
    return 0;
}

