struct coordinate_compression {
private:
    vector<long long> comp; // A vector to store the unique, sorted elements for compression.

    // A private method to perform compression by sorting and removing duplicates.
    void compress() {
        sort(comp.begin(), comp.end()); // Sort the vector to arrange elements in ascending order.
        comp.erase(unique(comp.begin(), comp.end()), comp.end()); // Remove duplicates to keep only unique elements.
    }

public:
    // Constructor that initializes the compression vector with the input and compresses it.
    coordinate_compression(vector<long long> & v) {
        comp = v; // Copy the input vector to the internal 'comp' vector.
        compress(); // Call the compress function to sort and remove duplicates.
    }

    // Method to get the compressed index of a given value.
    int get_index(long long val) {
        return lower_bound(comp.begin(), comp.end(), val) - comp.begin(); 
        // Finds the position where 'val' fits in the sorted 'comp' vector.
        // Subtracting comp.begin() gives the zero-based index of 'val'.
        // If a 1-based index is needed, add +1 to the result.
    }

    // Method to get the original value from the compressed index.
    int get_origin(size_t idx) {
        return comp[idx]; // Returns the original value corresponding to the given index in the compressed vector.
    }
};
