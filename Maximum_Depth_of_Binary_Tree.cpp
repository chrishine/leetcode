#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *root){
	if(root == NULL){
		return 0;
	}
	if(root -> left == NULL && root -> right == NULL){
		return 1;
	}
	if(root -> left == NULL && root -> right != NULL){
		return maxDepth(root -> right) + 1;
	}
	if(root -> left != NULL && root -> right == NULL){
		return maxDepth(root -> left) + 1;
	}
	if(root -> left != NULL && root -> right != NULL){
		return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
	}
}

int main(){
	TreeNode root(1);
	TreeNode left(2);
	TreeNode right(3);
	TreeNode left1(4);
	root.left = &left;
	root.right = &right;
	left.left = &left1;
	cout << maxDepth(&root);
}