void insertionSort(vector<int>& a) {
    int n = (int)a.size();  
    
    // Loop through the array starting from the second element
    for (int i = 1; i < n; i++) {
        int x = a[i];      // The element to be inserted
        int j = i - 1;
        
        // Shift elements that are greater than 'x' to the right
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        
        // Insert the element 'x' at its correct position
        a[j + 1] = x;
    }
    
    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";  
    }
    cout << endl; 
}
