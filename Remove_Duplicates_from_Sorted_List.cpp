#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head) {
    ListNode *p = head;
    if(p == NULL){
        return head;
    }
    ListNode *q = p -> next;
    while( q != NULL){
        if(p -> val == q -> val){
            p -> next = q -> next;
            q = q -> next;
        } else {
            p = p -> next;
            q = q -> next;
        }
        
    }
    return head;

}

int main(int argc, char const *argv[])
{
    ListNode a(1);
    ListNode b(1);
    ListNode c(1);
    ListNode d(2);
    ListNode e(2);
    ListNode f(2);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    ListNode *res = deleteDuplicates(&a);

    while(res != NULL){
        cout << res -> val << endl;
        res = res -> next;
    }
    return 0;
}