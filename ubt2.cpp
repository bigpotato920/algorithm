#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode *> generate(int left, int right)
{
    vector<TreeNode*> result;
    if (left > right) {
        result.push_back(NULL);
        return result;
    }
    
    for (int i = left; i <= right; i++) {
        vector<TreeNode*> lt = generate(begin, i-1);
        vector<TreeNode*> rt = generate(i+1, end);
        
        for (int j = 0; j < lt.size(); j++) {
            for (int k = 0; k < rt.size(); k++) {
                TreeNode *node = new TreeNode(i);
                node->left = lt[j];
                node->right = rt[k];
                
                result.push_back(node);
            }
        }
    }
    
    return result;

}

vector<TreeNode *> generateTrees(int n) {
    return generate(1, n);
}

int main(int argc, char const *argv[])
{
    vector<TreeNode*> result = generateTrees(5);
    return 0;
}