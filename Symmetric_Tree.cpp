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

bool symmetric_pre(TreeNode *p, TreeNode *q){
	if(!p && !q) return true;
	if(!p || !q) return false;
	if(p -> val != q -> val) return false;
	return symmetric_pre(p -> left, q -> right) && symmetric_pre(p -> right, q -> left);
}

bool isSymmetric(TreeNode *root){
	if(root == NULL) return true;
	return symmetric_pre(root -> left, root -> right);
}

int main(int argc, char const *argv[])
{
	TreeNode a(1);
    TreeNode b(2);
    TreeNode c(2);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(4);
    TreeNode g(3);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    cout << isSymmetric(&a);
	return 0;
}
