#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode *root){
	if(!root) return ;
	TreeNode *left = root -> left;
	TreeNode *right = root -> right;
	if(left){
		root -> right = left;
		root -> left = NULL;
		TreeNode *right_most = left;
		while(right_most -> right){
			right_most = right_most -> right;
		}
		right_most -> right = right;
	}
	flatten(root -> right);
}

int main(int argc, char const *argv[])
{
	TreeNode *a = new TreeNode(1);
    TreeNode b(2);
    TreeNode c(2);
    TreeNode d(3);
    TreeNode e(3);
    TreeNode f(4);
    TreeNode g(4);

    a -> left = &b;
    a -> right = &c;
    b.left = &d;
    d.left = &f;
    c.right = &e;
    e.right = &g;

    flatten(a);
    while(a){
    	cout << a -> val << " ";
    	a = a -> right;
    }
	return 0;
}