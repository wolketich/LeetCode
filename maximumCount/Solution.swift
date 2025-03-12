class Solution {
    func maximumCount(_ nums: [Int]) -> Int {
        var positiveNumbers: [Int] = []
        var negativeNumbers: [Int] = []

        for num in nums {
            if num > 0 {
                positiveNumbers.append(num)
            } else if num < 0 {
                negativeNumbers.append(num)
            }
        }  

        return max(positiveNumbers.count, negativeNumbers.count)
    }
}
