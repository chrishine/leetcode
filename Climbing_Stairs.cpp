#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n){
	if(n <= 1) return 1;
	vector<int> ans(n + 1, 1);
	for(int i = 2; i <= n; ++i){
		ans[i] = ans[i - 2] + ans[i - 1];
	}
	return ans[n];
}

int main(int argc, char const *argv[])
{
	cout << climbStairs(44);
	return 0;
}