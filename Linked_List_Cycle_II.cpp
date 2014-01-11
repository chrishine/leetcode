#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head){
	if(!head || !(head -> next))
		return NULL;
	ListNode *slow = head -> next;
	ListNode *fast = head -> next -> next;
	while(slow != fast){
		if(!slow || !fast) return NULL;
		slow = slow -> next;
		fast = fast -> next;
		if(fast) 
			fast = fast -> next;
		else 
			return NULL;
	}
	slow = head;
	while(slow != fast){
		slow = slow -> next;
		fast = fast -> next;
	}
	return slow;
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

	cout << detectCycle(&a) -> val ;
	return 0;
}