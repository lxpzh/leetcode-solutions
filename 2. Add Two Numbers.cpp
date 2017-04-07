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
    ListNode* createNode(int value) {
         ListNode* newNode = new ListNode(value);
         if (!newNode)
            exit(-1);
            
         return newNode;
    }
    
    int getRightValue(int value, int& flag) {
        if (value > 9) {
            value = value - 10;
            flag = 1;
        } else {
            flag = 0;
        }
        
        return value;
    }
    
    inline void pushBack(ListNode*& head, int value) {
          head->next = createNode(value);
          head = head->next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-123456);
        int flag = 0;
        ListNode* head = result;
        
        while (l1 != NULL && l2 != NULL) {
            int value = l1->val + l2->val + flag;
            value = getRightValue(value, flag);
            pushBack(result, value);
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode *node = (l1 == NULL) ? l2 : 
                                    ((l2 == NULL) ? l1 : NULL);
      
        while (node != NULL) {
            int value = node -> val + flag;
            value = getRightValue(value, flag);
            pushBack(result, value);
            node = node->next;
        }
         
        if (flag) {
           pushBack(result, flag);
        }
 
        return head->next;
    }
};