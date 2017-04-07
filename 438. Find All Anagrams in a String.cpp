class Solution {
public:
    inline int getIndex(char ch) {
        return ch - 'a';
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        
        if (s.size() < p.size()) {
            return vector<int>();
        }
        
        int cvec[26] = { };
        for (auto ch : p) {
            ++cvec[ch - 'a'];
        } 
        
        int size = s.size() - p.size() + 1;
        vector<int> temp(26, 0);
       
        for (int i = 0; i < size; ++i) {
            auto sIndex = getIndex(s[i]);
        
            if (cvec.at(sIndex)) {
                
                auto sz = p.size() + i;
                int j = i;
                
                temp.assign(temp.size(), 0);
                while (j < sz) {
                    auto index = getIndex(s[j++]);
                    ++temp[index];
                }
                
                if (temp == cvec) {
                    result.push_back(i);
 
                    while (j  < s.size() && s[j] == s[i]) {
                        result.push_back(i + 1);
                        ++i;
                        ++j;
                    }
                }
            }
        }
        
        return result;
    }
};