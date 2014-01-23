#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *gen(ListNode *&head, int start, int end){
	if(start > end) return NULL;
	int mid = start + ((end - start) >> 1);
	TreeNode *left_child = gen(head, start, mid - 1);
	TreeNode *parent = new TreeNode(head -> val);
	parent -> left = left_child;
	head = head -> next;
	parent -> right = gen(head, mid + 1, end);
	return parent;
}

TreeNode *sortedListToBST(ListNode *head){
	ListNode *p = head;
	int length = 0;
	while(p){
		p = p -> next;
		++length;
	}
	return gen(head, 0, length - 1);
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
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);

	a.next = &b;
	b.next = &c;
	c.next = &d;

	TreeNode *res = sortedListToBST(&a);
	inorder(res);
	return 0;
}