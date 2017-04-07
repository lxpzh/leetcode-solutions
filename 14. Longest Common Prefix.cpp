class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return string();
        }
        
        auto minStrIter = min_element(strs.begin(), strs.end(), 
            [](const string& str1, const string& str2) {
                return str1.size() < str2.size();
        });
        
        auto minStr = *minStrIter;
 
        int prefixLen = minStr.size();
        for (const auto& str : strs) {
            
            int i;
            for (i = 0; i < minStr.size(); i++) {
                if (minStr[i] != str[i]) {
                    break;
                }
            }
            
            if (i < prefixLen) {
                prefixLen = i;
            }
        }
        
        return minStr.substr(0, prefixLen);
    }
};