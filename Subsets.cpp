#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > subsets(vector<int> &S){
	sort(S.begin(), S.end());
	vector<vector<int>> ans(1);
	for(int i = 0; i < S.size(); ++i){
		int j = ans.size();
		while(j-- > 0){
			ans.push_back(ans[j]);
			ans.back().push_back(S[i]);
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	vector<int> input = {1,2,3};
	for(auto tmp : subsets(input)){
		for(auto t : tmp)
			cout << t << " ";
		cout << endl;
	}
	return 0;
}