// Maximum possible string using atmost k swaps   

   void backtrack (string &s, string &ans, int k, int pos) {
        if(k==0 || pos == s.length())
            return;
        int index = pos;
        for(int i = pos+1;i<s.length();i++) {
            if(s[i]>s[index])
                index = i;
        }
        if(index != pos) {
            char c = s[index];
            for(int i = pos + 1;i<s.length();i++) {
                if(s[i]==c) {
                    swap(s[i], s[pos]);
                    if(s>ans) {
                        ans = s;
                    }
                    backtrack(s, ans, k-1, pos+1);
                    swap(s[i], s[pos]);
                }
            }
        } else {
            backtrack(s, ans, k, pos+1);
        }
    }
