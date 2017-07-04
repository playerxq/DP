// leetcode-630-øŒ≥Ã≈≈–Ú.cpp : Defines the entry point for the console application.
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
	int scheduleCourse(vector<vector<int>>& courses) {
		sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b) {return a.back() < b.back(); });
		multiset<int> cls;
		int cursum = 0;
		for (int i = 0; i < courses.size(); i++)
		{
			if (cursum + courses[i].front() <= courses[i].back())
			{
				cls.insert(courses[i].front());
				cursum += courses[i].front();
			}
			else if (*cls.rbegin() > courses[i].front())
			{
				cursum += courses[i].front() - *cls.rbegin();
				cls.erase(--cls.end());
				cls.insert(courses[i].front());
			}
		}
		return cls.size();
	}
};
int main()
{
    return 0;
}

