#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int> > &matrix){
	if(!matrix.empty()){
		int n = matrix.size();
		for(int i = 0; i < n/2; ++i)
			for(int j = i; j < n - 1 - i; ++j){
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = tmp;
			}
	}
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> input = {{1,2,3}, {4,5,6}, {7,8,9} };
	rotate(input);
	for(auto tmp : input){
		for(auto t : tmp)
			cout << t << " ";
		cout << endl;
	}
	return 0;
}