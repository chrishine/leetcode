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

TreeNode *BST_pre(vector<int> &num, int low, int high){
	int mid = low + (high - low) / 2;
	TreeNode *root = new TreeNode(num[mid]);
	if(mid + 1 < high) root -> right = BST_pre(num, mid + 1, high);
	if(mid > low) root -> left = BST_pre(num, low, mid);
	return root;
}

TreeNode *sortedArrayToBST(vector<int> &num){
	if(num.empty()) return NULL;
	int mid = num.size() / 2;
	TreeNode *root = new TreeNode(num[mid]);
	if(mid + 1 < num.size()) root -> right = BST_pre(num, mid + 1, num.size());
	if(mid > 0)	root -> left = BST_pre(num, 0, mid);
	return root;
}

void inorder(TreeNode *root){
	if( root ){
		inorder(root -> left);
		cout << root -> val << endl;
		inorder(root -> right);
	}
}

int main(int argc, char const *argv[])
{
	vector<int> num = {1,2,3,4,5,6,7};
    TreeNode *res = sortedArrayToBST(num);
    inorder(res);
	return 0;
}