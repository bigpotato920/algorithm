#include "tree_util.h"
#include <stdio.h>

static void build_tree_helper(TreeNode *root, char nodes[], int i, int n)
{
	if (root == NULL)
		return;
	TreeNode *lchild = NULL;
	TreeNode *rchild = NULL;
	//printf("root = %d, i = %d\n", root->val, i);

	if ((2 * i + 1 < n) && nodes[2 * i + 1] != '#') {
		lchild = new TreeNode(nodes[2 * i + 1] - '0');
		build_tree_helper(lchild, nodes, 2 * i + 1, n);	
	}

	if ((2 * i + 2) < n && nodes[2 * i + 2] != '#') {
		rchild = new TreeNode(nodes[2 * i + 2] - '0');
		build_tree_helper(rchild, nodes, 2 * i + 2, n);
	}

	root->left = lchild;
	root->right = rchild;
}

TreeNode *build_tree(char nodes[], int n)
{
	TreeNode *root = new TreeNode(nodes[0] - '0');

	build_tree_helper(root, nodes, 0, n);

	return root;
}

void destroy_tree(TreeNode * root)
{
	if (root == NULL)
		return;
	destroy_tree(root->left);
	destroy_tree(root->right);

	delete root;
	
}