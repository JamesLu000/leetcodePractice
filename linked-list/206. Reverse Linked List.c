/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


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