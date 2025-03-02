// T.C : O(n)
// S.C : O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        unordered_map<ListNode*, int> mp;

        ListNode* temp = head;
        while(temp){
            mp[temp]++;
            if(mp[temp] > 1){
                return temp;
            }
            temp = temp->next;
        }

        return NULL;
    }
};
