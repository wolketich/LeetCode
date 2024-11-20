class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string longestPrefix = "";
        int minLength = INT_MAX;

        for (int i = 0; i < strs.size(); i++)
            minLength = min(minLength, (int)strs[i].length());

        for (int i = 0; i < minLength; i++) {
            char currentChar = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != currentChar) {
                    return longestPrefix;
                }
                
            }
        longestPrefix += currentChar;
        }
        return longestPrefix;
    }
};
