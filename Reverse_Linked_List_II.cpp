#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n){
	if(m == n) return head;
	ListNode *dummy = new ListNode(-1);
	dummy -> next = head;
	ListNode *prev = dummy;
	ListNode *p = dummy;
	for(int i = 1; i <= n; ++i){
		if(i == m) p = prev;
		if(i > m && i <= n){
			prev -> next = head -> next;
			head -> next = p -> next;
			p -> next = head;
			head = prev;
		}
		prev = head;
		head = head -> next;
	}
	return dummy -> next;
}

int main(int argc, char const *argv[])
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	ListNode *ans = reverseBetween(&a, 2, 4);
	while(ans){
		cout << ans -> val << " ";
		ans = ans -> next;
	}
	return 0;
}