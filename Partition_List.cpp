#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x){
	ListNode *ans = new ListNode(-1);
	ListNode *pivot = new ListNode(x);
	ListNode *ans_last = ans, *pivot_last = pivot;
	ListNode *p = head;

	while(p){
		ListNode *q = p -> next;
		if(p -> val < x){
			ans_last -> next = p;
			ans_last = p;
		} else {
			pivot_last -> next = p;
			pivot_last = p;
			pivot_last -> next = NULL;
		}
		p = q;
	}
	ans_last -> next = pivot -> next;
	return ans -> next;
}

int main(int argc, char const *argv[])
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);

	d.next = &a;
	a.next = &b;
	b.next = &c;

	ListNode *res = partition(&a, 2);
	while(res){
		cout << res -> val << " ";
		res = res -> next;
	}
	return 0;
}