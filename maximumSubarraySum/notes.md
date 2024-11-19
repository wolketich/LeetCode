# Problem: 2461. Maximum Sum of Distinct Subarrays With Length K

## Approach

This solution uses a sliding window and an unordered set for maintaining distinct elements. The set allows O(1) average-time complexity for insert and erase operations, ensuring optimal runtime.

### Steps:
1. **Initialize Variables**:
   - `window`: An unordered set to store distinct elements of the current subarray.
   - `currentSum`: Tracks the sum of elements in the current subarray.
   - `maxSum`: Stores the maximum sum encountered.

2. **Sliding Window**:
   - Expand the window by adding `nums[right]`.
   - If `nums[right]` already exists in the set, remove elements from the left until the subarray becomes distinct.
   - If the window size equals `k`, compare `currentSum` with `maxSum`, and then shrink the window from the left to maintain the sliding behavior.

3. **Edge Cases**:
   - If no valid subarray of size `k` exists, return `0`.

### Complexity:
- **Time Complexity**: O(n), where `n` is the size of `nums`. Each element is processed at most twice (once for addition and once for removal).
- **Space Complexity**: O(k), for the unordered set storing elements of the current subarray.

---

## Examples

### Example 1:
**Input**: nums = [1, 5, 4, 2, 9, 9, 9], k = 3  
**Output**: 15  
**Explanation**:
- Subarrays of length `k`: [1, 5, 4], [5, 4, 2], [4, 2, 9], [2, 9, 9], [9, 9, 9].
- Only [1, 5, 4], [5, 4, 2], and [4, 2, 9] are valid. The maximum sum is `15`.

### Example 2:
**Input**: nums = [4, 4, 4], k = 3  
**Output**: 0  
**Explanation**:
- No valid subarray meets the condition of all elements being distinct.

---

## Notes
- Using `unordered_set` instead of `unordered_map` optimizes memory usage.
- Sliding window ensures that the runtime is linear, even