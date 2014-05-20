#include "tree_util.h"
#include <queue>

using namespace std;

TreeNode *build_tree(char nodes[], int n)
{
	TreeNode *root = new TreeNode(nodes[0] - '0'); 
	queue<TreeNode*> q;
	bool is_left = true;
	TreeNode *cur = NULL;
	q.push(root);

	for (int i = 1; i < n; i++) {
		TreeNode *node = NULL;
		if (nodes[i] != '#') {
			node = new TreeNode(nodes[i] - '0');
			q.push(node);
		}

		if (is_left) {
			cur = q.front();
			q.pop();
			cur->left = node;
			is_left = false;
		} else {
			cur->right = node;
			is_left = true;
		}
	}

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
