#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string& s, int i, int j){
	while(i < j){
		if(s[i++] != s[j--])
			return false;
	}
	return true;
}

void gen(string s, int start, vector<vector<string>>& ans, vector<int>& index){
	if(start == s.length()){
		vector<string> single;
		for(int k = 0; k < index.size() - 1; ++k)
			single.push_back(s.substr(index[k] + 1, index[k + 1] - index[k]));
		ans.push_back(single);
		return;
	}
	for(int j = start; j < s.length(); ++j){
		if(isPalindrome(s, start, j)){
			index.push_back(j);
			gen(s, j + 1, ans, index);
			index.pop_back();
		}
	}
}

vector<vector<string>> partition(string s){
	vector<vector<string>> ans;
	vector<int> index;
	if(!s.length()) return ans;
	index.push_back(-1);
	gen(s, 0, ans, index);
	return ans;
}

int main(int argc, char const *argv[])
{
	string s("aab");
	for(auto tmp : partition(s)){
		for(auto t : tmp)
			cout << " " << t;
		cout << endl;
	}
	return 0;
}