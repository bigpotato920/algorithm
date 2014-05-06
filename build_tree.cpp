#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *helper(vector<int> &inorder, int in_begin, int in_end, vector<int> &postorder, int post_begin, int post_end)
{
	cout << in_begin << " " << in_end << " " << post_begin << " " << post_end << endl;
    if ( in_begin > in_end || post_begin > post_end)
        return NULL;

    int root_value = postorder[post_end];
    
    int pivot;
    for (pivot = in_begin; pivot <= in_end; pivot++) {
        if (inorder[pivot] == root_value) 
            break;
    }
    
    TreeNode *root = new TreeNode(root_value);
    int left_part_len = pivot - in_begin;
    int right_part_len = in_end - pivot;
    cout << pivot << endl;
    root->left = helper(inorder, in_begin, in_begin+left_part_len-1, postorder, post_begin, post_begin+left_part_len-1);

    root->right = helper(inorder, pivot+1, in_end, postorder, post_end-right_part_len ,post_end-1);
    
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    
    return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
}

int main(int argc, char const *argv[])
{
	int a[] = {1, 2};
	int b[] = {2, 1};
	vector<int> in(a, a+2);
	vector<int> out(b, b+2);

	TreeNode *root = buildTree(in, out);
	return 0;
}