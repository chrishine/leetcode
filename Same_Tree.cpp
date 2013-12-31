#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode *p, TreeNode *q){
	if(p == NULL && q == NULL)
		return true;
	if(p == NULL && q != NULL)
		return false;
	if(p != NULL && q == NULL)
		return false;
	if(p -> val != q -> val ){
		return false;
	}
	return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
}

int main(){
	TreeNode root(1);
	TreeNode left(2);
	TreeNode right(3);
	TreeNode left1(4);
	root.left = &left;
	root.right = &right;
	left.left = &left1;

	TreeNode rootA(1);
	TreeNode leftA(3);
	TreeNode rightA(2);
	TreeNode leftA1(4);
	rootA.left = &leftA;
	rootA.right = &rightA;
	leftA.left = &leftA1;
	cout << isSameTree(&root, &rootA);
}