// leetcode-99-BST树恢复.cpp : 定义控制台应用程序的入口点。
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
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *pre = NULL;
public:
    void recoverTree(TreeNode* root) {
        DFS(root);
        
        if (first == NULL && second == NULL) return;

        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    
    void DFS(TreeNode *root) {
        if (root == NULL) return;
        
        DFS(root->left);
        
        if (pre != NULL) {
            if (root->val < pre->val) {
                if (first == NULL) {
                    first = pre;
                    second = root;
                } else {
                    second = root;
                }
            }
        }
        
        pre = root;
        
        DFS(root->right);
        
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

