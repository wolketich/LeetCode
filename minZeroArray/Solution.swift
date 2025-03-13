let n = nums.count
    let m = queries.count
    
    func canZeroArray(_ k: Int) -> Bool {
        var diff = Array(repeating: 0, count: n + 2)
        
        for i in 0..<k {
            let l = queries[i][0]
            let r = queries[i][1]
            let val = queries[i][2]
            diff[l] += val
            diff[r + 1] -= val
        }
        
        var maxDecrement = Array(repeating: 0, count: n)
        var curr = 0
        for i in 0..<n {
            curr += diff[i]
            maxDecrement[i] = curr
        }
        
        for i in 0..<n {
            if nums[i] > maxDecrement[i] {
                return false
            }
        }
        return true
    }
    
    // Binary search on the number of queries
    var left = 0
    var right = queries.count
    var result = -1
    
    while left <= right {
        let mid = (left + right) / 2
        if canZeroArray(mid) {
            result = mid
            right = mid - 1
        } else {
            left = mid + 1
        }
    }
    
    return result
