#include <iostream>
#include <string>
#include <stack>
#include <functional>
#include <unordered_map>
#include <vector>
#include <ctime>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
	if(root == NULL){
		return ;
	}
	TreeLinkNode *p = root;
	p -> next = NULL;
	while(p -> left != NULL){
		p -> left -> next = p -> right;
		if(p -> next == NULL){
			p -> right -> next = NULL;
			root = root -> left;
			p = root ;
		} else {
			p -> right -> next = p -> next -> left;
			p = p -> next;
		}
	}        
}

int main(int argc, char const *argv[])
{
	TreeLinkNode a(1);
	TreeLinkNode b(2);
	TreeLinkNode c(3);
	TreeLinkNode d(4);
	TreeLinkNode e(5);
	TreeLinkNode f(6);
	TreeLinkNode g(7);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &g;

	connect(&a);
	TreeLinkNode *res = &d;
	while(res != NULL){
		cout << res -> val << " " << endl;
		res = res -> next;
	}
	return 0;
}