ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev = nullptr, *cur = head, *next = nullptr;
        int cunt = 0;
        while(cur!=nullptr && cunt<k) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            cunt++;
        }
        if(cunt!=k) {
            cur = prev;
            prev = nullptr, next = nullptr;
            while(cur!=nullptr) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
        }
        if(next!=nullptr) 
            head->next = reverseKGroup(next, k);
        return prev;
    }
