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

TreeNode *gen(vector<int>& preorder, int start, int end, unordered_map<int, int>& map_index, int start2, int end2){
	if(start > end || start2 > end2) return NULL;
	int root_val = preorder[start];
	int index = map_index[root_val];
	TreeNode *root = new TreeNode(root_val);
	root -> left = gen(preorder, start + 1, start + index - start2, map_index, start2, index - 1);
	root -> right = gen(preorder, start + index - start2 + 1, end, map_index, index + 1, end2);
	return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
	if(preorder.empty() || inorder.empty()) return NULL;
	unordered_map<int, int> map_index;
	for(int i = 0; i < inorder.size(); ++i){
		map_index[inorder[i]] = i;
	}
	return gen(preorder, 0, preorder.size() - 1, map_index, 0, inorder.size() - 1);
}

void postorder(TreeNode *root){
	if(root){
		postorder(root -> left);
		postorder(root -> right);
		cout << root -> val << " ";
	}
}

int main(int argc, char const *argv[])
{
	vector<int> preorder = {1,3,2,4};
	vector<int> inorder = {1,2,3,4};
	TreeNode *ans = buildTree(preorder, inorder);
	postorder(ans);
	return 0;
}