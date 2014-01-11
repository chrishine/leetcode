#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int> > &matrix){
	if(!matrix.empty() && !matrix[0].empty()){
		int m = matrix.size(), n = matrix[0].size();
		bool first_row = false, fisrt_col = false;
		for(int i = 0; i < n; ++i)
			if(!matrix[0][i]){
				first_row = true;
				break;
			}
		for(int j = 0; j < m; ++j)
			if(!matrix[j][0]){
				fisrt_col = true;
				break;
			}
		for(int i = 1; i < m; ++i)
			for(int j = 1; j < n; ++j)
				if(!matrix[i][j]){
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
		for(int i = 1; i < m; ++i)
			for(int j = 1; j < n; ++j)
				if(!matrix[i][0] || !matrix[0][j])
					matrix[i][j] = 0;
		if(first_row)
			for(int i = 0; i < n; ++i)
				matrix[0][i] = 0;
		if(fisrt_col)
			for(int i = 0; i < m; ++i)
				matrix[i][0] = 0;
	}

}

int main(int argc, char const *argv[])
{
	vector<vector<int>> input = {{1,1,1}, {1,0,1}, {1,1,1}};
	setZeroes(input);
	for(auto tmp : input){
		for(auto t : tmp)
			cout << t << " ";
		cout << endl;
	}
	return 0;
}