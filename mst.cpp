#include <iostream>
#include <cstring> // For memset
#define HIGH 99999 // Represents a very large value (infinity)
using namespace std;

class graph {
    int g[10][10], n;             // Adjacency matrix and number of vertices
    int v_array[10];              // Visited array
    string dept[10];              // Department names

public:
    // Initialize graph
    void initialize() {
        cout << "\nEnter total departments: ";
        cin >> n;
        cout << "\nEnter department names:\n";
        for (int i = 0; i < n; i++) {
            cin >> dept[i];
        }

        cout << "\nEnter distances between departments:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "Distance between " << dept[i] << " and " << dept[j] << ": ";
                cin >> g[i][j];
            }
        }
    }

    // Display adjacency matrix
    void display() {
        cout << "\nAdjacency Matrix:\n";
        cout << "  ";
        for (int i = 0; i < n; i++) {
            cout << dept[i] << "\t";
        }
        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << dept[i] << "\t";
            for (int j = 0; j < n; j++) {
                cout << g[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Prim's algorithm to find Minimum Spanning Tree (MST)
    void prims() {
        int cost = 0;                         // Total cost of MST
        memset(v_array, false, sizeof(v_array)); // Mark all vertices as unvisited
        v_array[0] = true;                    // Start from the first vertex

        cout << "\nEDGE : Weight\n";
        int n_edges = 0;                      // Number of edges in the MST

        while (n_edges < n - 1) {
            int min = HIGH;                   // Initialize minimum weight
            int r = 0, c = 0;                 // Row and column of the selected edge

            // Find the smallest edge connecting the visited and unvisited vertices
            for (int i = 0; i < n; i++) {
                if (v_array[i]) {             // Only consider visited vertices
                    for (int j = 0; j < n; j++) {
                        if (!v_array[j] && g[i][j] && g[i][j] < min) {
                            min = g[i][j];
                            r = i;
                            c = j;
                        }
                    }
                }
            }

            // Include this edge in the MST
            cout << dept[r] << " - " << dept[c] << " : " << g[r][c] << endl;
            cost += g[r][c];                  // Add edge cost to total cost
            v_array[c] = true;                // Mark the vertex as visited
            n_edges++;                        // Increment the edge count
        }

        cout << "\nCost of Minimum Spanning Tree using Prim's: " << cost << endl;
    }
};

int main() {
    graph g;
    g.initialize();
    g.display();
    g.prims();

    return 0;
}
