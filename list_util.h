#ifndef LIST_UTIL_H
#define LIST_UTIL_H

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode *build_list(int *a, int n);

void traverse_list(ListNode *head);

void destroy_list(ListNode *head);

#endif