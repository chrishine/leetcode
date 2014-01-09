#include <iostream>
#include <vector>

using namespace std;

string common_prefix(string first, string second){
	int len = min(first.length(), second.length());
	string res = "";
	for(int i = 0; i < len; ++i){
		if(first[i] == second[i]){
			res += first[i];
			continue;
		}
		break;
	}
	return res;
}

string longestCommonPrefix(vector<string> &strs){
	string ans;
	if(strs.empty()) return ans;
	if(strs.size() == 1) return strs[0];
	ans = common_prefix(strs[0], strs[1]);

	for(int i = 2; i < strs.size(); ++i){
		ans = common_prefix(ans, strs[i]);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	vector<string> input = {"aa","aa"};
	cout << longestCommonPrefix(input);
	return 0;
}