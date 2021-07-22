/*
arr = {7,2,6,5};
target = 16
ans = 	(2 2 2 2 2 2 2 2)
	(2 2 2 2 2 6)
	(2 2 2 5 5)
	(2 2 5 7)
	(2 2 6 6)
	(2 7 7)
	(5 5 6)
*/

    void f(vector<vector<int> > &ans, vector<int> &temp, vector<int> &arr, int target, int pos) {
        if(sum(temp)==target) {
            ans.push_back(temp);
            return;
        }
        if(sum(temp)>target)
            return;
        for(int i = pos;i<arr.size();i++) {
            temp.push_back(arr[i]);
            f(ans, temp, arr, target, i);
            temp.pop_back();
        }
    }
