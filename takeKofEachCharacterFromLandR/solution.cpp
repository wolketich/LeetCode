class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        unordered_map<char, int> total_count;
        
        // Count the total occurrences of each character
        for (char c : s) {
            total_count[c]++;
        }
        
        // If any character occurs less than k, it's impossible
        if (total_count['a'] < k || total_count['b'] < k || total_count['c'] < k) {
            return -1;
        }
        
        // Sliding window to find the largest skippable middle part
        unordered_map<char, int> current_count = {{'a', 0}, {'b', 0}, {'c', 0}};
        int max_window_length = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            current_count[s[right]]++;
            
            // Check if we can skip this window
            while (current_count['a'] > total_count['a'] - k ||
                   current_count['b'] > total_count['b'] - k ||
                   current_count['c'] > total_count['c'] - k) {
                current_count[s[left]]--;
                left++;
            }
            
            // Update the maximum window length
            max_window_length = max(max_window_length, right - left + 1);
        }
        
        // Minimum steps = total length - max_window_length
        return n - max_window_length;
    }
};
