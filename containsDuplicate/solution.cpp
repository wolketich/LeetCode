class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++)
        for (int j = i + 1; j < nums.size(); j++)
            if (nums[i] == nums[j]) return true;
                else continue;
    return false;
    }
};
