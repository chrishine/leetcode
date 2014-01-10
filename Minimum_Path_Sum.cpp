#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int> > &grid){
	if(grid.empty() || grid[0].empty()) return 0;
	int m = grid.size(), n = grid[0].size();
	int single_res = 0;
	if(m == 1){
		for(auto tmp :grid[0])
			single_res += tmp;
		return single_res;
	}
	if(n == 1){
		for(int i = 0; i < m; ++i)
			single_res += grid[i][0];
		return single_res;
	}

	vector<vector<int>> ans(m, vector<int>(n, 0));
	ans[0][0] = grid[0][0];
	for(int i = 1; i < n; ++i)
		ans[0][i] = ans[0][i - 1] + grid[0][i];
	for(int i = 1; i < m; ++i)
		ans[i][0] = ans[i - 1][0] + grid[i][0];
	for(int i = 1; i < m; ++i){
		for(int j = 1; j < n; ++j){
			ans[i][j] = min(ans[i - 1][j], ans[i][j - 1]) + grid[i][j];
		}
	}
	return ans.back().back();
}

int main(int argc, char const *argv[])
{
	vector<int> one = {1,2,3,4};
	vector<int> two = {4,3,2,1};
	vector<vector<int>> input = {one, two};
	cout << minPathSum(input);
	return 0;
}