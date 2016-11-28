// leetcode-95-BST树求解.cpp : 定义控制台应用程序的入口点。
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<TreeNode*>* gen_tree(int st, int ed)
	{
		vector<TreeNode*>* res = new vector<TreeNode*>;
		if(st>ed)
		{
			res->push_back(NULL);
			return res;
		}
		if(st==ed)
		{
			TreeNode *root = new TreeNode(st);
			(*res).push_back(root);
			return res;
		}
		for(int i = st;i<=ed;i++)
		{
			vector<TreeNode*>* le = gen_tree(st,i-1);
			vector<TreeNode*>* ri = gen_tree(i+1,ed);
			for (auto lit = le->begin(); lit != le->end(); ++lit) {
                for (auto rit = ri->begin(); rit != ri->end(); ++rit) {
                    TreeNode *root = new TreeNode(i);
                    root->left = *lit;
                    root->right = *rit;
                    res->push_back(root);
                }
            }
		}
		return res;
	}
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
		for(int i = 1;i<=n;i++)
		{
			vector<TreeNode*>* le = gen_tree(1,i-1);
			vector<TreeNode*>* ri = gen_tree(i+1,n);
			for (auto lit = le->begin(); lit != le->end(); ++lit) {
                for (auto rit = ri->begin(); rit != ri->end(); ++rit) {
                    TreeNode *root = new TreeNode(i);
                    root->left = *lit;
                    root->right = *rit;
                    res.push_back(root);
                }
            }
		}
		return res;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	s.generateTrees(3);
}

