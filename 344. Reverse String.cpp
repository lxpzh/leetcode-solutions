class Solution {
public:
    string reverseString(string s) {
       if (s.empty())
            return s;
        size_t j = s.size() - 1;
        for (size_t i = 0; i < j; j--, i++) {
            swap(s[i],s[j]);
        }
      
        return s;
    }
};