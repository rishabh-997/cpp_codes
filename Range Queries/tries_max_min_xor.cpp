#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);

struct node {
    node *child[2];
    int freq;

    node() {
        freq = 0;
        for (auto &i : child)
            i = nullptr;
    }
};

node *root;

void insert(ll a) {
    node *temp = root;
    for (ll i = 30; i >= 0; i--) {
        if (a & (1 << i)) {
            if (temp->child[1] == nullptr) {
                node *te = new node();
                temp->child[1] = te;
            }
            temp = temp->child[1];
            temp->freq++;
        } else {
            if (temp->child[0] == nullptr) {
                node *te = new node();
                temp->child[0] = te;
            }
            temp = temp->child[0];
            temp->freq++;
        }
    }
}

ll evaluate(ll a) {
    node *temp = root;
    ll ans = 0;
    for (ll i = 30; i >= 0; i--) {
        if (a & (1 << i)) {
            if (temp->child[0] != nullptr) {
                ans = ans + (1 << i);
                temp = temp->child[0];
            } else if (temp->child[1] != nullptr) {
                temp = temp->child[1];
            } else {
                break;
            }
        } else {
            if (temp->child[1] != nullptr) {
                ans = ans + (1 << i);
                temp = temp->child[1];
            } else if (temp->child[0] != nullptr) {
                temp = temp->child[0];
            } else {
                break;
            }
        }
    }
    return ans;
}

int main() {
    fastRead()
    ll n, q, a;
    cin >> n;
    root = new node();
    for (ll i = 0; i < n; i++) {
        cin >> a;
        insert(a);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a;
        cout << evaluate(a) << "\n";
    }
    return EXIT_SUCCESS;
}
