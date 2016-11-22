// poj-2817-״̬ѹ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1 << 11][11];//dp[s][i]����ǰ��״̬s ��i����β
int num[11][11];
int n, ans;
char str[11][11];

void Init()
{
	memset(num, 0, sizeof(num));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int len1 = strlen(str[i]), len2 = strlen(str[j]);
			int MAX = 0, cnt = 0;
			for (int k = 0; k < len1; k++) {//kΪ��ʼƫ��  ���ӵ�һ�����ĵ�k��λ�ÿ�ʼ�ȶ�
				cnt = 0;
				for (int l = 0; l < len2 && k + l < len1; l++) {//
					if (str[i][k + l] == str[j][l]) cnt++;
				}
				MAX = max(MAX, cnt);//��¼����ƥ����Ŀ
			}
			for (int k = 0; k < len2; k++) {
				cnt = 0;
				for (int l = 0; l < len1 && k + l < len2; l++) {
					if (str[i][l] == str[j][k + l]) cnt++;
				}
				MAX = max(MAX, cnt);
			}
			num[i][j] = num[j][i] = MAX;
		}
	}
}

void getDP()
{
	memset(dp, 0, sizeof(dp));
	for (int s = 0; s < (1 << n); s++) {//״̬s
		for (int i = 0; i < n; i++) {//�ҵ�s�е�ĳ����i
			if (s & (1 << i)) {
				for (int j = 0; j < n; j++) {
					if (! ( s & (1 << j))) {//��j��s��δʹ��  ���Էŵ�i����
						dp[s | (1 << j)][j] = max(dp[s | (1 << j)][j], dp[s][i] + num[i][j]);
					}
				}
			}
		}
	}
	ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[(1 << n) - 1][i]);//n��ȫ�������ö�����һ����
	}
}

int main()
{
	while (cin >> n && n > 0) {
		for (int i = 0; i < n; i++) {
			cin >> str[i];
		}
		Init();
		getDP();
		cout << ans << endl;
	}
	return 0;
}

