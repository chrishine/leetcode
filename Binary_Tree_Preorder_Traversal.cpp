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


vector<int> preorderTraversal(TreeNode *root) {
	vector<int> res;
    stack<TreeNode *> s;
    if(root == NULL){
        return res;
    }
    TreeNode *p = root;
    while(!s.empty() || p){
        if(p){
            res.push_back(p -> val);
            s.push(p);
            p = p -> left;
        } else {
            p = s.top();s.pop();
            p = p -> right;
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
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    vector<int> res =  preorderTraversal(&a);

    for(auto tmp : res){
    	cout << tmp << " " << endl;
    }
	return 0;
}