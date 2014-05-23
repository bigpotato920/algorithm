#include <vector>
#include <iostream>

using namespace std;

void helper(int start, vector<int> &candidates, int target, vector<int> &items, vector<vector<int> > &result)
{
	if (target < 0)
		return;
	if (target == 0) {
		result.push_back(items);
		return;
	}

	for (int i = start; i < candidates.size(); i++) {
		if (i > 0 && candidates[i] == candidates[i-1])
			continue;

		items.push_back(candidates[i]);

		helper(i, candidates, target-candidates[i], items, result);
		items.pop_back();
	}
}

vector< vector<int> > comination_sum(vector<int> &candidates, int target)
{
	vector<vector<int> > result;
	if (candidates.size() == 0)
		return result;
	vector<int> items;
	helper(0, candidates, target, items, result);

	return result;
}

int main(int argc, char const *argv[])
{

	vector<vector<int> > result;
	int can[] = {2, 3, 4, 7};
	vector<int> candidates(can, can+3);
	result = comination_sum(candidates, 7);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j <result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}