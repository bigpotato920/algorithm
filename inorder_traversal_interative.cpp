#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

void inorder_travsersal_iterative(TreeNode *root)
{
	stack<TreeNode*> nodes;
	TreeNode *current = root;

	while (!nodes.empty() || current) {
		if (current) {
			nodes.push(current);
			current = current->left;
		} else {
			current = nodes.top();
			nodes.pop();
			
			cout << current->val;
			current = current->right;
		}
	}
}