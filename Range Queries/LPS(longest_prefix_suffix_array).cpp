/** Finding LPS (Longest Prefix Suffix Array)
* pattern = needle
* str = haystack
*/

        n = pattern.size(), m = str.size();
        vector<int> lps(n, 0);
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && pattern[i] != pattern[j])
                j = lps[j - 1];
            if (pattern[i] == pattern[j])
                j++;
            lps[i] = j;
        }

