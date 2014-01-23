#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> gen(int start, int end){
	if(start > end){
		vector<TreeNode*> single = {NULL};
		return single;
	}
	vector<TreeNode*> ans;
	for(int i = start; i <= end; ++i){
		vector<TreeNode*> left_child = gen(start, i - 1);
		vector<TreeNode*> right_child = gen(i + 1, end);
		for(int j = 0; j < left_child.size(); ++j){
			for(int k = 0; k < right_child.size(); ++k){
				TreeNode *root = new TreeNode(i);
				root -> left = left_child[j];
				root -> right = right_child[k];
				ans.push_back(root);
			}
		}
	}
	return ans;
}

vector<TreeNode *> generateTrees(int n){
	return gen(1, n);
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
	for(auto tmp : generateTrees(3)){
		inorder(tmp);
		cout << "*************" << endl;
	}
	return 0;
}