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
    ListNode* deleteDuplication(ListNode* head) {
		auto *dummy = new ListNode(-1);
		dummy->next = head;

		auto *p = dummy;
		while(p->next){
			auto q = p->next;
			while(q && p->next->val == q->val) q = q->next;
			if(q == p->next->next) p = p->next;
			else
				p->next = q;
		}
		return dummy->next;
    }
};
