class Solution {
    func countCompleteSubstrings(_ word: String, _ k: Int) -> Int {
        let vowels: Set<Character> = ["a", "e", "i", "o", "u"]
        let chars = Array(word)
        let n = chars.count
        var count = 0

        var left = 0
        var vowelCount = [Character: Int]()
        var consonantCount = 0

        for right in 0..<n {
            let c = chars[right]
            
            if vowels.contains(c) {
                vowelCount[c, default: 0] += 1
            } else {
                consonantCount += 1
            }

            while consonantCount > k {
                let lc = chars[left]
                if vowels.contains(lc) {
                    vowelCount[lc]! -= 1
                    if vowelCount[lc]! == 0 {
                        vowelCount.removeValue(forKey: lc)
                    }
                } else {
                    consonantCount -= 1
                }
                left += 1
            }

            if consonantCount == k && vowelCount.count == 5 {
                count += 1
                var tempLeft = left
                var tempVowelCount = vowelCount
                var tempConsonantCount = consonantCount

                while tempLeft < right {
                    let lc = chars[tempLeft]
                    if vowels.contains(lc) {
                        tempVowelCount[lc]! -= 1
                        if tempVowelCount[lc]! == 0 {
                            break
                        }
                    } else {
                        tempConsonantCount -= 1
                        if tempConsonantCount < k {
                            break
                        }
                    }
                    count += 1
                    tempLeft += 1
                }
            }
        }

        return count
    }
}

