// leetcode-638-����.cpp : Defines the entry point for the console application.
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
	int get_key(vector<int>& needs) {
		int n = needs.size(), key = 0;
		for (int i = n - 1, p = 1; i >= 0; i--, p *= 10)
			key += needs[i] * p;
		return key;
	}
	int helper(vector<int>& price, vector<vector<int>>& special, unordered_map<int, int>& mp, int k) {
		if (mp.count(k)) return mp[k];
		int n = price.size(), ans = 0;
		// pows is to help get each digit of key
		vector<int> pows(n, 1);
		for (int i = n - 2; i >= 0; i--) pows[i] = pows[i + 1] * 10;
		for (int i = 0; i < n; i++) ans += ((k / pows[i]) % 10)*price[i];
		for (auto spe : special) {
			int key = 0, i = 0;
			// check whether this offer is valid
			while (i < n) {
				int t = (k / pows[i]) % 10;
				if (t >= spe[i])
					key = key * 10 + (t - spe[i++]);
				else
					break;
			}
			if (i == n) ans = min(ans, spe[n] + helper(price, special, mp, key));
		}
		mp[k] = ans;
		return ans;
	}
	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		unordered_map<int, int> mp;
		return helper(price, special, mp, get_key(needs));
	}
};
int main()
{
    return 0;
}

