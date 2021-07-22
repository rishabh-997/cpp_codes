// create a structure
struct st {
    ll node;
    ll offers;
    ll dist;
};

// comparator to reverse priority queue
struct compare {
    bool operator()(st one, st two) {
        return one.dist > two.dist;
    }
};

// declaration
priority_queue<st, vector<st>, compare> pq;
        
