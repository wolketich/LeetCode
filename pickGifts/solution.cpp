class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        for (int i = 0; i < k; i++) {

            // find max by index 
            int indexMax = 0;
            for (int j = 0; j < gifts.size(); j++){
                if (gifts[j] >= gifts[indexMax])
                    indexMax = j; 
            }

            // leave the floor of the square root
            gifts[indexMax] = floor(sqrt(gifts[indexMax]));
        }

        // return sum
        long long sum = 0;
        for (int i = 0; i < gifts.size(); i++)
            sum += gifts[i];

        return sum;
    }
};
