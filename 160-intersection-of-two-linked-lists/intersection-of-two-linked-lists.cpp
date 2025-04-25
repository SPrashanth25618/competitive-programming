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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int len1 = 0, len2 = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while (temp1) {
            len1++;
            temp1 = temp1->next;
        }
        while (temp2) {
            len2++;
            temp2 = temp2->next;
        }
        if (len1 > len2) {
            int dis = len1 - len2;
            temp1 = headA;
            while (dis--) {
                temp1 = temp1->next;
            }
            temp2 = headB;
            while (temp1 && temp2) {
                if (temp1 == temp2)
                    return temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        else{
            int dis = len2 - len1;
            temp2 = headB;
            while (dis--) {
                temp2 = temp2->next;
            }
            temp1 = headA;
            while (temp1 && temp2) {
                if (temp1 == temp2)
                    return temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return nullptr;
    }
};