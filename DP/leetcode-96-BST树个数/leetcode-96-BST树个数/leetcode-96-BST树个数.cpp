// leetcode-96-BST树个数.cpp : 定义控制台应用程序的入口点。
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
    int numTrees(int n) {
        long long* h = new long long[n+1];
		h[0] = h[1] = 1;
		for(int i = 2;i<=n;i++)
		{
			h[i] = h[i-1]*(4*i-2)/(i+1);
		}
		return (int)h[n];
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

