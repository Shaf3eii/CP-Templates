int inversions(int l, int mid, int r, vector<int>& arr) {
    int n1 = mid - l;
    int n2 = r - mid;
 
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; ++i) left[i] = arr[l + i];
    for (int i = 0; i < n2; ++i) right[i] = arr[mid + i];
 
    int i = 0, j = 0;
    int idx = l;
    int cnt = 0;
 
    while (i < n1 and j < n2) {
        if (left[i] <= right[j]) {
            arr[idx++] = left[i++];
        } else {
            arr[idx++] = right[j++];
            cnt += n1 - i;
        }
    }
 
    while (i < n1) arr[idx++] = left[i++];
    while (j < n2) arr[idx++] = right[j++];
 
    return cnt;
}
 
int countInversions(int l, int r, vector<int>& arr) {
    if (r - l <= 1) return 0;
 
    int mid = l + (r - l) / 2;
    int left = countInversions(l, mid, arr);
    int right = countInversions(mid, r, arr);
    return left + right + inversions(l, mid, r, arr);
}
