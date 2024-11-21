#include <vector>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Create a grid
        vector<vector<char>> grid(m, vector<char>(n, 'U')); // 'U' for unoccupied
        
        // Mark walls and guards
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 'W'; // 'W' for wall
        }
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 'G'; // 'G' for guard
        }
        
        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Mark guarded cells
        for (const auto& guard : guards) {
            int row = guard[0], col = guard[1];
            for (const auto& dir : directions) {
                int r = row, c = col;
                while (true) {
                    r += dir.first;
                    c += dir.second;

                    // Stop if out of bounds or hitting a wall/guard
                    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 'W' || grid[r][c] == 'G') {
                        break;
                    }

                    // Mark cell as guarded if it's unoccupied
                    if (grid[r][c] == 'U') {
                        grid[r][c] = 'X'; // 'X' for guarded
                    }
                }
            }
        }

        // Count unguarded cells
        int unguardedCount = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 'U') {
                    ++unguardedCount;
                }
            }
        }

        return unguardedCount;
    }
};

