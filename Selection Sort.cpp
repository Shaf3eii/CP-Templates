void selectionSort(vector<int>& a) {
    int n = a.size(); // The correct size of the array
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {  // Loop through the array, stopping at n-1
        int min_index = i;  // Assume the current element is the smallest
        for (int j = i + 1; j < n; j++) {  // Find the minimum element in the remaining unsorted part
            if (a[j] < a[min_index]) {
                min_index = j;  // Update min_index if a smaller element is found
            }
        }
        if (i != min_index) {  // If the minimum element is not already at the correct position
            swap(a[i], a[min_index]);  // Swap the elements
            ++swaps;  // Increment the swap count
        }
    }
    
    // Print the sorted array
    for (int i = 0; i < n; i++) { 
        if (i > 0) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    
    // Print the number of swaps
    cout << swaps << '\n';
}
