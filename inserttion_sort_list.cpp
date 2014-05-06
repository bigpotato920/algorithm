#include <iostream>
#include "list_util.h"

using namespace std;

ListNode *find_insert_pre_node(ListNode *head, ListNode *node)
{
	while (head->next && head->next->val <= node->val && head->next != node)
		head = head->next;
	return head;
}

ListNode *insertionSortList(ListNode *head) {
	if (!head || head->next == NULL)
		return head;

	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *start = head->next;
	ListNode *start_pre = head;

	while (start) {
		cout << start->val << endl;
		ListNode *pre_node = find_insert_pre_node(dummy, start);
		if (pre_node->next == start) {
			start_pre = start_pre->next;
			start = start->next;

		} else {
			start_pre->next = start->next;
			start->next = pre_node->next;
			pre_node->next = start;
			start = start_pre->next;
		}
	}

	head = dummy->next;
	delete dummy;
	return head;
}


int main(int argc, char const *argv[])
{
	int a[] = {3,4,1};
	ListNode *head = build_list(a, 3);

	ListNode *new_head = insertionSortList(head);
	traverse_list(new_head);

	destroy_list(new_head);
	return 0;
}