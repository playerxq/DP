// leetcode-198-����DP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
class Solution {
public:
	int rob(vector<int> num) {
        int i = 0;//ѡ�����
        int e = 0;//��ѡ�����
        for (int k = 0; k<num.size(); k++) {
            int tmp = i;
            i = num[k] + e;//ѡ��k k-1��ѡ
            e = max(tmp, e);//��ѡ��k  k-1����ѡҲ���Բ�ѡ
        }
        return max(i,e);
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

