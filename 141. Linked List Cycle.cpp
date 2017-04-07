class Solution {
public:
    //use two pointers;
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        else {
           auto node1 = head;
           auto node2 = head;
        
            while (node1->next && node2->next->next) {
                node1 = node1->next;
                node2 = node2->next->next;
                if (node1 == node2) {
                    return true;
                }
            }
        
            return  false;
        }
    }
};