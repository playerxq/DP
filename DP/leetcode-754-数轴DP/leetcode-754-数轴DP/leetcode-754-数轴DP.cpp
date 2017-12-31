// leetcode-754- ˝÷·DP.cpp : Defines the entry point for the console application.
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
	int reachNumber(int target) {
		if (target == 0)
			return 0;
		target = abs(target);
		long long k = sqrt(2 * target);
		long long sum = (k + 1)*k / 2;
		while (sum < target || (sum - target) % 2 != 0)
		{
			k++;
			sum = (k + 1)*k / 2;
		}
		return (int)k;
	}
};

int main()
{
	Solution s;
	int res = s.reachNumber(4);
	printf("%d",res);
    return 0;
}

