#include <iostream>
#include <vector>

using namespace std;

vector<int> grayCode(int n){
	vector<int> ans;
	ans.push_back(0);
	if(!n) return ans;
	ans.push_back(1);
	if(n == 1) return ans;
	for(int i = 2; i <= n; ++i){
		int max = (1 << (i - 1));
		for(int j = max - 1; j >=0; --j){
			ans.push_back(max + ans[j]);
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	for(auto tmp : grayCode(3))
		cout << tmp << " ";
	return 0;
}
