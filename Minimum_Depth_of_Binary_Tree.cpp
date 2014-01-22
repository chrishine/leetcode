#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode *root){
	if(!root) return 0;
	unordered_map<TreeNode* , int> path;
	path[root] = 1;
	queue<TreeNode*> que;
	que.push(root);
	while(!que.empty()){
		TreeNode *p = que.front();que.pop();
		if(p -> left) {
			path[p -> left] = path[p] + 1;
			que.push(p -> left);
		}
		if(p -> right){
			path[p -> right] = path[p] + 1;
			que.push(p -> right);
		} 
		if(!(p -> left) && !(p -> right))
			return path[p];
	}
}

int main(int argc, char const *argv[])
{
	TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    TreeNode g(7);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    d.left = &e;
    e.left = &f;
    f.left = &g;

    cout << minDepth(&a);
	return 0;
}