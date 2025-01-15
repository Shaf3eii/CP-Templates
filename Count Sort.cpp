// https://www.hackerrank.com/challenges/countingsort2/problem

void countSort(vector<int>& a) {
    // Find the maximum value in the array to define the size of the frequency array.
    int Max = *max_element(a.begin(), a.end());

    // Create a frequency array to store counts of each element in the input array.
    vector<int> freq(Max + 1, 0);

    // Count occurrences of each element in the input array.
    for(auto& i : a)
        freq[i]++;  // Increment frequency of the element i.

    // Rebuild the sorted array based on the frequencies.
    for(int i = 0, idx = 0; i < Max + 1; i++)  // Loop over the frequency array.
        while(freq[i]--)  // For each element i, place it in the original array.
            a[idx++] = i;
}
