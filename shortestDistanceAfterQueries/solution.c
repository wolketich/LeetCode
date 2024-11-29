#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N 500
#define INF INT_MAX

// Node structure for adjacency list
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Add an edge to the graph
void addEdge(Node** graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = graph[src];
    graph[src] = newNode;
}

// BFS to find shortest path from src to dest
int bfs(Node** graph, int n, int src, int dest) {
    int dist[MAX_N];
    for (int i = 0; i < n; i++) dist[i] = INF; // Initialize distances
    dist[src] = 0;

    int queue[MAX_N], front = 0, back = 0;
    queue[back++] = src;

    while (front < back) {
        int current = queue[front++];
        Node* temp = graph[current];

        while (temp) {
            int neighbor = temp->dest;
            if (dist[neighbor] == INF) {
                dist[neighbor] = dist[current] + 1;
                queue[back++] = neighbor;
            }
            temp = temp->next;
        }
    }

    return dist[dest];
}

// Main function to compute shortest distances after queries
int* shortestDistanceAfterQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    Node* graph[MAX_N] = {NULL};

    // Initialize the graph with roads from i to i+1
    for (int i = 0; i < n - 1; i++) {
        addEdge(graph, i, i + 1);
    }

    int* result = (int*)malloc(queriesSize * sizeof(int));
    if (!result) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < queriesSize; i++) {
        int u = queries[i][0];
        int v = queries[i][1];

        addEdge(graph, u, v); // Add the new road
        result[i] = bfs(graph, n, 0, n - 1); // Compute shortest path
    }

    *returnSize = queriesSize;
    return result;
}

