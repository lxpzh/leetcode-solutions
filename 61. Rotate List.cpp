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
    int getListLength(ListNode* head) 
    {
        int len = 0;
        
        while (head != NULL) {
            head = head->next;
            ++len;
        }
        
        return len;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k < 0) {
            return NULL;
        }
        
        int len = getListLength(head);
        k = k < len ? k : k % len;
        
        if (k == 0) {
            return head;
        }
        
        ListNode* fastNode  = head;
        for (int i = 0; i < k - 1; i++) {
            if (fastNode) {
                fastNode = fastNode->next;
            } 
        }
        
        ListNode* slowNode = head;
        ListNode* slowNodePre = NULL;
        while (fastNode && fastNode->next != NULL) {
            fastNode = fastNode->next;
            slowNodePre = slowNode;
            slowNode = slowNode->next;
        }
        if (slowNodePre) {
            fastNode->next = head;
            head = slowNode;
            slowNodePre->next = NULL;
        } 
        return head;
    }
};