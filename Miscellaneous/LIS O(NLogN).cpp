int LIS(vector<int>& arr) {
    vector<int> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < arr.size(); ++i) {
        if (ans.back() < arr[i]) {
            ans.push_back(arr[i]);
        } else {
            auto it = lower_bound(begin(ans), end(ans), arr[i]) - ans.begin();
            ans[it] = arr[i];
        }
    }
    return ans.size();
}
