class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        nums.sort()  # Sort the array to process ranges in order
        max_beauty = 0
        left = 0

        # Sliding window to find the longest overlap of ranges
        for right in range(len(nums)):
            while nums[right] - nums[left] > 2 * k:
                left += 1
            max_beauty = max(max_beauty, right - left + 1)

        return max_beauty

