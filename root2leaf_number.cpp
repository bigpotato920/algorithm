#include <iostream>
#include <math.h>

using namespace std;
int total_sum = 0;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x): val(x), left(NULL), right(NULL) {}
};

int decimal_length(int n) {
    int len = 0;
    
    if (n == 0)
        return 1;

    while (n > 0) {
        n = n / 10;
        len++;
    }

    return len;
}

int postorder(TreeNode *root, int last_sum) {
    int cur_sum = last_sum * 10 + root->val; 
    if (root->left) {
        postorder(root->left, cur_sum);
    }

    if (root->right) {
        postorder(root->right, cur_sum);
    }

    if (root->left == NULL && root->right == NULL)
        total_sum += cur_sum;
}

int sumNumbers(TreeNode *root) {
    if (root == NULL)
        return 0;
    postorder(root, 0);
    return total_sum;
}

int main(int argc, const char *argv[])
{

    TreeNode n1(8);
    TreeNode n2(3);
    TreeNode n3(5);
    TreeNode n4(9);
    TreeNode n5(9);
    TreeNode n6(5);
    
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;
    n4.left = &n5;
    n4.right = &n6;

    cout << sumNumbers(&n1) << endl;
    return 0;
}
