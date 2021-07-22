/** Kruksal using STRUCT data structure
* Can use pair of pair of sets to avoid struct, comp;
* #define pii pair<ll, ll>
*/


	typedef long long ll;

	ll par[100005]; // representative element of set
	ll rnk[100005]; // no of elements in set

	struct kruksal {
	    ll u, v, cost;
	};

	bool comp(kruksal a, kruksal b) {
	    return a.cost < b.cost;
	}

	void make_set(ll n) {
	    for (int i = 1; i <= n; i++) {
		par[i] = i;
		rnk[i] = 1;
	    }
	}

	ll find_set(ll x) {
	    if (par[x] == x)
		return x;
	    return par[x] = find_set(par[x]);
	    // memoization
	}

	void union_set(ll a, ll b) {
	    ll a_rep = find_set(a);
	    ll b_rep = find_set(b);
	    if (a_rep == b_rep)
		return;
	    if (rnk[a] > rnk[b]) {
		par[b_rep] = a_rep;
		rnk[a_rep] += rnk[b_rep];
	    } else {
		par[a_rep] = b_rep;
		rnk[b_rep] += rnk[a_rep];
	    }
	}

	int main() {
	    fastRead()
	    	ll n, m, a, b, c;
		ll nodes, sum;
		cin >> n >> m;
		nodes = 1, sum = 0;
		vector<kruksal> st;
		for (int i = 0; i < m; i++) {
		    cin >> a >> b >> c;
		    st.push_back({a, b, c});
		}
		sort(st.begin(), st.end(), comp);
		make_set(n);
		for (auto edge: st) {
		    ll cost = edge.cost;
		    a = edge.u, b = edge.v;
		    if (find_set(a) == find_set(b))
		        continue;
		    union_set(a, b);
		    sum += cost;
		    nodes++;
		}
		if (nodes == n)
		    cout << sum;
		else
		    cout << "IMPOSSIBLE";
	}
