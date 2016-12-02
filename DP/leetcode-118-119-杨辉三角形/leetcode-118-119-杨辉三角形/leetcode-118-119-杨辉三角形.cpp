// leetcode-118-119-杨辉三角形.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0)
            return res;
        vector<int> temp;
        temp.push_back(1);
        res.push_back(temp);
        for(int i = 2;i<=numRows;i++)
        {
            vector<int> temp1;
            temp1.push_back(temp[0]);
            for(int k = 1;k<temp.size();k++)
            {
                temp1.push_back(temp[k-1]+temp[k]);
            }
            temp1.push_back(1);
            res.push_back(temp1);
            temp.clear();
            for(int k = 0;k<temp1.size();k++)
                temp.push_back(temp1[k]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1);
        res[0] = 1;
        for(int r = 0;r<=rowIndex;r++)
        {
            for(int c = r;c>0;c--)
            {
                res[c] = res[c-1]+res[c];
            }
        }
        return res;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

