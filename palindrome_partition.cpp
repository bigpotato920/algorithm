#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_palindrome(string &s, int i, int j)
{
   
    while (i <= j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    
    return true;
}

void part_helper(string s, int start, vector<string> &output, vector<vector<string> > &result) {

	//cout << "start = " << start << endl;
	if (start == s.size()) {
		result.push_back(output);
		return;
	}

	for (int i = start; i < s.size(); i++) {
		//cout << "i = " << i << endl;
		if (is_palindrome(s, start, i)) {
			output.push_back(s.substr(start, i-start+1));
			part_helper(s, i+1, output, result);
			output.pop_back();
		}
	}
}

vector<vector<string> > partition(string s) {
	vector<vector<string> > result;
	vector<string> output;
	part_helper(s, 0, output, result);


	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return result;
}



int main(int argc, char const *argv[])
{
	partition("aab");
	return 0;
}