// leetcode-87-旋转树重构字符串.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {
		if(s1==s2)
            return true;
            
        int l1 = s1.length();
        int count[26] = {0};
        for(int i=0; i<l1; i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        
        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)
                return false;
        }
		for(int i = 1;i<=l1-1;i++)
		{
			if(isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i)))
				return true;
			if(isScramble(s1.substr(0,i),s2.substr(l1-i))&&isScramble(s1.substr(i),s2.substr(0,l1-i)))
				return true;
		}
		return false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

