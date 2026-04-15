vector<int> nextGreater(vector<int> &v) {
    int n = v.size();
    vector ans(n, n);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        while (!s.empty() and v[s.top()] < v[i]) {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}
 
vector<int> prevGreater(vector<int> &v) {
    int n = v.size();
    vector<int> ans(n, -1);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        while (!s.empty() and v[s.top()] <= v[i]) {
            s.pop();
        }
        if (!s.empty()) {
            ans[i] = s.top();
        }
        s.push(i);
    }
    return ans;
}
 
