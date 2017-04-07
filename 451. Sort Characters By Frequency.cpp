  struct FreqChracter {
        FreqChracter() : freq() { };
        char ch;
        int freq;
    };
    
class Solution {
public:
  /*  string frequencySort(string s) {
        vector<int> cvec(128,0);
        multimap<int, int> m;
 
        for (auto ch : s) {
            ++cvec[ch];
        }
   
        for (auto ch=0; ch < cvec.size(); ch++) {
            if (cvec[ch] > 0) {
                m.insert({cvec[ch], ch});
            }
        }
         
        string result;
        result.reserve(s.size());
        
        for (auto iter = m.rbegin(); iter != m.rend(); ++iter) {
            int count = iter->first;
            while (count) {
                result.push_back(iter->second);
                --count;
            }
        }
       
        return result;
    }
    */
    /*
    string frequencySort(string s) {
        if (s.empty())
            return s;
        vector<int> cvec(128,0);
 
        int maxSize = INT_MIN;
        for (auto ch : s) {
            ++cvec[ch];
            if (maxSize < cvec[ch]) {
                maxSize = cvec[ch];
            }
        }
         
        vector<shared_ptr<list<int>>> m(maxSize + 1, nullptr);
        
        
        for (auto ch=0; ch < cvec.size(); ch++) {
            auto frequency = cvec[ch];
            if (frequency > 0) {
                if (m[frequency] == nullptr) {
                    m[frequency] = std::make_shared<list<int>>();
                }
                 m[frequency]->push_back(ch);
            }
        }
        
        string result;
        result.reserve(s.size());
  
        for (int freq = m.size() - 1; freq >= 0; freq--) {
            if (m[freq] != nullptr) {
                const auto& myList = *m[freq];
             
                for (auto ch : myList) {
                
                    auto count = freq;
                    while (count) {
                        result.push_back(ch);
                        --count;
                    }
                }
            }
        }
        
       
        return result;
    }
    */
  
    
    string frequencySort(string s) {
        vector<FreqChracter> cvec(128);
        
        for (auto c : s) {
            cvec[c].freq++;
            cvec[c].ch = c;
        }
        
        auto Comp = [](const FreqChracter& ch1, const FreqChracter& ch2) {
          return ch1.freq > ch2.freq;  
        };
        
        sort(cvec.begin(), cvec.end(), Comp);
        
        string result;
        result.reserve(s.size());
        
        for (int i=0; i < cvec.size(); i++) {
            int freq = cvec[i].freq;
            while ( freq-- ) {
               result += cvec[i].ch;
            }
        }
        return result;
    }
};