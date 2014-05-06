#include <iostream>
#include "list_util.h"

using namespace std;

ListNode *build_list(int *a, int n)
{
	ListNode *head = new ListNode(a[0]);
	ListNode *current = head;
	for (int i = 1; i < n; i++) {
		ListNode *node = new ListNode(a[i]);
		current->next = node;
		current = current->next;
	}

	return head;
}

void traverse_list(ListNode *head)
{
	ListNode *node = head;

	while (node) {
		cout << node->val << " ";
		node = node->next;
	}

	cout << endl;
}

void destroy_list(ListNode *head)
{
	while (head) {
		ListNode *node = head->next;
		delete head;
		head = node;
	}
}
