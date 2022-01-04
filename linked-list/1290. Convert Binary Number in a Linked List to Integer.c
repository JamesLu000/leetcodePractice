/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    int tmp[32];
    int tlen = 0;
    int ans = 0;
    while(head){
        tmp[tlen] = head->val;
        head = head->next;
        tlen++;
    };
    for(int i=0 ; i< tlen;i++){
        ans += tmp[i]*pow(2,tlen-i-1);
    };
    return ans;

}