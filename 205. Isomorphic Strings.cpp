
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, int> sHash;
		unordered_map<char, int> tHash;
 
		for (auto i = 0; i < s.size(); i++) {
			sHash.insert({ s[i], t[i] });
			tHash.insert({ t[i], s[i] });
		}
    
		for (size_t i = 0; i < s.size(); i++) {
			if (sHash[s[i]] != t[i] || tHash[t[i]] != s[i]) {
			    return false;
			}
		}

		return true;
	}
};