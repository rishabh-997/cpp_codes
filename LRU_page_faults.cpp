/*
	We are given total possible page numbers that can be referred. 
	We are also given cache size. The LRU caching scheme is to 
	remove the least recently used frame when the cache 
	is full and a new page is referenced which is not there in cache. 
*/


class LRUCache {
    int pageFaults(int n, int c, int arr[]) {
        int ans = 0;
        set<int> st;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (st.size() < c) {
                if (st.find(arr[i]) == st.end()) {
                    st.insert(arr[i]);
                    ans++;
                }
                mp[arr[i]] = i;
            } else {
                if (st.find(arr[i]) == st.end()) {
                    int temp = INT_MAX;
                    int value = 0;
                    auto it = st.begin();
                    while (it != st.end()) {
                        if (mp[*it] < temp) {
                            temp = mp[*it];
                            value = *it;
                        }
                        it++;
                    }
                    st.erase(value);
                    st.insert(arr[i]);
                    ans++;
                }
                mp[arr[i]] = i;
            }
        }
        return ans;
    }   
};

