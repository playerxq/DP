// leetcode-714-股票交易-有交易费.cpp : Defines the entry point for the console application.
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
//s0 = profit having no stock
//s1 = profit having 1 stock
//update s0 by selling the stock from s1, so s0 = max(s0, s1+p-fee);
//update s1 by buying the stock from s0, so s1 = max(s1, s0 - p);
class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int n = prices.size();
		int s0 = 0;
		int s1 = -1000000;
		for (auto p : prices)
		{
			int tmp = s0;
			s0 = max(s0,s1+p-fee);//fee只存在于卖的时候
			s1 = max(tmp-p,s1);
		}
		return s0;
	}
};

int main()
{
    return 0;
}

