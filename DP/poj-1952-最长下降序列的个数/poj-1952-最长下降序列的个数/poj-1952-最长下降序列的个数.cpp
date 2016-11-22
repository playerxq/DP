// poj-1952-��½����еĸ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = (5000 + 50);
int n, num[MAXN]; 
int dp[MAXN], Count[MAXN];

int main()
{
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			cin >> num[i];
			dp[i] = Count[i] = 1;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (num[i] < num[j] && dp[i] < dp[j] + 1) {//ԭ��i��β�����г���С�ڽ�i��Ϊj���Ԫ���γ����еĳ��ȣ���iӦ��Ϊj��β�����е�������Ԫ�� ��i��β�����и�������j��β���и���
					dp[i] = dp[j] + 1;
					Count[i] = Count[j];
				} else if (num[i] < num[j] && dp[i] == dp[j] + 1) {//���ʱ ԭ��i��β�����и���Ӧ���Ͻ�i��ӵ�j���γɵ����и���
					Count[i] += Count[j];
				}
			}
			//Ϊ�˱����ظ���������
			for (int j = 1; j < i; j++) {
				if (num[j] == num[i]) Count[j] = 0;//ǰ������ͬ��β��Ԫ�� ��0
			}
		}
		int ans1 = 0, ans2 = 0;
		for (int i = 1; i <= n; i++) {
			ans1 = max(ans1, dp[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (dp[i] == ans1) ans2 += Count[i];
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}

