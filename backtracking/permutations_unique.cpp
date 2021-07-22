// permutatons in case of repitions

    void perm(vector<vector<int>> &ans, vector<int> &a, vector<bool> &taken, vector<int> &nums) {
        
        if (i == nums.size() - 1) {
            ans.push_back(a);
            return;
        }

        int lastElement;
        bool initialized = false;
        for (int i = 0; i < nums.size(); i++) {
            if (initialized && nums[i] == lastElement) {
                continue;
            }
            if (!taken[i]) {
                taken[i] = true;
                a.push_back(nums[i]);
                perm(ans, a, taken, nums);
                a.pop_back();
                taken[i] = false;
                lastElement = nums[i];
                initialized = true;
            }
        }

    }
