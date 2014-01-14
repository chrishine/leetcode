#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode *root, int sum){
	if(!root) return false;
	if(!(root -> left) && !(root -> right) && root -> val == sum)
		return true;
	else 
		return hasPathSum(root -> left, sum - root -> val) || hasPathSum(root -> right, sum - root ->val);
}

int main(int argc, char const *argv[])
{
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);

	a.left = &b;
	a.right = &c;

	cout << hasPathSum(&a, 4);
	return 0;
}