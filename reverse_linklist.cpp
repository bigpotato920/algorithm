#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (!head || m == n)
        return head;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *worker = &dummy;
    
    
    for (int i = 1; i < m; i++)
        worker = worker->next;
    ListNode *pre = worker->next;
    ListNode *cur = pre->next;
    
    for (; m < n; m++) {
        pre->next = cur->next;
        cur->next = worker->next;
        worker->next = cur;
        cur = pre->next;
    }
    
    return dummy.next;    
}

int main(int argc, char const *argv[])
{
	ListNode a(3);
	ListNode b(5);

	a.next = &b;

	reverseBetween(&a, 1, 2);
	return 0;
}