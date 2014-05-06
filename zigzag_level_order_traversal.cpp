#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printLevelOrderZigZag(TreeNode *root) {
  stack<TreeNode*> currentLevel, nextLevel;
  bool leftToRight = true;
  currentLevel.push(root);
  while (!currentLevel.empty()) {
    TreeNode *currNode = currentLevel.top();
    currentLevel.pop();
    if (currNode) {
      cout << currNode->val << " ";
      if (leftToRight) {
        nextLevel.push(currNode->left);
        nextLevel.push(currNode->right);
      } else {
        nextLevel.push(currNode->right);
        nextLevel.push(currNode->left);
      }
    }
    if (currentLevel.empty()) {
      cout << endl;
      leftToRight = !leftToRight;
      swap(currentLevel, nextLevel);
    }
  }
}


vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > result;
    if (!root)
        return result;
    stack<TreeNode*> cur_level;
    stack<TreeNode*> next_level;
    bool left_to_right = true;
    vector<int> level;
    cur_level.push(root);
    
    while (!cur_level.empty()) {
        TreeNode *node = cur_level.top();
        cur_level.pop();
        
        if (node) {
            cout << node->val << " ";
        
        
            if (left_to_right) {
                next_level.push(node->left);
                next_level.push(node->right);
            } else {
                next_level.push(node->right);
                next_level.push(node->left);
            }

            if (cur_level.empty()) {
                cout << endl;
                left_to_right = !left_to_right;
                swap(cur_level, next_level);
            }
        } else 
        	cout << "NULL" << endl;


    }
    
    return result;
}
int main(int argc, char const *argv[])
{
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);

	n1->right = n2;

	//printLevelOrderZigZag(n1);
	zigzagLevelOrder(n1);
	delete n1;
	delete n2;

	return 0;
}