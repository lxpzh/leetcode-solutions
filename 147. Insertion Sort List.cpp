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
    ListNode* insertionSortList(ListNode* head) {
       if(head==NULL || head->next==NULL) return head;
        ListNode *cur=head;
        ListNode *helper=new ListNode(0);
        ListNode *pre;
        while(cur)
        {
            ListNode *next=cur->next;
            pre=helper;
            while(pre->next!=NULL && pre->next->val<cur->val)
            {
                pre=pre->next;
            }
            cur->next=pre->next;
            pre->next=cur;
            cur=next;
        }
        return helper->next;
     
    }
};