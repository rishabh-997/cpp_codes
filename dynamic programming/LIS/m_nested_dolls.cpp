#include <bits/stdc++.h>
 
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
 
bool myComparison(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}
 
int main() {
    fastRead()
    int t;
    cin >> t >> ws;
    //t = 1;
    while (t--) {
        ll n, w, h;
        cin >> n;
        vector<pair<ll, ll> > arr(n);
        for (int i = 0; i < n; i++) {
            cin >> w >> h;
            arr[i] = make_pair(w, h);
        }
        sort(arr.begin(), arr.end(), myComparison);
 
        vector<pair<ll, ll> > ans;
        ans.push_back(arr[0]);
        for (int i = 1; i < n; i++) {
            ll l = 0, r = ans.size() - 1, mid;
            while (l <= r) {
                mid = (l + r) / 2;
                if (ans[mid].second <= arr[i].second)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            if (l == ans.size()) {
                ans.push_back(arr[i]);
            } else {
                ans[l] = arr[i];
            }
        }
        cout << ans.size() << "\n";
    }
    return EXIT_SUCCESS;
}
