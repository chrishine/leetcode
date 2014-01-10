#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid){
	if(obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	if(obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) return 0;
	vector<vector<int>> ans(m, vector<int>(n, 0));
	int i = 0;
	for(i = 0; i < n; ++i){
		if(obstacleGrid[0][i] != 1)
			ans[0][i] = -1;
		else
			break;
	}
	while(i < n){
		ans[0][i] = 1;
		++i;
	}
	for(i = 0; i < m; ++i){
		if(obstacleGrid[i][0] != 1)
			ans[i][0] = -1;
		else 
			break;
	}
	while(i < m){
		ans[i][0] = 1;
		++i;
	}

	for(int i = 1; i < m; ++i){
		for(int j = 1; j < n; ++j){
			if(obstacleGrid[i][j] != 1 && ans[i][j] != 1){
				if(ans[i - 1][j] != 1 && ans[i][j -1] != 1)
					ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
				else if(ans[i - 1][j] != 1)
					ans[i][j] = ans[i - 1][j];
				else if(ans[i][j - 1] != 1)
					ans[i][j] = ans[i][j - 1]; 
				else 
					ans[i][j] = 1;
			} else {
				ans[i][j] = 1;
			}
		}
	}
	if(ans.back().back() == 1)
		return 0;
	return -ans.back().back();
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> input = {{0,0}, {1,1}, {0,0}};
	cout << uniquePathsWithObstacles(input);
	return 0;
}