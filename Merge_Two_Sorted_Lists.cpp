#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
	if( !l1) return l2;
	if( !l2) return l1;
	ListNode *ans = NULL;
	if(l1 -> val <= l2 -> val){
		ans = l1;
		l1 = l1 -> next;
	} else {
		ans = l2;
		l2 = l2 -> next;
	}

	ListNode *last = ans;
	while( l1 && l2){
		if(l1 -> val <= l2 -> val){
			last -> next = l1;
			last = last -> next;
			l1 = l1 -> next;
		} else {
			last -> next = l2;
			last = last -> next;
			l2 = l2 -> next;
		}
	}
	if(l1) last -> next = l1;
	if(l2) last -> next = l2;
	return ans;
}

int main(int argc, char const *argv[])
{
	ListNode a(1);
	ListNode b(3);
	a.next = &b;

	ListNode c(2);
	ListNode d(4);
	c.next = &d;

	ListNode *res = mergeTwoLists(&a, &c);
	while(res){
		cout << res -> val;
		res = res -> next;
	}
	return 0;
}