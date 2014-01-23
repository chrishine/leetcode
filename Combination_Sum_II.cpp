#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void gen(vector<int>& num, int target, int start, vector<int>& single, vector<vector<int>>& ans){
	if(target == 0){
		ans.push_back(single);
		return;
	}
	for(int i = start; i < num.size(); ++i){
		if(i != start && num[i] == num[i - 1])
			continue;
		if(target < num[i])
			return;
		single.push_back(num[i]);
		gen(num, target - num[i], i + 1, single, ans);
		single.pop_back();
	}
}

vector<vector<int> > combinationSum2(vector<int> &num, int target){
	vector<vector<int>> ans;
	vector<int> single;
	sort(num.begin(), num.end());
	gen(num, target, 0, single, ans);
	return ans;
}

int main(int argc, char const *argv[])
{
	vector<int> input = {10,1,2,7,6,1,5};
	for(auto tmp : combinationSum2(input, 8)){
		for(auto t : tmp)
			cout << t << " ";
		cout << endl;
	}
	return 0;
}