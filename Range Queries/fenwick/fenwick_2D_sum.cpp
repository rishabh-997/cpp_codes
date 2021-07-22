// 2D BIT

void update_bit(ll x, ll y, int delta, vector<vector<ll> > &bit) {
    while (x <= n) {
        ll y_temp = y;
        while (y_temp <= n) {
            bit[x][y_temp] += delta;
            y_temp = y_temp + (y_temp & (-y_temp));
        }
        x = x + (x & (-x));
    }
}

ll sum_query(ll x, ll y, vector<vector<ll> > &bit) {
    ll ans = 0;
    while (x > 0) {
        ll ytemp = y;
        while (ytemp > 0) {
            ans += bit[x][ytemp];
            ytemp = ytemp & (ytemp - 1);
        }
        x = x & (x - 1);
    }
    return ans;
}

