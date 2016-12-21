// leetcode-174-棋盘搜索.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;
int dir[2][2] = {{-1,0},{0,-1}};
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& mp) {
		int m = mp.size();
		int n = mp[0].size();
		int res;
		if(mp[m-1][n-1]<0)
			res = mp[m-1][n-1]*(-1)+1;
		else
			res = 1;
		int** dp = new int*[m+1];
		for(int i = 0;i<m;i++)
			dp[i] = new int[n+1];
		for(int i = 0;i<m;i++)
			for(int j = 0;j<n;j++)
				dp[i][j] = INT_MAX;
		dp[m-1][n-1] = res;
		for(int i = m-1;i>=0;i--)
		{
			for(int j = n-1;j>=0;j--)
			{
				if(i==m-1&&j==n-1)
				{
					continue;
				}
				if(i==m-1)
				{
					int t = dp[i][j+1]-mp[i][j];
					if(t<=0)
						t = 1;
					dp[i][j] = min(dp[i][j],t);
				}
				else if(j==n-1)
				{
					int t = dp[i+1][j]-mp[i][j];
					if(t<=0)
						t = 1;
					dp[i][j] = min(dp[i][j],t);
				}
				else
				{
					int t = min(dp[i+1][j],dp[i][j+1])-mp[i][j];
					if(t<=0)
						t = 1;
					dp[i][j] = min(dp[i][j],t); 
				}
			}
		}
		return dp[0][0];
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<vector<int>> ve;
	vector<int> nums;
	nums.push_back(0);
	ve.push_back(nums);
	s.calculateMinimumHP(ve);
	return 0;
}

