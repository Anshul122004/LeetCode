class Solution {
public:
    int MAX_WIDTH;

    string findLine(int i, int j, int eachGapSpace, int extraSpace,
                    vector<string>& words) {

        string line;

        for (int k = i; k < j; k++) {
            line += words[k];

            if (k == j - 1)
                continue;

            line += string(eachGapSpace, ' ');

            if (extraSpace > 0) {
                line += ' ';
                extraSpace--;
            }
        }

        while (line.length() < MAX_WIDTH)
            line += ' ';

        return line;
    }

    string findLastLine(int i, int j, vector<string>& words) {
        string line;

        for (int k = i; k < j; k++) {
            line += words[k];

            if (k != j - 1)
                line += ' ';
        }

        while (line.length() < MAX_WIDTH)
            line += ' ';

        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> result;
        MAX_WIDTH = maxWidth;

        int n = words.size();
        int i = 0;

        while (i < n) {

            int lettersCount = words[i].length();
            int j = i + 1;
            int gaps = 0;

            while (j < n &&
                   lettersCount + words[j].length() + gaps + 1 <= maxWidth) {

                lettersCount += words[j].length();
                gaps++;
                j++;
            }

            if (j == n || gaps == 0) {
                result.push_back(findLastLine(i, j, words));
            }
            else {
                int totalSpaces = maxWidth - lettersCount;
                int eachGapSpace = totalSpaces / gaps;
                int extraSpace = totalSpaces % gaps;

                result.push_back(
                    findLine(i, j, eachGapSpace, extraSpace, words)
                );
            }

            i = j;
        }

        return result;
    }
};