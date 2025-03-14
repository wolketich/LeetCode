class Solution {
    func maximumCandies(_ candies: [Int], _ k: Int) -> Int {
        var left = 1
        var right = candies.max() ?? 0
        var result = 0

        while left <= right {
            let mid = (left + right) / 2
            let childrenCount = candies.reduce(0) { $0 + $1 / mid }

            if childrenCount >= k {
                result = mid
                left = mid + 1
            } else {
                right = mid - 1
            }
        }

        return result
    }
}
