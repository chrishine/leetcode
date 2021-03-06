#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getDepth(TreeNode *root){
	if(!root) return 0;
	return max(getDepth(root -> left), getDepth(root -> right)) + 1;
}

vector<vector<int> > levelOrderBottom(TreeNode *root){
	vector<vector<int>> ans;
	if(!root) return ans;
	int height = getDepth(root);
	ans.resize(height);

	vector<int> level;
	TreeNode *seg = root;
	stack<TreeNode *> record;
	queue<TreeNode *> que;
	que.push(root);
	while(!que.empty()){
		TreeNode *p = que.front();que.pop();
		record.push(p);
		level.push_back(p -> val);
		if(p == seg){
			ans[--height] = level;
			level.clear();
			while(!record.empty()){
				TreeNode *q = record.top();record.pop();
				if(q -> right) {
					seg = q -> right;
					break;
				} 
				if(q -> left && !(q -> right)) {
					seg = q -> left;
					break;
				} 
			}
			stack<TreeNode *> empty;
			swap(record,empty);
		}
		if(p -> left){
			que.push(p -> left);
		}
		if(p -> right){
			que.push(p -> right);
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	TreeNode a(1);
    TreeNode b(2);
    a.right = &b;

	vector<vector<int>> res = levelOrderBottom(&a);
	for(auto tmp : res){
		for(auto t : tmp)
			cout << t << " ";
		cout << endl;
	}
	return 0;
}