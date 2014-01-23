#include <iostream>
#include <string>

using namespace std;

string gen(string s){
	if(s == "") return "1";
	string tmp = "";
	for(int i = 0; i < s.length(); ++i){
		int count = 1;
		while(i + 1 < s.length() && s[i] == s[i + 1]){
			++i;
			++count;
		}
		tmp += to_string(count);
		tmp += s[i];
	}
	return tmp;
}

string countAndSay(int n){
	string ans = "";
	if(!n) return ans;
	for(int i = 0; i < n; ++i){
		ans = gen(ans);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	cout << countAndSay(2);
	return 0;
}
