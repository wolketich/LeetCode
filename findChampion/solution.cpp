class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        unordered_map<int, unordered_set<int>> graph;

        // Build the graph and calculate in-degrees
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].insert(v);
            inDegree[v]++;
        }

        // Find the node with no incoming edges
        int champion = -1;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                if (champion != -1) {
                    return -1; // More than one node with no incoming edges
                }
                champion = i;
            }
        }

        // If no node with zero in-degree is found, return -1
        if (champion == -1) {
            return -1;
        }

        // Check if the "champion" can reach all other nodes
        unordered_set<int> visited;
        queue<int> q;
        q.push(champion);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            if (visited.count(current)) continue;

            visited.insert(current);
            for (const auto& neighbor : graph[current]) {
                if (!visited.count(neighbor)) {
                    q.push(neighbor);
                }
            }
        }

        // If the number of visited nodes is not equal to n, return -1
        if (visited.size() != n) {
            return -1;
        }

        return champion;
    }
};
