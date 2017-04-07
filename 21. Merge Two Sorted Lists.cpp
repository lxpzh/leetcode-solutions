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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        auto node = head;
        
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        } else {
            
            while (l1 && l2) {
                if (l1->val < l2->val) {
                    node->next = l1;
                    l1 = l1->next;
                } else {
                    node->next = l2;
                    l2 = l2->next;
                }
                node = node->next;
            }
 
            auto remainNode = (l1 == NULL) ? l2 : l1;
            while (remainNode != NULL) {
                node->next = remainNode;
                remainNode = remainNode->next;
                node = node->next;
            }
            
            node->next = NULL;
        }
        
        return head->next;
    }
};