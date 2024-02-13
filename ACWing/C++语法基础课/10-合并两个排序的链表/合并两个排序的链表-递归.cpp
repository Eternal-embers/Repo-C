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
    ListNode* merge(ListNode* l1, ListNode* l2) {
		if(!l1) return l2;
		if(!l2) return l1;
		if(l1->val <= l2->val){
			l1->next = merge(l1->next,l2);
			return l1;
		} else{
			l2->next = merge(l1,l2->next);
			return l2;
		}
    }
};
