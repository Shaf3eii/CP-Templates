void bubbleSort(vector<int>& a) {
    int n = (int)a.size(); 
    int swaps = 0;    // Counter for the number of swaps.
    
    // Bubble Sort implementation.
    for (int step = 1; step <= n - 1; step++) {
        for (int i = 0; i < n - step; i++) { // Adjusted condition to avoid out-of-bound access.
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                ++swaps;
            }
        }
    }
    
    // Output results.
    cout << "Array is sorted in " << swaps << " swaps.\n";
    cout << "First Element: " << a[0] << '\n';
    cout << "Last Element: " << a[n - 1] << '\n';
}
