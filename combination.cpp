#include <iostream>
#include <string>
#include <vector>

using namespace std;

void combination(string &s, int start, vector<string> &output)
{
	if (start == s.size()) {
		for (int i = 0; i < output.size(); i++)
			cout << output[i] << " ";
		cout << endl;

	}

	for (int i = start; i < s.size(); i++) {
		output.push_back(s.substr(start, i-start+1));
		combination(s, i+1, output);
		output.pop_back();
	}
}


int main(int argc, char const *argv[])
{

	vector<string> output;
	string s = "abc";
	combination(s, 0, output);
	return 0;

}