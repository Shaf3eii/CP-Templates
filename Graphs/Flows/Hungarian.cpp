const int INF = 1e18;

// Hungarian Algorithm: Solves the Minimum Cost Bipartite Matching (Assignment Problem) in O(N^3)
// Returns: {Minimum Total Cost, Vector of {Worker, Job} assignments}
pair<int, vector<pair<int, int>>> hungarianAlgorithm(const vector<vector<int>>& cost) {
    int n = cost.size();
    
    // u: Potentials for rows (workers)
    // v: Potentials for columns (jobs)
    vector<int> u(n + 1, 0), v(n + 1, 0); 
    
    // p: The matching array. p[j] stores the worker assigned to job j.
    // way: The "breadcrumb" array. way[j] stores the previous column in the augmenting path.
    vector<int> p(n + 1, 0), way(n + 1, 0);

    // Outer loop: Try to find a job for each worker 'i' one by one
    for (int i = 1; i <= n; i++) {
        // minv[j]: The minimum delta needed to make an edge to job j "rigid" (u[i] + v[j] == cost[i][j])
        vector<int> minv(n + 1, INF);
        vector<bool> used(n + 1, false); // Tracks which jobs we have visited in the current search
        
        int j0 = 0; // j0 is our current column. We start at the "dummy" column 0.
        p[0] = i;   // Place our new worker 'i' in the dummy column to start the search.

        // Search for an alternating augmenting path
        do {
            used[j0] = true;          // Mark current job column as visited
            int i0 = p[j0], j1 = 0;   // i0 is the worker currently assigned to job j0
            int delta = INF;          // The smallest cost difference to create a new rigid edge

            // Look at all jobs to find the closest rigid edge
            for (int j = 1; j <= n; j++) {
                if (!used[j]) {
                    // cur: How far is worker i0 from being able to take job j?
                    // (cost[i0-1][j-1] maps the 1-based algorithm to the 0-based input matrix)
                    int cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                    
                    // Update minv if we found a cheaper way to reach job j
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0; // Remember that we reached job j from job j0
                    }
                    
                    // Track the absolute smallest delta across all unvisited jobs
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j; // j1 is the next job column we will visit
                    }
                }
            }

            // Shift the potentials by 'delta' to force a new rigid edge to appear
            for (int j = 0; j <= n; j++) {
                if (used[j]) {
                    // If visited, shift potentials to maintain existing rigid edges
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    // If unvisited, they are now 'delta' closer to becoming rigid
                    minv[j] -= delta;
                }
            }

            // Move to the next column in our augmenting path
            j0 = j1;
            
        // Stop when we reach a column p[j0] == 0 (meaning we found a job that is completely empty!)
        } while (p[j0] != 0);

        // We found an augmenting path ending at empty job j0.
        // Backtrack using the 'way' array to flip the assignments and lock worker 'i' in.
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    // Extract the final assignments (1-based indexing)
    vector<pair<int, int>> assignment;
    for (int j = 1; j <= n; j++)
        if (p[j])
            assignment.emplace_back(p[j], j);

    // Because of the dummy column 0, -v[0] magically holds the exact total minimum cost
    return {-v[0], assignment};
}