Last login: Mon Mar 10 13:41:07 on ttys000
Started
> cd myProjects/LeetCode
> git commit -m @3306. Count of Substrings Containing Every Vowel and K Consonants
> git commit -m @3306. Count of Substrings Containing Every Vowel and K Consonants II
> git commit -m "3306. Count of Substrings Containing Every Vowel and K Consonants II"
On branch main
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
countOfSubstrings/Solution.swift                              1,1            Top
-- INSERT --
