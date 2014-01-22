#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string s){
	int i = 0, j = s.length() - 1;
	while(i < j){
		if(!isalnum(s[i])){
			++i;
			continue;
		}
		if(!isalnum(s[j])){
			--j;
			continue;
		}
		if(tolower(s[i++]) != tolower(s[j--])) return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string s("A man, a plan, a canal: Panama");
	cout << isPalindrome(s);
	return 0;
}