#include <iostream>
#include <queue>
#include <map>
using namespace std;

const int MAX_LEN = 5;

int maze[5][5] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
};


struct Node
{
	int x;
	int y;

	Node (int x, int y)
	{
		this->x = x;
		this->y = y;
	
	}

	Node ()
	{
		this->x = -1;
		this->y = -1;

	}

	Node (const Node &node)
	{
		x = node.x;
		y = node.y;
	}

	Node& operator = (const Node &node)
	{
		this->x = node.x;
		this->y = node.y;

		return *this;
	}

	bool friend operator == (const Node &n1, const Node &n2)
	{
		return n1.x == n2.x && n1.y == n2.y;
	}

	bool friend operator != (const Node &n1, const Node &n2)
	{
		return !(n1 == n2);
	}

	bool friend operator < (const Node &n1, const Node &n2)
	{
		if (n1.x < n2.x)
			return true;
		else if (n1.x == n2.x) {
			if (n1.y < n2.y)
				return true;
		}

		return false;
	}
};


bool is_valid (const Node &node)
{
	bool result = false;
	if  (node.x >= 0 && node.x < MAX_LEN &&
		node.y >= 0 && node.y < MAX_LEN && maze[node.x][node.y] != 1)
		result =  true;

	return result;
}

bool BFS(map<Node, Node> &parent, Node &src_node, Node &dst_node)
{
	queue<Node> q;

	Node cur_node;
	Node next_node;
	bool visited[MAX_LEN][MAX_LEN];
	int dir[][2] = {
		{0, 1}, {1, 0},
		{-1, 0}, {0, -1}
	};

	q.push(src_node);
	visited[src_node.x][src_node.y] = true;

	for (int i = 0; i < MAX_LEN; i++) {
		for (int j = 0; j < MAX_LEN; j++)
			visited[i][j] = false;
	}

	while (!q.empty()) {
		cur_node = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {

			next_node = Node(cur_node.x + dir[i][0], cur_node.y + dir[i][1]);

			if (is_valid(next_node)) {
				parent[next_node] = cur_node;
				
				if (next_node == dst_node)
					return true;

				if (!visited[next_node.x][next_node.y]) {
					q.push(next_node);
					visited[next_node.x][next_node.y] = true;
				}
			} 

		}
	}


	return false;
}

void print_path(map<Node, Node> &parent, const Node &src_node, const Node &dst_node)
{
	if (src_node == dst_node) {
		cout << "node x = " << src_node.x << " y = " << src_node.y << endl;
		return;
	}
	print_path(parent, src_node, parent[dst_node]);
	cout << "node x = " << dst_node.x << " y = " << dst_node.y << endl;
}	
int main(int argc, char const *argv[])
{


	Node src_node(0, 0);
	Node dst_node(4, 4);
	map<Node, Node> parent;
	BFS(parent, src_node, dst_node);

	print_path(parent, src_node, dst_node);

	return 0;
}