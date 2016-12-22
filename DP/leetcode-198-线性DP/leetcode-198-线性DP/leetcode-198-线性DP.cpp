// leetcode-198-线性DP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class Solution {
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

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

