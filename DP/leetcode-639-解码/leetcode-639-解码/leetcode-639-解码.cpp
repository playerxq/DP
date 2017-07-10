// leetcode-639-½âÂë.cpp : Defines the entry point for the console application.
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
/*
*ºÅ´ú±í1-9
For any string s longer than 2, we can decode either the last 2 characters as a whole 
or the last 1 character. 
So dp[i] = dp[i-1]* f(s.substr(i,1)) + dp[i-2]* f(s.substr(i-1, 2)). 
f() is the number of ways to decode a string of length 1 or 2. 
f() could be 0, for example f("67").
There is a lot of cases and corner cases for f(string s). 
For example, * cannot be '0', so ** has 15 instead of 16 possibilities, 
because "10,20" are excluded.
*/
class Solution {
public:
	int solve(string s)
	{
		if (s.size() == 1) {
			if (s[0] == '*') return 9;
			return s[0] == '0' ? 0 : 1;
		}
		if (s == "**")
			return 15;
		else if (s[1] == '*') {
			if (s[0] == '1') return 9;
			return s[0] == '2' ? 6 : 0;
		}
		else if (s[0] == '*')
			return s[1] <= '6' ? 2 : 1;
		else
			// if two digits, it has to be in [10 26]; no leading 0
			return stoi(s) >= 10 && stoi(s) <= 26 ? 1 : 0;
	}
	int numDecodings(string s) {
		int n = s.size();
		int p = 1000000007;
		long f1 = 1;
		long f2 = solve(s.substr(0,1));
		for (int i = 1; i < n; i++)
		{
			long f3 = f2*solve(s.substr(i, 1)) + f1*solve(s.substr(i-1,2));
			f1 = f2;
			f2 = f3%p;
		}
		return f2;
	}
};
int main()
{
    return 0;
}

