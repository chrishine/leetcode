#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head){
	if(!head || !(head -> next) ) return head;
	ListNode *p = head;
	head = head -> next;
	ListNode *prev = NULL;
	ListNode *q = NULL;
	while(p && p -> next){
		if(prev) prev -> next = p -> next;
		q = p -> next -> next;
		p -> next -> next= p;
		p -> next = q;
		prev = p;
		p = q;
	}
	return head;
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

	ListNode *res = swapPairs(&a);
	while(res){
		cout << res -> val ;
		res = res -> next;
	}
	return 0;
}