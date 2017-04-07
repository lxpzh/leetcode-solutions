class Solution {
public:
 /*
    vector<string> splitSpace(const string& splitStr, size_t sz) {
        vector<string> strVec;
        strVec.reserve(sz);
        
        istringstream iss(splitStr);
        copy(istream_iterator<string>(iss),
        istream_iterator<string>(), back_inserter(strVec));

        return strVec;
    }

    
    bool wordPattern(string pattern, string str) 
    {
        auto splitStrVec = splitSpace(str, pattern.size());
        
        if (splitStrVec.size() != pattern.size()) 
        {
            return false;
        }
        else 
        {
           // unordered_map<char, string> patternStrMap;
            vector<string> patternStrMap(128);
            unordered_map<string, char> strPatternMap;
            
            for (int i = 0; i < pattern.size(); i++) 
            {
                //auto patternStrIter = patternStrMap.find(pattern[i]);
                auto index = pattern[i];
                if ( patternStrMap[ index ].empty() )
                {
                    auto strPatternIter = strPatternMap.find(splitStrVec[i]);
                    if (strPatternIter == strPatternMap.end())
                    {
                        strPatternMap.insert({ splitStrVec[i], pattern[i] });
                    }
                    else 
                    {
                        if (strPatternIter->second != pattern[i])
                        {
                            return false;
                        }
                    }
                    patternStrMap[ index ] = splitStrVec[i] ;
                } 
                else 
                {
                    if (patternStrMap[ index ] != splitStrVec[i]) 
                    {
                        return false;
                    }
                }
            }
            
            return true;
        }
    }
    */
     bool wordPattern(string pattern, string str) 
    {
        unordered_map<char, int> patternStrMap;
        unordered_map<string, int> strPatternMap;
        istringstream in(str);
        
        int i = 0;
        string word;
        
        while (in >> word) 
        {
                //auto patternStrIter = patternStrMap.find(pattern[i]);
            if (i == pattern.size() || patternStrMap[ pattern[i] ] != strPatternMap[word] ) {
                return false;
            }
            
           patternStrMap[ pattern[i] ] =  strPatternMap[word] = ++i;
        }
        
        return i == pattern.size();    
    }
};