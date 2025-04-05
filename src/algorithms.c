#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algorithms.h"

#define INF 1e9
#define EARTH_RADIUS 6371.0  // in kilometers

// Haversine formula implementation (as before)
double haversine(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * (M_PI / 180.0);
    double dLon = (lon2 - lon1) * (M_PI / 180.0);
    lat1 = lat1 * (M_PI / 180.0);
    lat2 = lat2 * (M_PI / 180.0);
    double a = sin(dLat / 2) * sin(dLat / 2) +
               sin(dLon / 2) * sin(dLon / 2) * cos(lat1) * cos(lat2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

// Dijkstra's algorithm: given a graph (2D array) and source, compute shortest distances
// graph: numNodes x numNodes matrix, source: starting node, numNodes: total nodes
// Returns an array 'dist' of size numNodes (allocated dynamically)
double* dijkstra(double **graph, int source, int numNodes) {
    double *dist = (double*) malloc(numNodes * sizeof(double));
    int *visited = (int*) malloc(numNodes * sizeof(int));
    
    // Initialize distances and visited flags
    for (int i = 0; i < numNodes; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[source] = 0;

    // Main loop of Dijkstra's algorithm
    for (int count = 0; count < numNodes - 1; count++) {
        // Find the unvisited node with the smallest distance
        int u = -1;
        double minDist = INF;
        for (int i = 0; i < numNodes; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1) break;  // All remaining nodes are inaccessible
        visited[u] = 1;
        
        // Update distance value for adjacent nodes of u.
        for (int v = 0; v < numNodes; v++) {
            if (!visited[v] && graph[u][v] < INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    free(visited);
    return dist;
}

// The new function that builds the graph and uses Dijkstra's algorithm
int dijkstraFindBestWarehouse(Warehouse warehouses[], int count, double productLat, double productLon) {
    int numNodes = count + 1;  // Node 0: product location, Nodes 1..count: warehouses
    double costFactor = 10.0;  // Tunable parameter for cost weighting

    // Allocate graph as a 2D array of size numNodes x numNodes
    double **graph = (double**) malloc(numNodes * sizeof(double*));
    for (int i = 0; i < numNodes; i++) {
        graph[i] = (double*) malloc(numNodes * sizeof(double));
    }

    // Initialize the graph with INF
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = INF;
        }
    }

    // Set edges from product location (node 0) to each warehouse (node i, i=1..count)
    for (int i = 1; i < numNodes; i++) {
        double directDistance = haversine(productLat, productLon, warehouses[i-1].latitude, warehouses[i-1].longitude);
        graph[0][i] = directDistance + costFactor * warehouses[i-1].costPerUnit;
        // For undirected graph (optional), set symmetric edge
        graph[i][0] = graph[0][i];
    }

    // Build edges between warehouses (nodes 1 to count)
    for (int i = 1; i < numNodes; i++) {
        for (int j = 1; j < numNodes; j++) {
            if (i != j) {
                graph[i][j] = haversine(warehouses[i-1].latitude, warehouses[i-1].longitude,
                                        warehouses[j-1].latitude, warehouses[j-1].longitude);
            }
        }
    }

    // Run Dijkstra's algorithm starting from node 0
    double *dist = dijkstra(graph, 0, numNodes);

    // Find the warehouse node (1 to numNodes-1) with the smallest distance
    double bestDistance = INF;
    int bestNode = -1;
    for (int i = 1; i < numNodes; i++) {
        if (dist[i] < bestDistance) {
            bestDistance = dist[i];
            bestNode = i;
        }
    }

    // Free allocated memory for graph and dist array
    for (int i = 0; i < numNodes; i++) {
        free(graph[i]);
    }
    free(graph);
    free(dist);

    // Return the index in the warehouses array corresponding to bestNode (node i corresponds to warehouses[i-1])
    return (bestNode == -1) ? -1 : (bestNode - 1);
}
