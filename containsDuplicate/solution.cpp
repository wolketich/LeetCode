class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    
        unordered_set<int> numFreq;

        for (int num : nums) {
            if (numFreq.count(num)) return true;
            else numFreq.insert(num);
        }

        return false;
    }
};
