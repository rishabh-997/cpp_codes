Node* merge(Node *a, Node *b) {
        if(a==nullptr)
            return b;
        if(b==nullptr)
            return a;
        Node *ans = nullptr, *cur = nullptr;
        while(a!=nullptr || b!=nullptr) {
            Node *temp;
            if(a==nullptr && b!=nullptr) {
                temp = new Node(b->data);
                b = b->next;
            } else if(b==nullptr && a!=nullptr) {
                temp = new Node(a->data);
                a = a->next;
            } else {
                if(a->data < b->data) {
                    temp = new Node(a->data);
                    a = a->next;
                } else {
                    temp = new Node(b->data);
                    b = b->next;
                }
            }
            if(cur == nullptr) {
                cur = temp;
                ans = cur;
            } else {
                cur->next = temp;
                cur = cur->next;
            }
        }
        return ans;
    }
    
    Node* divide(Node *head, Node *tail) {
        if(head==tail)
            return head;
        Node *slow = head, *fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr) {
            slow = slow -> next;
            fast = fast->next -> next;
        }
        Node *a = head;
        Node *b = slow->next;
        slow->next = nullptr;
        a = divide(a, slow);
        b = divide(b, tail);
        head = merge(a, b);
        return head;
    }
    
    
    Node* mergeSort(Node* head) {
        if(head==nullptr || head->next == nullptr)
            return head;
        Node *tail = head;
        while(tail->next!=nullptr)
            tail = tail->next;
        head = divide(head, tail);
        return head;
    }
