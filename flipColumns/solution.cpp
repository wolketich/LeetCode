class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    unordered_map<string, int> rowCount;

    for (const auto& row : matrix) {
        string normalized = "";
        for (int val : row) {
            normalized += to_string(val ^ row[0]);
        }
        rowCount[normalized]++;
    }

    // Find the maximum count
    int maxCount = 0;
    for (const auto& [key, count] : rowCount) {
        maxCount = max(maxCount, count);
    }

    return maxCount;
}
};
