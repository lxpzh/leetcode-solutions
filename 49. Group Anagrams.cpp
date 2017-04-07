class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_multimap<string, int> m;
    
        for (auto i = 0; i < strs.size(); i++) {
            auto temp = strs[i];
            sort(temp.begin(), temp.end());
            m.insert({temp, i});    
        }
       
        vector<vector<string>> result;
        vector<string> temp;
        result.reserve(strs.size() / 2);
        
        for (auto iter = m.begin(); iter != m.end();) {
            auto originalIter = iter;
            while (iter != m.end() && iter->first == originalIter->first) { 
                temp.push_back(strs[ iter->second ]);
                ++iter;
            }
            result.push_back(temp);
            temp.clear();
        }
         
        return result;
    }
};