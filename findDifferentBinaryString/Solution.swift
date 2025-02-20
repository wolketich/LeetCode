class Solution {
    func findDifferentBinaryString(_ nums: [String]) -> String {
        let n = nums.count
        var binarySet = Set(nums)
        
        for i in 0..<(1 << n) {
            let candidate = String(i, radix: 2).leftPadding(toLength: n, withPad: "0")
            if !binarySet.contains(candidate) {
                return candidate
            }
        }
        return ""
    }
}

extension String {
    func leftPadding(toLength: Int, withPad character: Character) -> String {
        let newLength = self.count
        if newLength < toLength {
            return String(repeatElement(character, count: toLength - newLength)) + self
        } else {
            return self
        }
    }
}
