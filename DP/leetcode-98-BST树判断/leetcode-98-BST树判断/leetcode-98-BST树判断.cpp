// leetcode-98-BST树判断.cpp : 定义控制台应用程序的入口点。
//
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isBST(TreeNode* root, long minx, long maxx)
	{
		if(root==NULL)
			return true;
		return (root->val<maxx)&&(root->val>minx)&&isBST(root->left,minx,root->val)&&isBST(root->right,root->val,maxx);
	}
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
			return true;
		return isBST(root->left,(long) INT_MIN-1,root->val)&&isBST(root->right,root->val,(long) INT_MAX+1);
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

