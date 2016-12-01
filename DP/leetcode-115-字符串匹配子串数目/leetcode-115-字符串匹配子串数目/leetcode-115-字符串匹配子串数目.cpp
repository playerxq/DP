// leetcode-115-字符串匹配子串数目.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        int l1 = s.length();
		int l2 = t.length();
		if(l1<l2)
			return 0;
		int** dp = new int* [l1+1];
		for(int i = 0;i<=l1;i++)
			dp[i] = new int[l2+1];
		for(int i = 0;i<l1+1;i++)
			for(int j = 0;j<l2+1;j++)
				dp[i][j] = 0;
		dp[0][0] = 1;
		for(int i = 1;i<=l1;i++)
			dp[i][0] = 1;
		for(int i = 1;i<=l1;i++)
		{
			for(int j = 1;j<=l2;j++)
			{
				if(s[i-1]==t[j-1])
				{
					dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
				}
				else
					dp[i][j] = dp[i-1][j];
			}
		}
		return dp[l1][l2];
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

