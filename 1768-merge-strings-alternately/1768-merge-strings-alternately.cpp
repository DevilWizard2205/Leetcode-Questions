class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();

        string result;

        for (int i = 0, j = 0; i < len1 || j < len2; i++, j++) {

            if (i < len1) {
                result += word1[i];
            }

            if (j < len2) {
                result += word2[j];
            }
        }

        return result;
    }
};