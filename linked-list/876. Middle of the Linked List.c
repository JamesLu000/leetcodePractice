/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* ans = head;
    while (head != NULL){
        
        if (head->next == NULL){
            return ans;
        }
        ans = ans->next;
        head = head->next->next;
    };
    return ans;

}