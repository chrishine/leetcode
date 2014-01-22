#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumNumbers(TreeNode *root){
	if(!root) return 0;
	unordered_map<TreeNode* , string> path;
	path[root] = to_string(root -> val);
	queue<TreeNode* > que;
	que.push(root);
	vector<string> ans;

	while(!que.empty()){
		TreeNode *p = que.front();que.pop();
		if(p -> left){
			path[p -> left] = path[p] + to_string(p -> left -> val);
			que.push(p -> left);
		}
		if(p -> right){
			path[p -> right] = path[p] + to_string(p -> right -> val);
			que.push(p -> right);
		}
		if(!(p -> left) && !(p -> right))
			ans.push_back(path[p]);
	}

	int res = 0;
	for(auto s : ans){
		res += stoi(s);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	TreeNode a(1);
    TreeNode b(2);
    TreeNode c(2);
    TreeNode d(3);
    TreeNode e(3);
    TreeNode f(4);
    TreeNode g(4);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    d.left = &f;
    c.right = &e;
    e.right = &g;

    cout << sumNumbers(&a);
	return 0;
}