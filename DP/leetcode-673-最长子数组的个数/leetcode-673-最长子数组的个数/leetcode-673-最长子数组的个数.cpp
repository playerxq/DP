// leetcode-673-最长子数组的个数.cpp : Defines the entry point for the console application.
//
/*
For a sequence of numbers,
cnt[k] is total number of longest subsequence ending with nums[k];
len[k] is the length of longest subsequence ending with nums[k];
len[k+1] = max(len[k+1], len[i]+1) for all i <= k and nums[i] < nums[k+1];
cnt[k+1] = sum(cnt[i]) for all i <= k and nums[i] < nums[k+1] and len[i] = len[k+1]-1;
*/
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
	int findNumberOfLIS(vector<int>& nums) {
		int n = nums.size(), maxlen = 1, ans = 0;
		vector<int> cnt(n, 1), len(n, 1);
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					if (len[j] + 1 > len[i]) {
						len[i] = len[j] + 1;//len[k+1] = max(len[k+1], len[i]+1)
						cnt[i] = cnt[j];//cnt[k+1] = sum(cnt[i]) for all i <= k and nums[i] < nums[k+1] and len[i]+1 = len[k+1];
					}
					else if (len[j] + 1 == len[i])
						cnt[i] += cnt[j];//cnt[k+1] = sum(cnt[i]) for all i <= k and nums[i] < nums[k+1] and len[i]+1 = len[k+1];
				}
			}
			maxlen = max(maxlen, len[i]);
		}
		for (int i = 0; i < n; i++)
			if (len[i] == maxlen) ans += cnt[i];
		return ans;
	}
};

int main()
{
    return 0;
}

