// leetcode-240-矩阵搜索.cpp : 定义控制台应用程序的入口点。
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

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& m, int target) {
		if (m.size() == 0||m[0].size()==0)
			return false;
		if (target < m[0][0] || target > m[m.size() - 1][m[0].size() - 1])
			return false;
		int row1 = 0;
		int col1 = m[0].size() - 1;
		int row2 = m.size() - 1;
		int col2 = 0;
		while (row1 < m.size() && col2<m[0].size())
		{
			if (target > m[row1][col1] && target>m[row2][col2])
			{
				col2++;
				row1++;
			}
			else if (target == m[row1][col1] || target == m[row2][col2])
				return true;
			else
			{
				while (col1>=0&&target < m[row1][col1])
				{
					col1--;
					if (col1 < 0)
						return false;
				}
				while (row2 >= 0 && target < m[row2][col2])
				{
					row2--;
					if (row2 < 0)
						return false;
				}
			}
		}
		return false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

