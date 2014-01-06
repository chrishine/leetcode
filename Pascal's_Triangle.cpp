#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<vector<int> > generate(int numRows){
	vector<vector<int>> ans;
	if(!numRows) return ans;
	vector<int> tmp = {1};
	ans.push_back(tmp);
	if(numRows == 1) return ans;
	vector<int> temp = {1,1};
	ans.push_back(temp);
	if(numRows == 2) return ans;
	for(int i = 3; i <= numRows; ++i){
		vector<int> tmp(i,0);
		tmp.front() = 1;
		tmp.back() = 1;
		vector<int> prev = ans.back();
		for(int j = 0; j < prev.size() - 1; ++j){
			tmp[j + 1] = prev[j] + prev[j + 1];
		}
		ans.push_back(tmp);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	auto c = clock();
	vector<vector<int>> ans = generate(20);
	cout << c - clock() << endl;
	for(auto tmp : ans){
		for(auto t : tmp)
			cout << " " << t;
		cout << endl;
	}
	return 0;
}