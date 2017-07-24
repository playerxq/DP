// leetcode-646-最长增序列.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool cmp(vector<int>& a, vector<int>& b)
	{
		return a[1] < b[1];
	}
	int findLongestChain(vector<vector<int>>& pairs) {
		int n = pairs.size();
		sort(pairs.begin(),pairs.end(),cmp);
		int cnt = 0;
		for (int i = 0, j = 0; j < n; j++)
		{
			if (j == 0 || pairs[i][1] < pairs[j][0])
			{
				cnt++;
				i = j;
			}
		}
		return cnt;
	}
};


int main()
{
    return 0;
}

