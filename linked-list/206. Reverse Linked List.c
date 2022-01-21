/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stddef.h>
// #include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};
// typedef struct ListNode ListNode;

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL){return head;}
    struct ListNode* tmp = head->next;
    head->next = NULL;
    while (tmp != NULL){
        struct ListNode* tmp2 = tmp->next;
        tmp->next = head;
        head = tmp;
        tmp = tmp2;
    }
    return head;

}

int main(){
    printf("Helloworld!");
    int a = 1;
    int *b = &a;
    int **c = &b;
    printf("Helloworld2!");
    struct ListNode *start = NULL;
    // struct ListNode *thenext = NULL;
    // start->val = 1;
    // start->next = NULL;
    // start->next = thenext;
    // start = start->next;
    // start->val = 2;

    start = reverseList(start);
    // struct ListNode head = ListNode{1,ListNode{2,NULL}};
    // reverseList(head);

return 0;}

