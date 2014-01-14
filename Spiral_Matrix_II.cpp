#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int n){
	vector<vector<int>> ans(n, vector<int>(n, 0));
	int num = 1, upper = n * n;
	int x_start = 0, x_end = n - 1;
	int y_start = 0, y_end = n - 1;
	while(num <= upper){
		for(int i = x_start; i <= x_end; ++i)
			ans[y_start][i] = num++;

		for(int i = ++y_start; i <= y_end; ++i)
			ans[i][x_end] = num++;

		for(int i = --x_end; i >= x_start; --i)
			ans[y_end][i] = num++;

		for(int i = --y_end; i >= y_start; --i)
			ans[i][x_start] = num++;
		++x_start;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> ans = generateMatrix(3);
	for(auto tmp : ans){
		for(auto t : tmp)
			cout << t << " ";
		cout << endl;
	}
	return 0;
}