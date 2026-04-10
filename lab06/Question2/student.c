#include "graph.h"
// Description

// Write a function that counts how many nodes are isolated.
// A node is isolated if it has no edges connected to it.
// // The graph is stored as an adjacency matrix. 
// Graph* g is a pointer to a Graph struct, which contains a 2D array adj[MAX_NODES][MAX_NODES]. 
// The value at adj[u][v] is 1 if there is an edge between nodes u and v, and 0 otherwise.




int count_isolated(Graph* g) {
    // TODO: implement
    // return -1;
   int isolatedCount = 0;

    // Loop through each node (each row)
    for (int i = 0; i < MAX_NODES; i++) {

        int isIsolated = 1;  // Assume node is isolated

        // Check all possible connections for node i
        for (int j = 0; j < MAX_NODES; j++) {

            // If any edge exists, it's NOT isolated
            if (g->adj[i][j] == 1) {
                isIsolated = 0;
                break;  // no need to check further
            }
        }

        // If still isolated after checking row
        if (isIsolated) {
            isolatedCount++;
        }
    }

    return isolatedCount;
}















// Tip: In the adjacency matrix, that means the entire row for that node contains only 0s.
