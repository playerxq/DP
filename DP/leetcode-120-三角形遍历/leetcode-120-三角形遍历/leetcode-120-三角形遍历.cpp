// leetcode-120-三角形遍历.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int nr = triangle.size();
		if(nr==0)
			return 0;
		vector<int> dp(nr+1);
		dp[0] = triangle[0][0];
		for(int r = 1;r<nr;r++)
		{
			dp[r] = dp[r-1]+triangle[r][r];
			for(int c = r-1;c>=1;c--)
			{
				dp[c] = min(dp[c-1]+triangle[r][c],dp[c]+triangle[r][c]);
			}
			dp[0] = dp[0]+triangle[r][0];
		}
		int minx = 0x3f3f3f3f;
		for(int i = 0;i<nr;i++)
		{
			if(dp[i]<minx)
				minx = dp[i];
		}
		return minx;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

