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
    ListNode* swapPairs(ListNode* head) {
        if (!head) {
            return NULL;
        } 
        else if (!head->next) {
                return head;
        }
        else {
            ListNode *newHead = head->next;
            auto node = head;
            
            ListNode* preNode = node;
            while (node && node->next) {
                auto nextNode = node->next;
                preNode->next = nextNode;
                
                node->next = nextNode->next;
                nextNode->next = node;
                preNode = node;
                node = node->next;
            }
            
            return newHead;
        }
    }
};