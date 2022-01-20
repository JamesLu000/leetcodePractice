/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapNodes(struct ListNode* head, int k){
    struct ListNode *ans = head;
    struct ListNode **llarray[100000];
    int index = 0;
    while (head != NULL){
        llarray[index] = head;
        index+=1;
        head = head->next;
    }
    k = k-1;
    for (int i = 0;i < index ; i++){printf("%i \n",(*llarray[i]));}
    int swaptmp = (*llarray[k]);
    (*llarray[k]) = (*llarray[index-k-1]);
    (*llarray[index-k-1]) = swaptmp;
    
    return ans;
}