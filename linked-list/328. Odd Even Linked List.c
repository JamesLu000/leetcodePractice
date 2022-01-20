/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if (head == NULL || head->next == NULL){return head;}
    struct ListNode* ans = head;
    struct ListNode* odd = head;
    struct ListNode* evenhead = head->next;
    struct ListNode* even = evenhead;
    head = head->next->next;
    
    while (head != NULL){
        if (head->next != NULL){
            odd->next = head;
            even->next = head->next;
            head->next = head->next->next;
            odd = odd->next;
            even = even->next;
            head = head->next;
        }
        else {
            odd->next = head;
            odd = odd->next;
            break;
        }
    }
    even->next = NULL;
    odd->next = evenhead;
    return ans;
}