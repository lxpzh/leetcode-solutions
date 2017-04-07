class Solution {
public:
    inline void setPivoitToEnd(vector<int>& nums, int first, int last) {
		int middle = first + (last - first) / 2;
		int pivoitIndex;

		if (nums[first] < nums[middle])
			if (nums[middle] < nums[last])
				pivoitIndex = middle;
			else if (nums[first] < nums[last])
				pivoitIndex = last;
			else
				pivoitIndex = first;
		else if (nums[first] < nums[last])
			pivoitIndex = first;
		else if (nums[middle] < nums[last])
			pivoitIndex = last;
		else
			pivoitIndex = middle;

		swap(nums[last], nums[pivoitIndex]);
	}

    int patition(vector<int>& nums, int first, int last) {
        int i = first - 1;
        setPivoitToEnd(nums, first, last);
        int pivoit = nums[last];
        
        for (int j = first; j < last; j++) {
            if (nums[j] < pivoit) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[++i], nums[last]);
        
        return i;
    } 
    
    int findKthLargest(vector<int>& nums, int first, int last, int k) {
     	if (first == last) {
			return nums[first];
		}

		int patitionIndex = patition(nums, first, last);
		int index = patitionIndex - first;

		if (index == k) {
			return nums[patitionIndex];
		}
		else if (index > k) {
			return findKthLargest(nums, first, patitionIndex - 1, k);
		}
		else {
			return findKthLargest(nums, patitionIndex + 1, last, k - index - 1);
		}
	}
  
    inline int getMedian(vector<int>&  ivec, int first, int last)
	{ 
		if (last - first <= 4) {
		//	insertionSort(ivec, first, last);
			int median = first + (last - first) / 2;
		 	return first;
		}
 
		int t = first - 1, i;
		for (i = first; i <= last && i + 5 <= last; i += 5) {
		 //	insertionSort(ivec, i, i + 4);
			std::swap(ivec[++t], ivec[i + 2]);    // swap median with first element''
		}
		
		if (last - i + 1 > 0) {
		 //	insertionSort(ivec, i, last);
			auto mid = i + (last - i) / 2;
			std::swap(ivec[++t], ivec[mid]);
		}
	 
		return getMedian(ivec, first, t);
	}

	inline int partition(vector<int>& nums, int first, int last, int pivoitIndex) {
		int i = first - 1;
		swap(nums[last], nums[pivoitIndex]);
		int pivoit = nums[last];

		for (int j = first; j < last; j++) {
			if (nums[j] < pivoit) {
				swap(nums[++i], nums[j]);
			}
		}
		swap(nums[++i], nums[last]);

		return i;
	}

	int brfprtSelect(vector<int>& ivec, int first, int last, int k)
	{
	 	int median = getMedian(ivec, first, last);
		auto partitionIndex = partition(ivec, first, last, median);
		int L1 = last - partitionIndex;
		
		if (k - 1 == L1) {
			return ivec[partitionIndex];
		}
		else if (k <= L1) {
			return brfprtSelect(ivec,partitionIndex + 1, last, k);
		}
		else if (k > L1 + 1) {
			return brfprtSelect(ivec, first, partitionIndex - 1, k - L1 - 1);
		} else {
		    return 0;
		}
	}
	
    //综合，当K比较小时，方法3速度最快，不过若K越来越接近num.size()，效果越差。
    int findKthLargest(vector<int>& nums, int k) {
      //  method 1
     //    return findKthLargest(nums, 0, nums.size() - 1, nums.size() - k);    
         return brfprtSelect(nums, 0, nums.size() - 1,k);
    
      /*method 3, O(nlogk)
      priority_queue<int, vector<int>, greater<int>> q;     //小顶堆,top是queue里面最小的
      int i = 0;
      
      for (auto i=0; i != nums.size(); ++i) {
         if (i < k) {
             q.push(nums[i]);
         } 
         else {
             if (nums[i] > q.top()) {
                 q.pop();
                 q.push(nums[i]);
             }
         }
      }
      
      return q.top();
      */
      // method 4
    //  nth_element(nums.begin(), nums.begin() + k - 1, nums.end(),greater<int>());
    //  return nums[k - 1];
    }
};