// leetcode-85-01矩阵中的最大1矩阵.cpp : 定义控制台应用程序的入口点。
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        
		int m = matrix.size();
		if(!m)
			return 0;
		int n = matrix[0].size();
		int maxx = 0;
		int* h = new int[n+1];
		int* l = new int[n+1];
		int* r = new int[n+1];
		for(int i = 0;i<n;i++)
		{
			h[i] = 0;
			l[i] = 0;
			r[i] = n;
		}
		for(int i = 0;i<m;i++)
		{
			int c_l = 0;
			int c_r = n;
			for(int j = 0;j<n;j++)
			{
				if(matrix[i][j]=='1')
				{
					h[j]++;
				}
				else
					h[j] = 0;
			}
			for(int j = 0;j<n;j++)
			{
				if(matrix[i][j]=='1')
				{
					l[j] = max(c_l,l[j]);
				}
				else
				{
					l[j] = 0;
					c_l = j+1;
				}
			}
			for(int j = n-1;j>=0;j--)
			{
				if(matrix[i][j]=='1')
				{
					r[j] = min(c_r,r[j]);
				}
				else
				{
					r[j] = n;
					c_r = j;
				}
			}
			for(int j = 0;j<n;j++)
			{
				int m = (r[j]-l[j])*h[j];
				if(m>maxx)
					maxx = m;
			}
		}
		return maxx;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	vector<vector<char>> matrix;
	vector<char> tmp;
	tmp.push_back('1');
	tmp.push_back('0');
	tmp.push_back('1');
	tmp.push_back('1');
	tmp.push_back('1');
	matrix.push_back(tmp);
	tmp.clear();
	tmp.push_back('0');
	tmp.push_back('1');
	tmp.push_back('0');
	tmp.push_back('1');
	tmp.push_back('0');
	matrix.push_back(tmp);
	tmp.clear();
	tmp.push_back('1');
	tmp.push_back('1');
	tmp.push_back('0');
	tmp.push_back('1');
	tmp.push_back('1');
	matrix.push_back(tmp);
	tmp.clear();
	tmp.push_back('1');
	tmp.push_back('1');
	tmp.push_back('0');
	tmp.push_back('1');
	tmp.push_back('1');
	matrix.push_back(tmp);
	tmp.clear();
	tmp.push_back('0');
	tmp.push_back('1');
	tmp.push_back('1');
	tmp.push_back('1');
	tmp.push_back('1');
	matrix.push_back(tmp);
	tmp.clear();
	s.maximalRectangle(matrix);
}

