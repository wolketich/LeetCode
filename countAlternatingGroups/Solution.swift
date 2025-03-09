func countAlternatingGroups(_ colors: [Int], _ k: Int) -> Int {
    let n = colors.count
    guard k <= n else { return 0 }

    // Create a circular version of colors
    let extended = colors + colors.prefix(k - 1)
    var count = 0

    for i in 0..<n {
        var isAlternating = true
        for j in 1..<k-1 {
            let current = extended[i + j]
            let prev = extended[i + j - 1]
            let next = extended[i + j + 1]
            if current == prev || current == next {
                isAlternating = false
                break
            }
        }
        if isAlternating {
            count += 1
        }
    }

    return count
}

