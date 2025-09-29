#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Define
 */
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* init_node(int val, struct ListNode* next);
void free_ll(struct ListNode* head);
struct ListNode* init_ll_cycle(const int* const arr, const int arr_size);
struct ListNode* init_ll_no_cycle(int* arr, int arr_size);
bool hasCycle(struct ListNode* head);

/**
 * Implement functions
 */
bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        // printf("Slow %d; %p\n", slow->val, slow);
        // printf("Fast %d; %p\n", fast->val, fast);
        if (slow == fast) {
            return true;
        }
    }

    return false;
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

struct ListNode* init_node(int val, struct ListNode* next) {
    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret->val = val;
    ret->next = next;
    return ret;
}

// The last value of arr will be the loop point
struct ListNode* init_ll_cycle(const int* const arr, const int arr_size) {
    if (arr_size < 2) {
        printf("Cycle linked list require at least 2 node --> Exit\n");
        goto exit;
    }

    struct ListNode* head = init_node(arr[0], NULL);
    struct ListNode* cur = head;
    struct ListNode* loop_point = NULL;
    struct ListNode* tmp;
    if (head->val == arr[arr_size - 1]) {
        loop_point = head;
    }
    printf("Init cycle linked list: %d -> ", head->val);

    int i;
    for (i = 1; i < arr_size - 1; i++) {
        tmp = init_node(arr[i], NULL);
        cur->next = tmp;  // update tail of ll
        cur = tmp;        // curr now at the tail
        printf("%d -> ", tmp->val);
        if (tmp->val == arr[arr_size - 1]) {
            loop_point = tmp;
        }
    }

    if (loop_point == NULL) {
        printf("There no loop point. Free\n");
        free_ll(head);
        goto exit;
    }
    cur->next = loop_point;
    printf("%d\n", loop_point->val);
    printf("The loop point: %p [%d]\n", loop_point, loop_point->val);
exit:
    return head;
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

int main() {
    int arr[] = {1, 2, 1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    struct ListNode* ll = init_ll_cycle(arr, arr_size);
    // struct ListNode* ll = init_ll_no_cycle(arr, arr_size);
    printf("\n==> Result cycle check : %d\n", hasCycle(ll));

    free_ll(ll);
    return 0;
}