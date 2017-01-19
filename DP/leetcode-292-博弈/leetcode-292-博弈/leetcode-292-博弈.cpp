// leetcode-292-博弈.cpp : 定义控制台应用程序的入口点。
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
	bool canWinNim(int n) {
		if (n == 0)
			return true;
		if (n <= 3)
			return true;
		if (n == 4)
			return false;
		int k = n / 4;
		int r = n % 4;
		if (r == 0)
			return false;
		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

