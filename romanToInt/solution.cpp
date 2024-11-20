class Solution {
public:
    int transformRoman(char c) {
                switch (c) {
                    case 'I': return 1;
                    case 'V': return 5;
                    case 'X': return 10;
                    case 'L': return 50;
                    case 'C': return 100;
                    case 'D': return 500;
                    case 'M': return 1000;
                }
            return 0;
            }

    int romanToInt(string s) {
        int length = s.length();
        int sum = 0;

        for (int i = 0; i < length; ++i) {
            // If the current numeral is less than the next, subtract it.
            if (transformRoman(s[i]) < transformRoman(s[i + 1])) {
                sum -= transformRoman(s[i]);
            } else {
                sum += transformRoman(s[i]);
            }
        }

        return sum;
    }
};
