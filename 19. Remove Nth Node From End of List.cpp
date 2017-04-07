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
    struct Compare{
        bool operator()(ListNode* list1, ListNode* list2) {
            return (list1-> val > list2->val);
        }
    };
        
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, Compare> q;
        for (auto const list : lists) {
            if (list != NULL) {
                q.push(list);
            }
        }
        
        ListNode* head = new ListNode(-1);
        auto node = head;
        while (!q.empty()) {
            node->next = q.top();
            node = node->next;
            q.pop();
            if (node->next) {
                q.push(node->next);
            }
        }
        
        return head->next;
    }
};