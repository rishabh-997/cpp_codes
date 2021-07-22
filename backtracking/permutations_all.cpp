// print all permutations by pushing and popping and keeping a visited array


    void backtrack(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, vector<bool> &vis) {
        if(temp.size()==nums.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i = 0;i<nums.size();i++) {
            if(!vis[i]) {
                vis[i] = true;
                temp.push_back(nums[i]);
                backtrack(ans, temp, nums, vis);
                vis[i] = false;
                temp.pop_back();
            }
        }
    }
