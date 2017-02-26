// leetcode-416-分割子集.cpp : 定义控制台应用程序的入口点。
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
#include <bitset>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int n = nums.size();
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += nums[i];
		if (sum % 2)
			return false;
		sum = sum / 2;
		bitset<20001> bits;
		bits |= 1;
		for (int i = 0; i < n; i++)
		{
			bits |= bits << nums[i];
		}
		return bits[sum] == 1 ? true:false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

