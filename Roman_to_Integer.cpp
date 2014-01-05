#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int handle(int ans, int last_number, int last_ans){
	return (last_number > ans)? last_ans - ans : last_ans + ans;
}

int romanToInt(string s){
	for(int i = 0; i < s.length(); ++i){
		s[i] = toupper(s[i]);
	}
	int ans = 0;
	int last_number = 0;
	for(int i = s.length() - 1; i >= 0; --i){
		auto c = s[i];
		switch(c){
			case 'M' :
				ans = handle(1000, last_number, ans);
				last_number = 1000;
				break;
			case 'D' :
				ans = handle(500, last_number, ans);
				last_number = 500;
				break;
			case 'C' :
				ans = handle(100, last_number, ans);
				last_number = 100;
				break;
			case 'L' :
				ans = handle(50, last_number, ans);
				last_number = 50;
				break;
			case 'X' :
				ans = handle(10, last_number, ans);
				last_number = 10;
				break;
			case 'V' :
				ans = handle(5, last_number, ans);
				last_number = 5;
				break;
			case 'I' :
				ans = handle(1, last_number, ans);
				last_number = 1;
				break;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	cout << romanToInt("DCXXI");
	return 0;
}