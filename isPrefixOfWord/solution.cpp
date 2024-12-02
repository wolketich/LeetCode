class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        istringstream stream(sentence);
        string word;
        int index = 1; // 1-indexed position
        
        while (stream >> word) {

            if (word.find(searchWord) == 0) {
                return index;
            }
            index++;
        }
        
        // If no prefix was found, return -1
        return -1;
    }
};

