class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;
        while(i < n){
            int lineLength = words[i].size();
            int j = i + 1;
            while(j < n && lineLength + words[j].size() + (j-i) <= maxWidth){
                lineLength += words[j].size();
                j++;
            }

            int numWords = j - i;
            int numSpaces = maxWidth - lineLength;

            string line;
            if(numWords == 1 || j == n){
                line = words[i];
                for(int k = i + 1; k < j; k++){
                    line += ' ' + words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            }
            else{
                int spacesBetweenWords = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);

                line = words[i];
                for(int k = i + 1; k < j; k++){
                    line += string(spacesBetweenWords, ' ');
                    if(extraSpaces > 0){
                        line += ' ';
                        extraSpaces--;
                    }
                    line += words[k];
                }
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};