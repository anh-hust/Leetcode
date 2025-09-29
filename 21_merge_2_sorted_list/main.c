#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* init_node(int val, struct ListNode* next);
void print_ll(struct ListNode* head);
void free_ll(struct ListNode* head);
struct ListNode* init_ll_no_cycle(int* arr, int arr_size);

/**
 * Implement
 */
struct ListNode* init_node(int val, struct ListNode* next) {
    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret->val = val;
    ret->next = next;
    return ret;
}

void print_ll(struct ListNode* head) {
    struct ListNode* traverser = head;
    printf("The linked list [val; next]: ");
    while (traverser) {
        printf("[%d; %p] -> ", traverser->val, traverser->next);
        traverser = traverser->next;
    }
    printf("NULL\n");
}

void free_ll(struct ListNode* head) {
    struct ListNode* traverse = head;
    struct ListNode* next;
    while (traverse != NULL) {
        next = traverse->next;
        free(traverse);
        traverse = next;
    }
}

struct ListNode* init_ll_no_cycle(int* arr, int arr_size) {
    struct ListNode* head = init_node(arr[0], NULL);
    printf("Init cycle linked list: %d -> ", head->val);
    if (arr_size < 2) goto exit;
    struct ListNode* cur = head;
    struct ListNode* tmp;

    int i;
    for (i = 1; i < arr_size; i++) {
        tmp = init_node(arr[i], NULL);
        cur->next = tmp;  // update tail of ll
        cur = tmp;        // curr now at the tail
        printf("%d -> ", tmp->val);
    }

exit:
    printf("NULL\n");
    return head;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* trace1 = list1;
    struct ListNode* trace2 = list2;
    struct ListNode* ret = NULL;
    struct ListNode* traverser;

    if (list1 != NULL & list2 != NULL) {
        if (trace1->val < trace2->val) {
            ret = list1;
            traverser = list1;
            trace1 = trace1->next;
        } else {
            ret = list2;
            traverser = list2;
            trace2 = trace2->next;
        }
    } else if (list1 != NULL && list2 == NULL) {
        ret = list1;
        goto exit;
    } else if (list1 == NULL && list2 != NULL) {
        ret = list2;
        goto exit;
    } else {
        goto exit;
    }

    // do the algorithm
    while (trace1 && trace2) {
        if (trace1->val < trace2->val) {
            traverser->next = trace1;
            trace1 = trace1->next;
        } else {
            traverser->next = trace2;
            trace2 = trace2->next;
        }
        traverser = traverser->next;
    }

    if (trace1 == NULL) {
        traverser->next = trace2;
    }

    if (trace2 == NULL) {
        traverser->next = trace1;
    }

exit:
    return ret;
}

int main() {
    int arr1[] = {1, 2, 4};
    int arr1_size = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {1, 3, 4};
    int arr2_size = sizeof(arr1) / sizeof(arr2[0]);

    struct ListNode* list1 = init_ll_no_cycle(arr1, arr1_size);
    struct ListNode* list2 = init_ll_no_cycle(arr2, arr2_size);

    struct ListNode* merged = mergeTwoLists(list1, list2);

    print_ll(merged);
    free_ll(merged);
    return 0;
}