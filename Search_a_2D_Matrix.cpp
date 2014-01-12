#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target){
	if(matrix.empty() || matrix[0].empty()) return false;
	int m = matrix.size(), n = matrix[0].size();
	int low = 0, high = m * n - 1;
	while(low <= high){
		int mid = low + (high - low)/2;
		if(matrix[mid/n][mid%n] == target){
			return true;
			continue;
		}	
		if(matrix[mid/n][mid%n] > target){
			high = mid - 1;
			continue;
		}
		if(matrix[mid/n][mid%n] < target){
			low = mid + 1;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> input = {{1}};
	cout << searchMatrix(input, 0);
	return 0;
}