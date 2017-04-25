class Solution {
public:
    // 是否是valid的正则表达式
    // [\s]*[-|+]?(\d+[\.]?\d*|[\.]\d+)(e[+|-]?\d+)?[\s]*
    bool isNumber(string s) {
        auto beg = s.begin();
        
        while (beg != s.end() && isspace(*beg)) {
            ++beg;
        }
        
        if (beg != s.end() && (*beg == '+' || *beg == '-'))
        {
            ++beg;
        }
        
        if (beg == s.end()) {
            return false;
        }
        else {
            bool containDigits = false;
            while (beg != s.end() && isdigit(*beg)) {  // for s = ".122", we think it is right
                ++beg;
                containDigits = true;
            }
            
            if (beg != s.end() && *beg == '.') {   // for 
                ++beg;
            } 
            
            while (beg != s.end() && isdigit(*beg)) {
                ++beg;
                containDigits = true;
            }
            
            if (!containDigits) {            // assure digits exist
                return false;
            }
            
            if (beg != s.end() && *beg == 'e') {
                
                if (++beg == s.end()) {         // such as "e"
                    return false;
                }
                if (beg != s.end() && (*beg == '+' || *beg == '-')) {
                    ++beg;
                }
               
                if (beg == s.end() || !isdigit(*beg)) {     // after 'e', digits must exist,such as "e  ","e 1",all are wrong
                    return false;
                }
                else {
                    while (beg != s.end() && isdigit(*beg)) {
                        ++beg;
                    } 
                }
                
            }
        }
        
        while (beg != s.end() && isspace(*beg)) {
            ++beg;
        }
        
        return beg == s.end();
    }
};