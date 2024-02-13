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
  		ListNode *tail = reverseList(head->next);//�����ݹ鵽����β�ڵ�
		head->next->next = head;//��һ���ڵ�ָ��ǰһ���ڵ�
		head->next = nullptr;
  		return tail;
    }
};
