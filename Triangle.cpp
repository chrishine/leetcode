#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle){
	if(triangle.empty() || triangle[0].empty()) return 0;
	int n = triangle.size();
	vector<int> ans(n + 1, 0);
	while(n-- > 0){
		for(int i = 0; i <= n; ++i){
			ans[i] = triangle[n][i] + min(ans[i], ans[i + 1]);
		}
	}
	return ans[0];
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> input = {{1}, {-5,-2}, {3,6,1}, {-3,2,-1,4}};
	cout << minimumTotal(input);
	return 0;
}