// *******ADD TWO NUMBERS********* //

/* You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1: 
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.


Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints: 
- The number of nodes in each linked list is in the range [1, 100].
- 0 <= Node.val <= 9
- It is guaranteed that the list represents a number that does not have leading zeros.

 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int sum = 0;
    int car = 0;
    struct ListNode* result = malloc(sizeof(struct ListNode));
    struct ListNode* temp = result;  
    
    
    //note: while(x) has same meaning as while(x!=0)//
    while(l1 || l2) {
        sum = car + (l1? l1->val: 0) + (l2? l2->val: 0);
        car = sum/10;
        sum %= 10;
        temp->val = sum;
        l1 = l1? l1->next: NULL;
        l2 = l2? l2->next: NULL;
        if(l1 || l2) {
            temp->next = malloc(sizeof(struct ListNode));
            temp = temp->next;    
        }
        else if(car) {
            temp->next = malloc(sizeof(struct ListNode));
            temp = temp->next;
            temp->val = car;
        }
    }
    temp->next = NULL;
    
    return result; 
}
