#include <iostream>
#include <cstring>

using namespace std;

int lengthOfLastWord(const char *s){
	int ans = 0, tmp = 0;
	for(int i = 0; i < strlen(s); ++i){
		if(s[i] != ' '){
			++tmp;
			ans = tmp;
		}
		else
			tmp = 0;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	const char *s = "a   bbb";
	cout << lengthOfLastWord(s);
	return 0;
}