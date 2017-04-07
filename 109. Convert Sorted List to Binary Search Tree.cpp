/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  
class Solution {
public:
    TreeNode* sortedArrayToBST(const vector<int>& nums, int left, int right)
    {
        if (left >  right) {
            return NULL;
        } else {
            int mid = (left + right) / 2;
 
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = sortedArrayToBST(nums, left, mid - 1);
            node->right = sortedArrayToBST(nums, mid + 1, right);
           
            return node;
        }
    }
     
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if (nums.empty()) {
            return NULL;
        }
   
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> ivec;
  
        while (head) {
            ivec.push_back(head->val);
            head = head->next;
        }
        
        return sortedArrayToBST(ivec);
    }
};