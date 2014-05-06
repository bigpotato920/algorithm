#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int freq;
	char ch;
	TreeNode *left;
	TreeNode *right;

	TreeNode (char c = '', int f = -1)
	{
		ch = c;
		freq = f;
		left = NULL;
		right = NULL;
	}

	TreeNode (TreeNode *n1, TreeNode *n2)
	{
		ch = '';
		freq = left->freq + right->freq;
        left = n1;
        right = n2;
	}

    bool operator () (const TreeNode &l, const TreeNode &r)
    {
        return l.freq > r.freq;
    }
};

void hufuman_encode(string &str) {
    priority_queue<TreeNode, vector<TreeNode>, TreeNode> q;

    for (char ch = 'a'; ch <= 'z'; ch++) {
        int count = (int)count(str.begin(), str.end(), ch);
        if (count) {
            q.push(TreeNode(ch, count));
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        int count = (int)count(str.begin(), str.end(), ch);
        if (count) {
            q.push(TreeNode(ch, count));
        }
    }

    while (q.size() != 1) {
        TreeNode *left = new TreeNode(q.top());
        q.pop();
        TreeNode *right= new TreeNode(q.top());
        q.pop();
        q.push(TreeNode(left, right);

    }

     
}
