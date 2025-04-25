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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head,*fast = head;
        bool flg = false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                flg = true;
                break;
            }
        }
        if(flg){
            slow = head;
            while(fast){
                if(slow == fast){
                    return slow;
                }
                slow = slow->next;
                fast = fast->next;
            }
        }
        return nullptr;
    }
};