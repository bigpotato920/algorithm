#include <queue>
#include <iostream>
#include "tree_util.h"

using namespace std;

void level_order_print(TreeNode *root)
{
	queue<TreeNode*> current_level;
	queue<TreeNode*> next_level;

	current_level.push(root);

	while (!current_level.empty()) {
		TreeNode *node = current_level.front();
		current_level.pop();

		cout << node->val << " ";
		if (node->left)
			next_level.push(node->left);
		if (node->right)
			next_level.push(node->right);

		if (current_level.empty()) {
			cout << endl;
			swap(current_level, next_level);
		}
	}


}


int main(int argc, char const *argv[])
{
	char nodes[] = {'3', '9', '2', '#', '#', '1', '7'};

	TreeNode *root = build_tree(nodes, 7);

	level_order_print(root);
	return 0;
}
