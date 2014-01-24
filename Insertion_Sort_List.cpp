#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertionSortList(ListNode *head){
	if(!head || !(head -> next)) return head;
	ListNode *dummy = new ListNode(-1);
	dummy -> next = head;
	ListNode *sorted = head;
	ListNode *unsort = head -> next;
	while(unsort){
		if(sorted -> val > unsort -> val){
			ListNode *p = dummy -> next;
			ListNode *prev = dummy;
			while(p -> val < unsort -> val){
				p = p -> next;
				prev = prev -> next;
			}
			sorted -> next = unsort -> next;
			unsort -> next = p;
			prev -> next = unsort;
			unsort = sorted -> next;
		} else{
			unsort = unsort -> next;
			sorted = sorted -> next;
		}
	}
	return dummy -> next;
}
                                                                                                                  
int main(int argc, char const *argv[])
{
	ListNode a(4);
	ListNode b(3);
	ListNode c(2);
	ListNode d(1);

	a.next = &b;
	b.next = &c;
	c.next = &d;

	ListNode *ans = insertionSortList(&a);
	while(ans){
		cout << ans -> val << " ";
		ans = ans -> next;
	}
	return 0;
}