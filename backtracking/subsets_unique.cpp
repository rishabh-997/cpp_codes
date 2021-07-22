void backtrack(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int pos) {
        ans.push_back(temp);
        if (pos == nums.size())
            return;
        for (int i = pos; i < nums.size(); i++) {
            if(i==pos || nums[i]!=nums[i-1]) {
                temp.push_back(nums[i]);
                backtrack(ans, temp, nums, i + 1);
                temp.pop_back();
            }
        }
    }
