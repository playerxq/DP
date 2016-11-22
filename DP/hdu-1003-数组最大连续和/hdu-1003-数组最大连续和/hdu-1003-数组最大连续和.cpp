// hdu-1003-数组最大连续和.cpp : 定义控制台应用程序的入口点。
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
const int INF = 0x3f3f3f3f;
int a[100000+1];
int n;
int _sum,_start,_end;
int sum[100000+1],startx[100000+1],endx[100000+1];
void solve()
{
	sum[1]=a[1];
	startx[1]=endx[1]=1;
	for(int i = 2;i<=n;i++)
	{
		if(sum[i-1]<0)
		{
			sum[i]=a[i];
			startx[i]=endx[i]=i;
		}
		else
		{
			sum[i]=sum[i-1]+a[i];
			startx[i]=startx[i-1];
			endx[i]=i;
		}
	}
	int _max=(-1)*INF;
	int index;
	for(int i = 1;i<=n;i++)
	{
		if(sum[i]>_max)
		{
			_max=sum[i];
			index = i;
		}
	}
	_sum = _max;
	_start = startx[index];
	_end = endx[index];
}
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		if(n==1)
			return nums[0];
		int* sum  = new int[n+1];
		memset(sum,0,sizeof(sum)*(n+1));
		sum[0]=nums[0];
		for(int i = 1;i<n;i++)
		{
			if(sum[i-1]<0)
			{
				sum[i]=nums[i];
			}
			else
			{
				sum[i]=sum[i-1]+nums[i];
			}
		}
		int _max=(-1)*INF;
		int index;
		for(int i = 0;i<n;i++)
		{
			if(sum[i]>_max)
			{
				_max=sum[i];
			}
		}
		return _max;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		if(kase>1)
			printf("\n");
		printf("Case %d:\n",kase);
		scanf("%d",&n);
		for(int i = 1;i<=n;i++)
			scanf("%d",&a[i]);
		solve();
		printf("%d %d %d\n",_sum,_start,_end);
	}
	Solution s;
	vector<int> v;
	v.push_back(1);
	s.maxSubArray(v);
}
