#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n){
	ListNode *later = head;
	ListNode *earlier = head;
	while(n--){
		earlier = earlier -> next;
	}
	if(!earlier) return head -> next;
	while(earlier -> next){
		earlier = earlier -> next;
		later = later -> next;
	}
	later -> next = later -> next -> next;
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

	ListNode *res = removeNthFromEnd(&a, 2);
	while(res){
		cout << res -> val;
		res = res -> next;
	}
	return 0;
}