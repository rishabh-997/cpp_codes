#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);

typedef long long ll;
const ll mod = 1e9 + 7;

ll MUL(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

ll ADD(ll a, ll b) {
    return ((a % mod) + (b % mod)) % mod;
}

ll findOptimal(map<ll, ll> &mp, ll value) {
    auto it = mp.lower_bound(value);
    if (it == mp.begin())
        return 0;
    it--;
    return it->second;
}

void insertInMap(map<ll, ll> &mp, ll value, ll dp) {
    if (mp[value] >= dp)
        return;
    mp[value] = dp;
    auto it = mp.find(value);
    it++;
    while (it != mp.end() && it->second <= dp) {
        auto temp = it;
        it++;
        mp.erase(temp);
    }
}

int main() {
    fastRead()
    int t;
    //cin >> t >> ws;
    t = 1;
    while (t--) {
        ll n;
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        map<ll, ll> mp;
        vector<ll> dp(n, 0);
        dp[0] = 1;
        mp.insert(make_pair(arr[0], dp[0]));
        for (int i = 1; i < n; i++) {
            dp[i] = 1 + findOptimal(mp, arr[i]);
            insertInMap(mp, arr[i], dp[i]);
        }
        ll ans = 0;
        for (auto x:dp)
            ans = max(ans, x);
        cout << ans;
    }
    return EXIT_SUCCESS;
}
