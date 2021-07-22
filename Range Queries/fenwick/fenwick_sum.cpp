/**
*	Fenwick Tree Sum Implementation
*	1. Create a tree
*	2. Pass sum queries
*	3. Pass update queries
*/


vector<ll> bit;

void create_bit(ll n) {
    ll par;
    for (ll i = 1; i <= n; i++) {
        par = i + (i & (-i));
        if (par <= n)
            bit[par] += bit[i];
    }
}

ll query(ll a) {
    ll ans = 0;
    while (a > 0) {
        ans += bit[a];
        a = a & (a - 1);
    }
    return ans;
}

void update(ll pos, ll value, ll n) {
    while (pos <= n) {
        bit[pos] += value;
        pos = pos + (pos & (-pos));
    }
}

