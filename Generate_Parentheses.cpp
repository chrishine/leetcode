#include <iostream>
#include <vector>
#include <string>

using namespace std;

void prev(vector<string>& ans, string single, int left, int right, int n){
	if(left == n){
		single.append(n - right, ')');
		ans.push_back(single);
		return;
	}
	prev(ans, single + '(', left + 1, right, n);
	if(left > right) prev(ans, single + ')', left, right + 1,n);
}

vector<string> generateParenthesis(int n){
	vector<string> ans;
	if(n) prev(ans, "", 0, 0, n);
	return ans;
}

int main(int argc, char const *argv[])
{
	for(auto tmp : generateParenthesis(3))
		cout << tmp << " ";
	return 0;
}