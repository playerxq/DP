// test.cpp : 定义控制台应用程序的入口点。
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

unsigned int hex2int(char* s)
{
	int len = strlen(s);
	unsigned int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum *= 16;
		if (s[i] >= 'A')
			sum += s[i] - 'A'+10;
		else
			sum += s[i] - '0';
	}
	return sum;
}
int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int s = hex2int("1A");
	return 0;
}

