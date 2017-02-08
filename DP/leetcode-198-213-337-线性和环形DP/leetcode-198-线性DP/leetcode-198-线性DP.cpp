// leetcode-198-线性DP.cpp : 定义控制台应用程序的入口点。
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
class Solution1 {
public:
	int rob(vector<int> num) {
        int i = 0;//选择这个
        int e = 0;//不选择这个
        for (int k = 0; k<num.size(); k++) {
            int tmp = i;
            i = num[k] + e;//选择k k-1不选
            e = max(tmp, e);//不选择k  k-1可以选也可以不选
        }
        return max(i,e);
    }
};
//环形
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int i[2];
		int e[2];
        i[0] = 0;
		e[1] = 0;
		i[1] = nums[0];
		e[0] = 0;
		for(int k = 1;k<nums.size();k++)
		{
			if(k<nums.size()-1)
			{
				int tmp_0 = i[0];
				int tmp_1 = i[1];
				i[0] = e[0]+nums[k];
				i[1] = e[1]+nums[k];
				e[0] = max(tmp_0,e[0]);
				e[1] = max(tmp_1,e[1]);
			}
			else
			{
				int tmp_0 = i[0];
				int tmp_1 = i[1];
				i[0] = e[0]+nums[k];
				e[0] = max(tmp_0,e[0]);
				e[1] = max(tmp_1,e[1]);
			}
		}
		if(nums.size()!=1)
			return max(i[0],max(e[0],e[1]));
		else
			return max(i[0],max(i[1],max(e[0],e[1])));
    }
};
//树形DP
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution3 {
public:
	int dfs(TreeNode* root, int& v1, int& v2)//v1 include v2 not include
	{
		if (root == NULL)
		{
			v1 = v2 = 0;
			return 0;
		}
		int v1_l = 0;
		int v2_l = 0;
		int v1_r = 0;
		int v2_r = 0;
		int a = dfs(root->left,v1_l,v2_l);
		int b = dfs(root->right,v1_r,v2_r);
		v1 = v2_l + v2_r+root->val;
		v2 = max(v2_l+v2_r,max(v1_l+v1_r,max(v1_l+v2_r,v1_r+v2_l)));
		return 0;
	}
	int rob(TreeNode* root) {
		int a = 0;
		int b = 0;
		dfs(root,a,b);
		return max(a,b);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<int> ve;
	ve.push_back(1);
	s.rob(ve);
	return 0;
}

