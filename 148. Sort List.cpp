/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeList(ListNode* thisList, ListNode* anotherList) {
        if (thisList == NULL)  {
            return anotherList;
        }
        if (anotherList == NULL) {
            return thisList;
        }
        
        ListNode* newHead = NULL;
        if (thisList->val < anotherList->val) {
            newHead = thisList;
            thisList = thisList->next;
        }
        else {
            newHead = anotherList;
            anotherList = anotherList->next;
        }
        
        auto tempHead = newHead;        
        while (thisList && anotherList) {
            if (thisList->val < anotherList->val) {
                tempHead->next = thisList;
                thisList = thisList->next;
            }
            else {
                tempHead->next = anotherList;
                anotherList = anotherList->next;
            }
            tempHead = tempHead->next;
        }
        
        if (thisList != NULL){
            tempHead->next = thisList;
        }
        else if (anotherList != NULL) {
             tempHead->next = anotherList;
        } 
        else {
            ;
        }
        
        return newHead;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }    
        
        auto fastNode = head;
        auto slowNode = head;
        while (fastNode->next != NULL && fastNode->next->next != NULL) {
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
        }
        auto middleNode = slowNode->next;
        slowNode->next = NULL;
       
        head = sortList(head);
        middleNode = sortList(middleNode);
        return mergeList(head, middleNode);
    }
};