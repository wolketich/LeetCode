class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> answer;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            answer.push_back(sum);
        }
        return answer;
    }
};
