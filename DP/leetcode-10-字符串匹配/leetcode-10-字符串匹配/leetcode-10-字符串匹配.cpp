// leetcode-10-字符串匹配.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int lenA = s.length(), lenB = p.length();

        vector<vector<bool>> dp(lenA+1, vector<bool>(lenB+1, false));
        dp[0][0] = true;
        for(int i=1; i<=lenB; i++){
            if(p[i-1] == '*' && i > 1) dp[0][i] = dp[0][i-2];
        }
        
        for(int i=1; i<=lenA; i++){
            for(int j=1; j<=lenB; j++){
                if(p[j-1] == '*'){
                    if(dp[i][j-2] || (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]) dp[i][j] = true;
                }
                else if((p[j-1] == '.' || s[i-1] == p[j-1]) && dp[i-1][j-1]){
                    dp[i][j] = true;
                }
            }
        }
        return dp[lenA][lenB];
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

