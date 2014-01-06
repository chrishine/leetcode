#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<int> getRow(int rowIndex){
	rowIndex = rowIndex + 1;
	vector<int> ans;
	ans = {1};
	if(rowIndex == 1) return ans;
	ans = {1,1};
	if(rowIndex == 2) return ans;
	vector<int> prev = ans;
	for(int i = 3; i <= rowIndex; ++i){
		vector<int> tmp(i,0);
		tmp.front() = 1;
		tmp.back() = 1;
		for(int j = 0; j < prev.size() - 1; ++j){
			tmp[j + 1] = prev[j] + prev[j + 1];
		}
		prev = tmp;
	}
	return prev;
}

int main(int argc, char const *argv[])
{
	auto c = clock();
	vector<int> ans = getRow(5);
	cout << c - clock() << endl;
	for(auto tmp : ans){
		cout << " " << tmp << endl;
	}
	return 0;
}