class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
       class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        unordered_map<int, unordered_set<int>> graph;

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].insert(v);
            inDegree[v]++;
        }

        int champion = -1;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                if (champion != -1) {
                    return -1; // More than one team with no incoming edges
                }
                champion = i;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i != champion && graph[champion].find(i) == graph[champion].end()) {
                return -1; // Not all nodes are reachable from the champion
            }
        }

        return champion;
    }
}; 

