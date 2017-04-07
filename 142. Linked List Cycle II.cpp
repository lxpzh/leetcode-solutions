142. Linked List Cycle II/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

//详解p273页 剑指offer
    ListNode* meetingNode(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode* slowNode = head->next;
        if (slowNode == NULL) {
            return NULL;
        }
        
        ListNode* fastNode = slowNode->next;
        
        while (fastNode && slowNode) {
            if (fastNode == slowNode) {
                return fastNode;
            }
            
            slowNode = slowNode->next;
            fastNode = fastNode->next;
            
            if (fastNode) {
                fastNode = fastNode->next;
            }
        }
        
        return NULL;
    }
    
    ListNode *detectCycle(ListNode *head) {
        auto meetNode = meetingNode(head);
        int cycleLength = 1;
        
        if (meetNode == NULL) {
            return NULL;
        }
        
        auto tempNode = meetNode->next;
        while (tempNode != meetNode) {
            tempNode = tempNode->next;
            ++cycleLength;
        }        
        
        auto pAhead = head;
        while (cycleLength-- ) {
            pAhead = pAhead->next;
        }
        
        auto pBehind = head;
        while (pAhead != pBehind) {
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }
        
        return pBehind;
    }
};