#include <iostream>
#include <vector>

using namespace std;

void gen(vector<vector<int>>& ans, vector<int>& single_ans, int n, int k, int index){
	if(!k)
		ans.push_back(single_ans);
	else if(k > 0 && index <= n){
		single_ans.push_back(index);
		gen(ans, single_ans, n, k - 1, index + 1);
		single_ans.pop_back();
		gen(ans, single_ans, n, k, index + 1);
	}
}

vector<vector<int> > combine(int n, int k){
	vector<vector<int>> ans;
	if(!n || n < k) return ans;
	vector<int> single_ans;
	gen(ans, single_ans, n, k, 1);
	return ans;
}

int main(int argc, char const *argv[])
{
	for(auto tmp : combine(4, 3)){
		for(auto t : tmp)
			cout << t << " ";
		cout << endl;
	}
	return 0;
}