#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);

ll n;
vector<ll> arr, bit;

void create_bit() {
    ll par;
    for (ll i = 1; i <= n; i++) {
        par = i + (i & (-i));
        if (par <= n)
            bit[par] += bit[i];
    }
}

void update_bit(ll pos, ll value) {
    while (pos <= n) {
        bit[pos] += value;
        pos = pos + (pos & (-pos));
    }
}

ll sum_query(ll pos) {
    ll ans = 0;
    while (pos > 0) {
        ans += bit[pos];
        pos = pos & (pos - 1);
    }
    return ans;
}

int main() {
    fastRead()
    ll a, high, low, mid;
    cin >> n;
    arr.resize(n + 1);
    bit.resize(n + 1);
    bit.assign(bit.size(), 1);
    bit[0] = 0;
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    create_bit();
    for (ll i = 1; i <= n; i++) {
        cin >> a;
        low = 1, high = n;
        while (low + 1 < high) {
                int mid = (high + low) / 2;
                if (query(bit, n, mid) >= a)
                    high = mid;
                else
                    low = mid;
            }
        cout << arr[low] << " ";
        update_bit(low, -1);
    }


    return EXIT_SUCCESS;
}
