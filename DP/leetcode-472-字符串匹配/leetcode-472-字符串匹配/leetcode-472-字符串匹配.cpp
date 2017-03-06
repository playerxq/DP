// leetcode-472-字符串匹配.cpp : 定义控制台应用程序的入口点。
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
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	int dfs(string word, unordered_set<string>& mp)
	{
		if (word.size() == 0 || mp.size() == 0)
			return false;
		vector<int> dp(word.size()+1,0);
		dp[0] = 1;
		for (int i = 1; i <= word.size(); i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (dp[j] == 1 && mp.find(word.substr(j, i - j)) != mp.end())
				{
					dp[i] = 1;
					break;
				}
			}
		}
		return dp[word.size()];
		
	}
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		vector<string> res;
		auto mycom = [&](const string& s1, const string& s2){return s1.size() < s2.size(); };
		sort(words.begin(),words.end(),mycom);
		unordered_set<string> mp;
		for (auto word : words)
		{
			if (dfs(word, mp))
				res.push_back(word);
			else
				mp.insert(word);
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

