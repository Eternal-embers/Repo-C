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
  		ListNode *tail = reverseList(head->next);//保留递归到最后的尾节点
		head->next->next = head;//后一个节点指向前一个节点
		head->next = nullptr;
  		return tail;
    }
};
