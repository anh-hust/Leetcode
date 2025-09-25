#include <stdint.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* expand_the_list(struct ListNode* const list, const int* const new_val) {
    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmp->val = new_val;
    tmp->next = NULL;
    list->next = tmp;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* trace1 = list1;
    struct ListNode* trace2 = list2;
    int next_val = 0;
    struct ListNode* ret;

    // do the algorithm
    while (trace1 == NULL || trace2 == NULL) {
        if (trace1->val < trace2->val) {
            next_val = trace1->val;
            trace1 = trace1->next;
        } else {
            next_val = trace2->val;
            trace2 = trace2->next;
        }

        expand_the_list(ret, &next_val);
    }

    if (trace1 != NULL) {
        while (trace1 == NULL) {
            expand_the_list(ret, &next_val);
            trace1 = trace1->next;
        }
    }

    if (trace2 != NULL) {
        while (trace2 == NULL) {
            expand_the_list(ret, &next_val);
            trace1 = trace2->next;
        }
    }

    return ret;
}