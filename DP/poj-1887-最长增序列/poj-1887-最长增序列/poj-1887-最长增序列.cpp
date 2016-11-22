// poj-1887-最长增序列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int MAXN = (100000 + 10);
const int inf = 0x3f3f3f3f;
int n;
int num[MAXN], B[MAXN];

int Binary_Search(int low, int high, int num)
{
	while (low <= high) {
		int mid = (low + high) / 2;
		if(B[mid]==num)
			return mid;
		if (B[mid] > num) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return low;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int x, t = 1;
	while (~scanf("%d", &x) && x != -1) {
		num[n = 0] = x;
		while (scanf("%d", &x) && x != -1) {
			num[++n] = x;
		}
		memset(B, 0, sizeof(B));
		B[0]=num[0];
		int len = 1;
		for (int i = 1; i <= n; i++) {
			if(B[len-1]>num[i])
			{
				B[len++]=num[i];
			}
			else
			{
				int pos = Binary_Search(0, len-1, num[i]);
				B[pos] = num[i];
			}
		}
		printf("Test #%d:\n", t++);
		printf("  maximum possible interceptions: %d\n\n", len);
	}
	return 0;
}

