/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode Stack_Node; //定義堆疊中節點的新形態
typedef Stack_Node *Linked_Stack;  //定義串列堆疊的新形態
Linked_Stack fst = NULL; //指向堆疊頂端的指標 
Linked_Stack sec = NULL;
Linked_Stack ans = NULL;
int isEmpty(Linked_Stack*);
void push(int, Linked_Stack*); 
int pop(Linked_Stack*);

/*判斷是否為空堆疊*/
int isEmpty(Linked_Stack* stack){
	if(*stack==NULL){
		return 1; 
	}else{
		return 0;
	}
} 
/*將指定的資料存入堆疊*/
void push(int val, Linked_Stack* stack){
	Linked_Stack new_add_node;  //新加入節點的指標
	/*配置新節點的記憶體*/
	new_add_node=(Linked_Stack)malloc(sizeof(Stack_Node));
	new_add_node->val=val;  //將傳入的值設為節點的內容 
	new_add_node->next=*stack;   //將新節點指向堆疊的點端 
	*stack=new_add_node;  //新節點成為堆疊的頂端 
} 
/*從堆疊取出資料*/
int pop(Linked_Stack* stack){
	Linked_Stack ptr;  //指向堆疊頂端的指標
	int temp;
	if(isEmpty(stack)){
		// printf("堆疊為空\n");
		return 0;
	}else{
		ptr=*stack;  //指向堆疊的頂端
        // printf("%p\n",*stack);
		temp=ptr->val; //取出堆疊資料
		*stack=(*stack)->next; //將堆疊頂端的指標指向下一個節點 
		free(ptr); //將節點占用的記憶體釋放
		return temp; 
	}
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (l1->val == 0){return l2;}
    if (l2->val == 0){return l1;}
    free(ans);
    Linked_Stack ans = NULL;

    while (l1 != NULL){
        push(l1->val, &fst);
        l1 = l1->next;
    }
    while (l2 != NULL){
        push(l2->val, &sec);
        l2 = l2->next;
    }
    // Linked_Stack top=NULL;
    int carry = 0;
    int nodeVal = 0;
	while (!isEmpty(&fst) || !isEmpty(&sec)){
        // int l1val = pop(&fst);
        // int l2val = pop(&sec);
		nodeVal = pop(&fst)+pop(&sec);
        // nodeVal = l1val+l2val;
        if (nodeVal+carry >= 10){
            // printf("l1 %i l2 %i %i %i\n",l1val,l2val,nodeVal,carry);
            nodeVal -= 10;
            push(nodeVal+carry,&ans);
            carry = 0;
            carry += 1;
            nodeVal = 0;
        }
        else {
            push(nodeVal+carry,&ans);
            // printf("l1 %i l2 %i %i %i\n",l1val,l2val,nodeVal,carry);
            carry = 0;
            nodeVal = 0;
        }
	}
    if (carry == 1){push(carry,&ans);}
	return ans;
}
