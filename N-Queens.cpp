#include <iostream>
#include <vector>
#include <string>

using namespace std;

void flag(vector<vector<int>>& index, int row, int col, int val){
	int m = index.size(), n = index[0].size();
	for(int i = -1; i < 2; ++i){
		for(int j = -1; j < 2; ++j){
			if(i == 0 && j == 0)
				continue;
			for(int k = 1; ;++k){
				int r = row + i * k, c = col + j * k;
				if(r < 0 || r >= m || c < 0 || c >= n)
					break;
				index[r][c] += val;
			}
		}
	}
}

void gen(int row, int n, vector<string>& single, vector<vector<string>>& ans, vector<vector<int>>& index){
	if(row == n){
		ans.push_back(single);
		return;
	}
	for(int i = 0; i < n; ++i){
		if(index[row][i])
			continue;
		flag(index, row ,i ,1);
		single[row][i] = 'Q';
		gen(row + 1, n, single, ans, index);
		single[row][i] = '.';
		flag(index, row, i, -1);
	}
}

vector<vector<string> > solveNQueens(int n){
	vector<vector<string>> ans;
	vector<vector<int>> index(n, vector<int>(n, 0));
	vector<string> single(n, string(n, '.'));
	gen(0, n, single, ans, index);
	return ans;
}

int main(int argc, char const *argv[])
{
	for(auto tmp : solveNQueens(4)){
		for(auto t : tmp)
			cout << t << endl;
		cout << "******************" << endl;
	}
	return 0;
}
