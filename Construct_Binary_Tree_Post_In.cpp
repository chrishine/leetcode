#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *gen(vector<int>& postorder, int start, int end, unordered_map<int, int>& map_index, int start2, int end2){
	if(start > end || start2 > end2) return NULL;
	int root_val = postorder[end];
	int index = map_index[root_val];
	TreeNode *root = new TreeNode(root_val);
	root -> right = gen(postorder, end - end2 + index, end - 1, map_index, index + 1, end2);
	root -> left = gen(postorder, start, end - end2 + index - 1, map_index, start2, index - 1);
	return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
	if(inorder.empty() || postorder.empty()) return NULL;
	unordered_map<int, int> map_index;
	for(int i = 0; i < inorder.size(); ++i){
		map_index[inorder[i]] = i;
	}
	return gen(postorder, 0, postorder.size() - 1, map_index, 0, inorder.size() - 1);
}

void preorder(TreeNode *root){
	if(root){
		cout << root -> val << " ";
		preorder(root -> left);
		preorder(root -> right);
	}
}

int main(int argc, char const *argv[])
{
	vector<int> postorder = {4,2,3,1};
	vector<int> inorder = {4,2,1,3};
	TreeNode *ans = buildTree(inorder, postorder);
	preorder(ans);
	return 0;
}