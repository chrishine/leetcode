#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool balance_pre(TreeNode *root, int& height){
	if(!root) {
		height = 0;
		return true;
	} 
	
	int lh = height + 1, rh = height + 1;

	bool l = balance_pre(root -> left, lh);
	bool r = balance_pre(root -> right, rh);
	height = max(lh, rh) + 1;
	if(abs(rh - lh) >= 2)
		return false;
	return l&&r;
}

bool isBalanced(TreeNode *root){ 
	if(!root) return true;

	int lh = 0, rh = 0;
	bool l = balance_pre(root -> left, lh);
	bool r = balance_pre(root -> right, rh);

	if(abs(rh - lh) >= 2)
		return false;
	return l&&r;
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
    
    cout << isBalanced(&a);
	return 0;
}