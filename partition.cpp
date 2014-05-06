#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x) {
    ListNode *less_head = new ListNode(0);
    ListNode *lp = less_head;
    ListNode *greater_head = new ListNode(0);
    ListNode *gp = greater_head;
    
    ListNode *node = head;
    
    while (node) {
        if (node->val < x) {
            lp->next = node;
            lp = lp->next;
        } else {
            gp->next = node;
            gp = gp->next;
        }
        node = node->next;
    }
    lp->next = greater_head->next;
    gp->next = NULL;
    
    head = less_head->next;
   
   	delete less_head;
   	delete greater_head;

   	return head;
}
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}