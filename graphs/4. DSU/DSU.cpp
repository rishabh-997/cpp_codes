/**
* Disjoin set union
* to combine two node (a, b): 		union_set(a, b);
* to find no. of nodes of a: 		rnk[find_set(a)];
*/


	typedef long long ll;

	ll par[100005]; // representative element of set
	ll rnk[100005]; // no of elements in set

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

