class Solution {
    func minimumRecolors(_ blocks: String, _ k: Int) -> Int {
        let blocksArray = Array(blocks)
        var whiteCount = 0
        var minWhite = Int.max
        
        // Count 'W' in the first window of size k
        for i in 0..<k {
            if blocksArray[i] == "W" {
                whiteCount += 1
            }
        }
        
        minWhite = whiteCount
        
        // Slide the window across the string
        for i in k..<blocksArray.count {
            if blocksArray[i] == "W" { whiteCount += 1 }
            if blocksArray[i - k] == "W" { whiteCount -= 1 }
            
            minWhite = min(minWhite, whiteCount)
        }
        
        return minWhite
    }
}
