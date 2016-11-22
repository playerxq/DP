//牛顿插值 f(x0,x1,...,xi)为i阶插值系数 = newton[i][0]/(xi-x0)
//f(x0,x1,...,xi)=(f(x1,...,xi)-f(x0,...,xk-1))/(xk-x0)
//xk-x0=k
//newton[i][j]=f(xj,xj+1,...,xj+i)分子部分
//newton[i][j]=newton[i-1][j+1]-newton[i-1][j]
//当用newton[i][j]计算f(xj,...,xj+i)时分母一直累乘为i!
//DP求newton
//本题中x0,x1...xs-1就是1，2，。。。，s
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
const int MAXSIZE = 500;
struct bign
{
	int s[MAXSIZE];
	int len;
	bign()
	{
		memset(s,0,sizeof(s));
		len = 1;
	}
	bign operator = (const char* num)//高位在后  低位在前
	{
		memset(s,0,sizeof(s));
		len = strlen(num);
		for(int i = 0;i<len;i++)
			s[len-i-1] = num[i]-'0';
		return *this;
	}
	bign operator = (const int num)
	{
		memset(s,0,sizeof(s));
		char number[200];
		sprintf(number,"%d",num);
		*this = number;
		this->len = strlen(number);
		return *this;
	}
	bign(const int n)
	{
		*this = n;
	}
	bign(char* n)
	{
		*this = n;
	}
	bign operator + (const bign &c){    
        bign sum;  
        int t = 0;  
        sum.len = max(this->len, c.len);  
        for (int i = 0; i < sum.len; i++) {  
            if (i < this->len) t += this->s[i];  
            if (i < c.len) t += c.s[i];  
            sum.s[i] = t % 10;  
            t /= 10;  
        }  
        while (t) {  
            sum.s[sum.len++] = t % 10;  
            t /= 10;  
        }  
        while(ans.s[ans.len-1]==0)
			ans.len--;
		if (ans.len == 0) ans.len = 1;  
        return sum;    
    }
	bign operator - (const bign& c)
	{
		bign ans;
		ans.len = max(this->len, c.len);  
        int i;  
		for(i = 0;i<c.len;i++)
		{
			if(this->s[i]<c.s[i])
			{
				this->s[i]+=10;
				this->s[i+1]--;
			}
			ans.s[i] = this->s[i]-c.s[i];
		}
		for (; i < this->len; i++) {  
            if (this->s[i] < 0) {  
                this->s[i] += 10;  
                this->s[i + 1]--;  
            }  
            ans.s[i] = this->s[i];  
        } 
		while(ans.s[ans.len-1]==0)
			ans.len--;
		if (ans.len == 0) ans.len = 1;  
		return ans;
	}
	bign operator * (int k)
	{
		bign ans;
		int c = 0;
		ans.len = this->len;
		for(int i = 0;i<this->len;i++)
		{
			ans.s[i] += this->s[i]*k;
			while(ans.s[i]>=10)
			{
				ans.s[i]-=10;
				ans.s[i+1]++;
			}
		}
		c = ans.s[ans.len];
		while(c)
		{
			ans.s[ans.len] = c%10;
			c/=10;
			ans.len++;
		}
		while(ans.len>1&&ans.s[ans.len-1]==0)
			ans.len--;
		return ans;
	}
	bign operator * (const bign& c)
	{
		bign ans;
		ans.len = this->len+c.len;
		for(int i = 0;i<this->len;i++)
		{
			for(int j = 0;j<c.len;j++)
			{
				ans.s[i+j] += this->s[i]*c.s[j];
			}
		}
		for(int i = 0;i<ans.len;i++)
		{
			while(ans.s[i]>=10)
			{
				ans.s[i]-=10;
				ans.s[i+1]++;
			}
		}
		while(ans.len>1&&ans.s[ans.len-1]==0)
			ans.len--;
		return ans;
	}
	bign operator / (const int num)
	{
		bign ans;
		ans.len = this->len;
		int k = 0;
		for(int i = this->len-1;i>=0;i--)
		{
			k = k*10+this->s[i];
			ans.s[i] = k/num;
			k = k%num;
		}
		while(ans.len>1&&ans.s[ans.len-1]==0)
			ans.len--;
		return ans;
	}
	bign operator / (const bign& c)
	{
		bign ans;
		ans = 0;
		ans.len = 1;
		while(*this>=c)
		{
			ans=ans+1;
			*this = *this-c;
		}
		if(*this!=0)
			ans = ans+1;
		return ans;
	}
	void put() {  
        if (len == 1 && s[0] == 0) {  
            printf("0");  
        } else {  
            for (int i = len - 1; i >= 0; i--)  
                printf("%d", s[i]);  
        }  
		//printf("\n");
    }  
	bool operator < (const bign& b) const {  
        if (len != b.len)  
            return len < b.len;  
   
        for (int i = len - 1; i >= 0; i--)  
            if (s[i] != b.s[i])  
                return s[i] < b.s[i];  
        return false;  
    }  
    bool operator > (const bign& b) const { return b < *this; }  
    bool operator <= (const bign& b) const { return !(b < *this); }  
    bool operator >= (const bign& b) const { return !(*this < b); }  
    bool operator != (const bign& b) const { return b < *this || *this < b;}  
    bool operator == (const bign& b) const { return !(b != *this); }  
};
int newton[110][110];
int s,c;
int val[110];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&s,&c);
		for(int i = 0;i<s;i++)
			scanf("%d",&val[i]);
		for(int i = 0;i<s;i++)
			newton[0][i]=val[i];//0阶插值系数
		int deg;
		for(deg = 1;deg<s;deg++)
		{
			bool allzero = true;
			for(int i = 0;i<s-deg;i++)
			{
				newton[deg][i]=newton[deg-1][i+1]-newton[deg-1][i];
				if(newton[deg][i]!=0)
					allzero = false;
			}
			if(allzero)
				break;//得到最高次deg-1
		}
		for(int k = 1;k<=c;k++)
		{
			int n = s+k;
			bign ans = 0;
			ans = newton[0][0];
			bign f = 1;
			bign tmp = 1;
			for(int i = 1;i<deg;i++)
			{
				f = f*i;
				tmp = tmp*(n-i);
				bign t = tmp*newton[i][0];
				t = t/f;
				ans = ans + t;
			}
			if(k==c)
			{
				ans.put();
				printf("\n");
			}
			else
			{
				ans.put();
				printf(" ");
			}
		}
	}
}