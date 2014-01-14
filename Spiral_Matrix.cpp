#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix){
	vector<int> ans;
	if(matrix.empty() || matrix[0].empty()) return ans;
	int m_begin = 0, m_end = matrix.size() - 1;
	int n_begin = 0, n_end = matrix[0].size() - 1;
	while(true){
		for(int i = n_begin; i <= n_end; ++i)
			ans.push_back(matrix[m_begin][i]);
		if(++m_begin > m_end) return ans;

		for(int i = m_begin; i <= m_end; ++i)
			ans.push_back(matrix[i][n_end]);
		if(--n_end < n_begin) return ans;

		for(int i = n_end; i >= n_begin; --i)
			ans.push_back(matrix[m_end][i]);
		if(--m_end < m_begin) return ans;

		for(int i = m_end; i >= m_begin; --i)
			ans.push_back(matrix[i][n_begin]);
		if(++n_begin > n_end) return ans;
	}
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> input = {{1,2,3}, {4,5,6}, {7,8,9}};
	for(auto tmp : spiralOrder(input))
		cout << tmp << " ";
	return 0;
}