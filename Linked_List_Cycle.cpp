#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head){
	ListNode *fast_node;
	if(head != NULL && head -> next != NULL){
		fast_node = head -> next;
	}
	else return false;
	while(fast_node != NULL && fast_node -> next != NULL){
		fast_node = fast_node -> next -> next;
		head = head -> next;
		if(head == fast_node){
			return true;
		}
	}
	return false;
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
	d.next = &a;

	cout << hasCycle(&a) << endl;
}