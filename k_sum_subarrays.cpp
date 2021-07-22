/*
	Evaluates total sub arrays having sum k
	if k == 0, gives zero sum subarrays

*/

int solve(vector<int> &arr, int k) {
    map<int, int> mp;
    int ans = 0, sum = 0;
    for(int i = 0;i<arr.size();i++) {
        if(arr[i]==b)
            sum++;
        else if (arr[i]==c)
            sum--;
        if(sum==k)
            ans++;
        if(mp.find(sum - k) != mp.end()) {
            ans = ans + mp[sum - k];
        }
        mp[sum]++;
    }
    return ans;
}
