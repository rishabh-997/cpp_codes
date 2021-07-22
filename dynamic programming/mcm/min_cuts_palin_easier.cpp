
bool isPalindrome(string A) {
    int left = 0;
    int right = A.size()-1;
    while(left < right) {
        if(A[left] != A[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int Solution::minCut(string A) {
    
    int n = A.size();
    vector<int> result(n+1);
    result[n] = -1;
    for(int i=n-1;i>=0;i--) {
        result[i] = n-i-1;
        for(int j=i;j<n;j++) {
            if(isPalindrome(A.substr(i, j-i+1))) {
                result[i] = min(result[i], 1 + result[j+1]);
            }
        }
    }
    return result[0];
}
