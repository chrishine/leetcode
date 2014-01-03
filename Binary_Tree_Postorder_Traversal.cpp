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

vector<int> postorderTraversal(TreeNode *root) {
	vector<int> res;
	stack<TreeNode *> s;
	if(root == NULL){
		return res;
	}
	TreeNode *p = root;
	TreeNode *prev = NULL;
	while(!s.empty() || p){
		if(p){
			s.push(p);
			p = p -> left;
		} else {
			TreeNode *q = s.top();
			if( q -> right == NULL || q -> right == prev){
				res.push_back(q -> val);
				s.pop();
				prev = q;
			}else {
				p = q -> right;
			}
		}	
	}
	return res;
}

int main(int argc, char const *argv[])
{
	TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    TreeNode g(7);
    TreeNode h(8);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;
    d.right = &h;

    vector<int> re =  postorderTraversal(&a);

    for(auto tmp : re){
    	cout << tmp << " " << endl;
    }
	return 0;
}