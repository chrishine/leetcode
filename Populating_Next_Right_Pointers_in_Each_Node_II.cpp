#include <iostream>

using namespace std;

struct TreeLinkNode {
  	int val;
  	TreeLinkNode *left, *right, *next;
  	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root){
	while(root){
		TreeLinkNode *first = NULL;
		TreeLinkNode *prev = NULL;
		while(root){
			if(!first) first = root -> left? root -> left : root -> right;
			if(root -> left){
				if(prev) prev -> next = root -> left;
				prev = root -> left;
			}
			if(root -> right){
				if(prev) prev -> next = root -> right;
				prev = root -> right;
			}
			root = root -> next;
		}
		root = first;
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

	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;

	connect(&a);

	TreeLinkNode *res = &d;
	while(res != NULL){
		cout << res -> val << " " << endl;
		res = res -> next;
	}
	return 0;
}