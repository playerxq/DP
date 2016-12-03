// leetcode-128-最长递增子序列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//找到一组数字中能组成的最长的连续序列
//如[100, 4, 200, 1, 3, 2] 不一定有顺序
//最长为4  1 2 3 4
class Solution {
public:
    int longestConsecutive(const vector<int> &num) {
    unordered_set<int> s(num.begin(), num.end()), searched;
    int longest = 0;
    for (int i: num) {
        if (searched.find(i) != searched.end()) continue;
        searched.insert(i);
        int j = i - 1, k = i + 1;
        while (s.find(j) != s.end()) searched.insert(j--);
        while (s.find(k) != s.end()) searched.insert(k++);
        longest = max(longest, k - 1 - j);
    }
    return longest;
}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

