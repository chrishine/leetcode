#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode *root){
	vector<vector<int>> ans;
	if(!root) return ans;

	vector<int> level;
	stack<TreeNode*> current, next;
	bool left_order = true;
	current.push(root);
	while(!current.empty()){
		TreeNode *p = current.top();current.pop();
		if(p){
			level.push_back(p -> val);
			if(left_order){
				next.push(p -> left);
				next.push(p -> right);
			} else{
				next.push(p -> right);
				next.push(p -> left);
			}
		}
		if(current.empty()){
			if(next.empty()){
				return ans;
			}
			ans.push_back(level);
			level.clear();
			left_order = !left_order;
			swap(current, next);
		}
	}
}

int main(int argc, char const *argv[])
{
	TreeNode a(3);
	TreeNode b(9);
	TreeNode c(20);
	TreeNode d(15);
	TreeNode e(7);

	a.left = &b;
	a.right = &c;
	c.left = &d;
	c.right = &e;

	for(auto tmp :zigzagLevelOrder(&a)){
		for(auto t : tmp)
			cout << t << " ";
		cout << endl;
	}
	return 0;
}