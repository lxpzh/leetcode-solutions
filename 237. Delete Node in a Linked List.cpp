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
    void deleteNode(ListNode* node) {
        auto preNode = node;
        node = node->next;
        preNode->val = node->val;
        preNode->next = node->next;
       
        delete node;
    }
};