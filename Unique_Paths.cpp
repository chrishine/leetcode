#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n){
	if(m + n < 1) return 0;
	vector<vector<int>> ans(m, vector<int>(n, 0));
	for(int i = 0; i < n; ++i){
		ans[0][i] = 1;
	}
	for(int i = 0; i < m; ++i){
		ans[i][0] = 1;
	}
	for(int i = 1; i < m; ++i){
		for(int j = 1; j < n; ++j){
			ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
		}
	}
	return ans.back().back();
}

int main(int argc, char const *argv[])
{
	cout << uniquePaths(1, 1);
	return 0;
}