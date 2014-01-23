#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s){
	stack<char> ans;
	for(int i = 0; i < s.length(); ++i){
		if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
			ans.push(s[i]);
		} else if(s[i] == ')'){
			if(!ans.empty() && ans.top() == '(')
				ans.pop();
			else 
				return false;
		} else if(s[i] == ']'){
			if(!ans.empty() && ans.top() == '[')
				ans.pop();
			else 
				return false;
		} else if(s[i] == '}'){
			if(!ans.empty() && ans.top() == '{')
				ans.pop();
			else
				return false;
		}
	}
	return ans.empty();
}

int main(int argc, char const *argv[])
{
	string s("()[]{}");
	cout << isValid(s);
	return 0;
}