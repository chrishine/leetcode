#include <iostream>
#include <vector>

using namespace std;

int minCut(string s){
	int len = s.length();
	int cut[len + 1];
	bool is_palin[len][len];

	for(int i = 0; i <= len; ++i)
		cut[i] = len - i;
	for(int i = 0; i < len; ++i)
		for(int j = 0; j < len; ++j)
			is_palin[i][j] = false;

	for(int i = len - 1; i >= 0; --i){
		for(int j = i; j < len; ++j){
			if(s[i] == s[j] && (j - i < 2 || is_palin[i + 1][j - 1])){
				is_palin[i][j] = true;
				cut[i] = min(cut[i], cut[j + 1] + 1);
			}
		}
	}
	return cut[0] -1;
}

int main(int argc, char const *argv[])
{
	string s("aab");
	cout << minCut(s);
	return 0;
}