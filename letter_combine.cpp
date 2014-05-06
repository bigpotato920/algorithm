#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
map<int, string> dict;

void dfs(string &digits, int start, string &output, vector<string> &result)
{
	cout << "start = " << start << endl;
	if (start == digits.size()) {
		result.push_back(output);
		return;
	}


	int v = digits[start] - '0';
	if (v != 1) {
		for (int j = 0; j < dict[v].size(); j++) {
			
			output.push_back(dict[v][j]);
			dfs(digits, start+1, output, result);
			output.erase(output.size()-1);
		}
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> result;
	string tmp = "";

	dict[2] = "abc";
	dict[3] = "def";
	dict[4] = "ghi";
	dict[5] = "jkl";
	dict[6] = "mno";
	dict[7] = "pqrs";
	dict[8] = "tuv";
	dict[9] = "wxyz";

	dfs(digits, 0, tmp, result);

	return result;
}


int main(int argc, char const *argv[])
{
	vector<string> result = letterCombinations("23");

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}