#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool gen(TreeNode *root, TreeNode *left_child, TreeNode *right_child){
	if(!root) return true;
	if(left_child && left_child -> val >= root -> val)
		return false;
	if(right_child && right_child -> val <= root -> val)
		return false;
	return gen(root -> left, left_child ,root) && gen(root -> right, root, right_child);
}

bool isValidBST(TreeNode *root){
	return gen(root, NULL, NULL);
}

int main(int argc, char const *argv[])
{
	TreeNode a(1);
	TreeNode b(2);
	a.left = &b;
	cout << isValidBST(&a);
	return 0;
}