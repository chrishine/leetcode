#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *gen(vector<int>& preorder, vector<int>& inorder, vector<int>& map, int offset){
	int root_val = preorder[offset];
	int index = map[root_val];
	TreeNode *root = new TreeNode(root_val);
	root -> left = gen(preorder, inorder[] , map, )
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
	if(preorder.empty() || inorder.empty()) return NULL;
	vector<int> map(inorder.size(), 0);
	for(int i = 0; i < inorder.size(); ++i){
		map[inorder[i]] = i;
	}
	return gen(preorder, map, 0);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}