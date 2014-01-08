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

vector<vector<int> > levelOrder(TreeNode *root){
	vector<vector<int>> ans;
	if(!root) return ans;
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
			ans.push_back(level);
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

	vector<vector<int>> res = levelOrder(&a);
	for(auto tmp : res){
		for(auto t : tmp)
			cout << t << " ";
		cout << endl;
	}
	return 0;
}