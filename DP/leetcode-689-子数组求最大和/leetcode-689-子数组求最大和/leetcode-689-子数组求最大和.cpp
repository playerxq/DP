// leetcode-689-������������.cpp : Defines the entry point for the console application.
//dp[i][j] ����jǰȡi+1�����ص��������鹹������

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
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		vector<vector<int>> dp(3, vector<int>(nums.size(), 0));
		vector<int> ksum(nums.size(), 0);
		int sum = 0;
		for (int i = 0; i < k; i++) {
			sum += nums[i];
		}
		dp[0][k - 1] = sum;
		ksum[k - 1] = sum;
		for (int i = k; i < nums.size(); i++) {
			sum += nums[i];
			sum -= nums[i - k];
			dp[0][i] = max(sum, dp[0][i - 1]);//nums[i]�Ƿ�ѡȡ
			ksum[i] = sum;
		}
		dp[1][k * 2 - 1] = ksum[k * 2 - 1] + ksum[k - 1];//ѡȡ2�� 0:k-1 k:2k-1
		for (int i = k * 2; i < nums.size(); i++) {
			dp[1][i] = max(dp[1][i - 1], ksum[i] + dp[0][i - k]);//nums[i]�Ƿ�ѡ��
		}
		dp[2][k * 3 - 1] = ksum[k * 3 - 1] + ksum[k * 2 - 1] + ksum[k - 1];//ѡȡ3�� 0:k-1 k:2k-1 2k:3k-1
		for (int i = k * 3; i < nums.size(); i++) {
			dp[2][i] = max(dp[2][i - 1], ksum[i] + dp[1][i - k]);//nums[i]�Ƿ�ѡ��
		}
		vector<int> ans(3, 0);
		for (int i = nums.size() - 1; i > 0; i--)
		{
			if (dp[2][i - 1] != dp[2][i])//dp[2][i] = max(dp[2][i-1],ksum[i]+dp[1][i-k]) ��dp[2][i-1]!=dp[2][i] ��dp[2][i]��Ҫѡ��nums[i]Ϊ���һ��������Ԫ��
			{
				ans[2] = i-k+1;
				break;
			}
		}
		for (int i = ans[2] - 1; i > 0; i--)
		{
			if (dp[1][i - 1] != dp[1][i])
			{
				ans[1] = i-k+1;
				break;
			}
		}
		for (int i = ans[1] - 1; i > 0; i--)
		{
			if (dp[0][i - 1] != dp[0][i])
			{
				ans[0] = i-k+1;
				break;
			}
		}
		return ans;
	}
};
int main()
{
    return 0;
}

