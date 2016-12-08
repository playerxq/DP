// leetcode-139-字符串DP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.length();
		int* dp = new int[len+1];
		for(int i = 0;i<=len;i++)
		    dp[i] = 0;
		dp[0] = 1;
		for(int i = 1;i<=len;i++)
		{
			for(int j = i-1;j>=0;j--)
			{
				if(dp[j])
				{
					string tmp = s.substr(j,i-j);
					if(wordDict.find(tmp)!=wordDict.end())
					{
						dp[i] = 1;
						break;
					}
				}
			}
		}
		return dp[len];
    }
};
class Solution {
public:
	map<string,vector<string>> mm;
	vector<string> combine(string s, vector<string> prev)
	{
		for(int i = 0;i<prev.size();i++)
		{
			prev[i]+=" "+s;
		}
		return prev;
	}
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if(mm.count(s))
			return mm[s];
		vector<string> res;
		if(wordDict.count(s))
			res.push_back(s);
		for(int i = 1;i<s.size();i++)
		{
			if(wordDict.count(s.substr(i)))
			{
				string tmp = s.substr(0,i);
				vector<string> prev = combine(s.substr(i),wordBreak(tmp,wordDict));
				res.insert(res.end(),prev.begin(),prev.end());
			}
		}
		mm[s] = res;
		return res;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

