class Solution {
public:
    char findTheDifference(string s, string t) {
        int chars[128];
        memset(chars,0,sizeof(chars));
        
        for (int i=0; i < s.size(); i++) {
            chars[s[i]]++;
        }
        
        int i = 0;
        for (; i < t.size() && (--chars[t[i]] >= 0); i++) {
            ;
        }
        
        return t[i];
    }
};