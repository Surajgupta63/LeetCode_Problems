// T.C : O(n)
// S.C : O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* tail = prev;

        while(head && tail){
            if(head->val != tail->val) return false;
            head = head->next;
            tail = tail->next;
        }

        return true;
    }
};
