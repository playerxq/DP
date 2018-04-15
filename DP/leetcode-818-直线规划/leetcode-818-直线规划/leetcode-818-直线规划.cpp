// leetcode-818-直线规划.cpp : Defines the entry point for the console application.
//
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
	int racecar(int target) {
		if (!target)
			return 0;
		queue<pair<int, int>> Q;
		Q.push(make_pair(0,1));
		set<pair<int, int>> vis;
		vis.insert(make_pair(0, 1));
		int cnt = 0;
		while (!Q.empty())
		{
			queue<pair<int, int>> new_Q;
			cnt += 1;
			while (!Q.empty())
			{
				pair<int, int> cur = Q.front();
				Q.pop();
				int p1;
				int s1;
				p1 = cur.first + cur.second;
				s1 = cur.second * 2;
				if (p1 == target)
					return cnt;
				int p2;
				int s2;
				p2 = cur.first;
				s2 = (cur.second > 0) ? -1 : 1;
				if (!vis.count(make_pair(p1, s1)))
					new_Q.push(make_pair(p1, s1));
				if (!vis.count(make_pair(p2, s2)))
				{
					if(s2==1||s2==-1)
						vis.insert(make_pair(p2, s2));
					new_Q.push(make_pair(p2, s2));
				}
			}
			Q = new_Q;
		}
		return -1;
	}
};
int main()
{
	Solution s;
	s.racecar(6);
    return 0;
}

