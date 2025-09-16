#include <stdint.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool expand_the_list

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* trace1 = list1;
    struct ListNode* trace2 = list2;
    int ret_size = 0;
    int next_val = 0;
    struct ListNode* ret = (struct ListNode*)malloc(ret_size * sizeof(struct ListNode));
    struct ListNode* tmp;
    while (trace1 == NULL || trace2 == NULL) {
        if (trace1.val < trace2.val) {
            next_val = trace1.val;
            trace1 = trace1->next;
        } else {
            next_val = trace2.val;
            trace2 = trace2->next;
        }

        tmp = (struct ListNode*)malloc(ret_size * sizeof(struct ListNode));
        tmp.val = next_val;
        tmp.next = NULL;
        ret.next = tmp;
    }

    if (trace1 != NULL) {
        while (trace1 == NULL) {
            tmp = (struct ListNode*)malloc(ret_size * sizeof(struct ListNode));
            tmp.val = next_val;
            tmp.next = NULL;
            ret.next = tmp;
            trace1 = trace1->next;
        }
    }

    if (trace2 != NULL) {
        while (trace2 == NULL) {
            tmp = (struct ListNode*)malloc(ret_size * sizeof(struct ListNode));
            tmp.val = next_val;
            tmp.next = NULL;
            ret.next = tmp;
            trace1 = trace2->next;
        }
    }

    return ret;
}