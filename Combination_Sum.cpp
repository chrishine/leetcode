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
		if(target < num[i])
			return;
		single.push_back(num[i]);
		gen(num, target - num[i], i, single, ans);
		single.pop_back();
	}
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target){
	vector<vector<int>> ans;
	vector<int> single;
	sort(candidates.begin(), candidates.end());
	gen(candidates, target, 0, single, ans);
	return ans;
}

int main(int argc, char const *argv[])
{
	vector<int> input = {2,3,6,7};
	for(auto tmp : combinationSum(input, 7)){
		for(auto t : tmp)
			cout << t << " ";
		cout << endl;
	}
	return 0;
}