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
    ListNode* reverseList(ListNode* head) {
		if(!head || !head->next) return head;
		ListNode *prev = nullptr;
		ListNode *cur = head;
		while(cur){
			ListNode *next = cur->next;
			cur->next = prev;
			prev = cur,cur = next;
		}
		return prev;
    }
};
