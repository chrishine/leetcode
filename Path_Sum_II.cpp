#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void gen(TreeNode *root, int sum, vector<vector<int>>& ans,vector<int>& single_ans){
	if(!root) return;
	single_ans.push_back(root -> val);
	if(!(root -> left) && !(root -> right) && root -> val == sum){
		ans.push_back(single_ans);
		single_ans.pop_back();
		return;
	}
	if(root -> left) gen(root -> left, sum - root -> val, ans, single_ans);
	if(root -> right) gen(root -> right, sum - root -> val, ans, single_ans);
	single_ans.pop_back();
}

vector<vector<int> > pathSum(TreeNode *root, int sum){
	vector<vector<int>> ans;
	vector<int> single_ans;
	gen(root, sum, ans, single_ans);
	return ans;
}

int main(int argc, char const *argv[])
{
	TreeNode a(1);
	TreeNode b(1);
	TreeNode c(3);
	TreeNode d(2);

	a.left = &b;
	a.right = &c;
	b.left = &d;
	
	for(auto tmp : pathSum(&a, 4)){
		for(auto t : tmp)
			cout << t << " ";
		cout << endl;
	}
	return 0;
}