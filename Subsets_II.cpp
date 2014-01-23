#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void gen(vector<int> &source, int start, vector<int>& single, vector<vector<int>>& ans){
	ans.push_back(single);
	for(int i = start; i < source.size(); ++i){
		if(i != start && source[i] == source[i - 1])
			continue;
		single.push_back(source[i]);
		gen(source, i + 1, single, ans);
		single.pop_back();
	}
}

vector<vector<int> > subsetsWithDup(vector<int> &S){
	vector<int> single;
	vector<vector<int>> ans;
	sort(S.begin(), S.end());
	gen(S, 0, single, ans);
	return ans;
}

int main(int argc, char const *argv[])
{
	vector<int> input = {1,2,2};
	for(auto tmp : subsetsWithDup(input)){
		for(auto t : tmp)
			cout << t << " ";
		cout << endl;
	}
	return 0;
}