class Solution {
    func checkPowersOfThree(_ n: Int) -> Bool {
        var num = n
        while num > 0 {
            if num % 3 == 2 {
                return false  // If remainder is 2, it means we need a duplicate power of 3
            }
            num /= 3  // Move to the next power
        }
        return true
    }
}
