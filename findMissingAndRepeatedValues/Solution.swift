class Solution {
    func findMissingAndRepeatedValues(_ grid: [[Int]]) -> [Int] {
        let n = grid.count
        let totalNumbers = n * n
        var numCount = [Int: Int]()
        
        // Count occurrences of each number
        for row in grid {
            for num in row {
                numCount[num, default: 0] += 1
            }
        }
        
        var repeated = 0, missing = 0
        
        // Identify repeated and missing numbers
        for num in 1...totalNumbers {
            if let count = numCount[num] {
                if count == 2 { repeated = num }
            } else {
                missing = num
            }
        }
        
        return [repeated, missing]
    }
}

