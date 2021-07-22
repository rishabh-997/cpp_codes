node* quick(node *head, node *tail) {
    if(head==tail || head==nullptr) {
        return head;
    } 
    node *pivot = head;
    node *prev = head;
    node *temp = head->next;
    node *a = head, *b = head;
    while(temp!=nullptr) {
        if(temp->data < pivot->data) {
            prev->next = temp->next;
            temp->next = a;
            a = temp;
            temp = prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    
    b = pivot->next;
    pivot->next = nullptr;
    a = quick(a, pivot);
    b = quick(b, tail);
    
    node *last = a;
    while(last->next) 
        last = last->next;
    last->next = b;
    return a;
}

void quickSort(struct node **hr) {
    node *head = *hr;
    node *tail = *hr;
    while(tail->next)   
        tail = tail->next;
    *hr = quick(head, tail);
}



