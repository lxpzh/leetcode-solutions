struct Comp {
	bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
		return p1.second > p2.second;
	} 
};
	
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> intergerFrequencyMap;
       
       for (auto const& num : nums) {
           if (intergerFrequencyMap.find(num) == intergerFrequencyMap.end()) {
               intergerFrequencyMap[num] = 1;
           } else {
               ++intergerFrequencyMap[num];
           }
       }
       
       typedef pair<int, int> IntIntPair;
       priority_queue<IntIntPair, vector<IntIntPair>, Comp> q;
       
       int t=0;
       for (auto const& iter : intergerFrequencyMap) {
        //   cout << iter.first << " : " << iter.second << endl;
           if (t < k) {
                ;
           } else if (iter.second > q.top().second) {
               q.pop();
           } else {
               continue;
           }
           
           q.push(make_pair(iter.first, iter.second));
           ++t;
       }
   
       vector<int> topKFrequentVec;
       topKFrequentVec.reserve(intergerFrequencyMap.size());
       while (!q.empty()) {
           auto const& p = q.top();
           topKFrequentVec.push_back(p.first);    
           q.pop();
       }
       
       return topKFrequentVec;
    }
};