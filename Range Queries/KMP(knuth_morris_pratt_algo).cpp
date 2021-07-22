/** KMP Algo (Knuth–Morris–Pratt Algo)
* pattern = needle
* str = haystack
*/
        string pattern, str;
        n = pattern.size(), m = str.size();
        vector<int> lps(n, 0);

        // 1. Finding LPS
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && pattern[i] != pattern[j])
                j = lps[j - 1];
            if (pattern[i] == pattern[j])
                j++;
            lps[i] = j;
        }

        // 2. KMP algo
        int i = 0, j = 0;
        while (i < m) {
            if (str[i] == pattern[j]) {
                i++, j++;
                if (j == n)
                    cout << i - j << '\n';
            } else if (i < m && str[i] != pattern[j]) {
                if (j > 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
