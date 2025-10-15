class Solution {
public:
    string reverseWords(string s) {
        //reverse whole string firstly
        reverse(s.begin(),s.end());
        int i = 0;
        int l = 0, r = 0;
        int n = s.length();
        while(i<n){
            while(i<n && s[i] !=' '){//if i get char then it give it to r
                s[r] = s[i];
                i++;
                r++;
            }
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);

                s[r] = ' ';
                r++;

                l = r;
            }
            i++;
        }
        s = s.substr(0,r-1);

        return s;
    }
};