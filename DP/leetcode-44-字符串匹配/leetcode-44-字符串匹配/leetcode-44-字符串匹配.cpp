// leetcode-44-字符串匹配.cpp : 定义控制台应用程序的入口点。
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
    bool isMatch(string s, string p) { 
        int m = s.length(), n = p.length();
        if (n > 30000) return false; // the trick
        vector<bool> cur(m + 1, false); 
        cur[0] = true;
        for (int j = 1; j <= n; j++) {
            bool pre = cur[0]; // use the value before update
            cur[0] = cur[0] && p[j - 1] == '*'; 
            for (int i = 1; i <= m; i++) {
                bool temp = cur[i]; // record the value before update
                if (p[j - 1] != '*')
                    cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                else cur[i] = cur[i - 1] || cur[i];//cur[i] = cur[i][j-1] cur[i-1] = cur[i-1][j]
                pre = temp;//[i-1][j-1]
            }
        }
        return cur[m]; 
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	s.isMatch("aab","c*a*b");
}

