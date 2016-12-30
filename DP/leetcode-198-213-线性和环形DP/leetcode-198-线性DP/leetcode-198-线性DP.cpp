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
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<int> ve;
	ve.push_back(1);
	s.rob(ve);
	return 0;
}

