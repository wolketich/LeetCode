class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int rows = accounts.size();
        int cols = accounts[0].size();

        vector<int> wealth(rows, 0);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                wealth[i] += accounts[i][j];
        
        int maxWealth = wealth[0];
        for (int i = 0; i < wealth.size(); i++)
                maxWealth = max(maxWealth, wealth[i]);

        return maxWealth;
    }
};
