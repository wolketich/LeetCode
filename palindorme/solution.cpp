class Solution {
public:
    bool isPalindrome(int x) {
        long int x_reversed = 0;
        int last_digit {0};
        int number = x;

        while (number > 0) {
            last_digit = number % 10;
            x_reversed = x_reversed * 10 + last_digit;
            number = number / 10;
        }

        return (x == x_reversed);
    }
};
