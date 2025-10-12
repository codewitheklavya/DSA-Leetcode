class Solution {
public:

    bool isVowel(char c){
        string vowels = "aeiouAEIOU";
        return vowels.find(c) != string::npos;
    }

    string reverseVowels(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            if(!isVowel(s[i])) i++;
            else if(!isVowel(s[j])) j--;
            else{ 
                swap(s[i],s[j]);      
                i++;
                j--;
            }
        }
        return s;
    }
};