class Solution {
    func numberOfSubstrings(_ s: String) -> Int {
        var count = 0
        var left = 0
        var right = 0
        var charCount = [Character: Int]()
        
        let n = s.count
        let sArray = Array(s)
        
        while right < n {
            charCount[sArray[right], default: 0] += 1
            
            while charCount["a", default: 0] > 0 && charCount["b", default: 0] > 0 && charCount["c", default: 0] > 0 {
                count += n - right
                charCount[sArray[left], default: 0] -= 1
                left += 1
            }
            
            right += 1
        }
        
        return count
    }
}
