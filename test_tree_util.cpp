#include <stdio.h>
#include "tree_util.h"

void preorder_traversal(TreeNode *root)
{
	if (root == NULL)
		return;
	printf("%d\n", root->val);
	preorder_traversal(root->left);
	preorder_traversal(root->right);

}
int main(int argc, char const *argv[])
{
	char nodes[] = {'1', '2', '3', '4', '5', '#', '7'};

	TreeNode *root = build_tree(nodes, 7);

	preorder_traversal(root);

	destroy_tree(root);
	return 0;
}