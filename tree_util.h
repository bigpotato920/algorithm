#ifndef TREE_UTIL_H
#define TREE_UTIL_H

#ifndef NULL
#define NULL 0
#endif

struct TreeNode
{
	TreeNode *left;
	TreeNode *right;
	int val;

	TreeNode(int x): left(NULL), right(NULL), val(x) {}
};


TreeNode *build_tree(char nodes[], int n);
void destroy_tree(TreeNode * root);
#endif