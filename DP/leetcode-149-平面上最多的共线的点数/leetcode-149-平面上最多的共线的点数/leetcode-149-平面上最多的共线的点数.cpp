// leetcode-149-平面上最多的共线的点数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
	bool ok(Point a,Point b,Point c)
	{
		int ax=a.x-b.x,bx=a.y-b.y;
		int cx=b.x-c.x,dx=b.y-c.y;
		return ax*dx==bx*cx;
	}
    int maxPoints(vector<Point>& points) {
		int n = points.size();
		if(n<=2)
			return n;
		int res = 0;
		unordered_map<double, int> m_map;
		for(int i = 0;i<n;i++)
		{
			int dup = 1;
			int ver = 0;
			m_map.clear();
			int tmp = 0;
			for(int j = i+1;j<n;j++)
			{
				if(points[i].x==points[j].x)
				{
					if(points[i].y==points[j].y)
					{
						dup++;
					}
					else
					{
						ver++;
					}
				}
				else
				{
					double tt = (double)(points[j].y-points[i].y)/(points[j].x-points[i].x);
					m_map[tt]++;
					tmp = max(m_map[tt],tmp);
				}
			}
			res = max(res,dup+max(ver,tmp));
		}
		return res;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
