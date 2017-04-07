namespace HashCode {
	template <typename T>
	struct hash {	};

	template <>
	struct hash < int > {
		size_t operator()(int val) const {
			return val ^ (val >> 16);
		}
	};
}


static const unsigned long numPrimes = 28;

static const unsigned long primeList[numPrimes] =
{
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};

template <typename ValueType>
struct Node {
	Node<ValueType> *next;
	ValueType data;

	Node() : next(nullptr) {  }

	Node(const ValueType& value) : data(value), next(nullptr) {  }

	bool operator==(const Node<ValueType>& other) {
		return (next == other.next && data == other.data);
	}

	bool operator!=(const Node<ValueType>& other) {
		return !(*this == other);
	}
};


template <typename KeyType, typename ValueType, typename HashFunc,
	typename ExtractKey, typename EqualKey>
class HashTable;

template <typename KeyType, typename ValueType, typename HashFunc,
	typename ExtractKey, typename EqualKey>
struct HashIterator : public std::iterator < std::forward_iterator_tag, ValueType >
{
public:
    typedef forward_iterator_tag  iterator_category;
    typedef ValueType            value_type;

	typedef Node<ValueType>  Nodes ;
	typedef HashTable < KeyType, ValueType,
		HashFunc, ExtractKey, EqualKey> HashTables;
	typedef HashIterator < KeyType, ValueType, HashFunc,
		ExtractKey, EqualKey> iterators ;

	HashIterator(Nodes* node, HashTables* ht) :
		cur(node), hashTable(ht) { }

	iterators& operator++() {
		Nodes* oldNode = cur;
		cur = cur->next;

		if (!cur) {   // cur is nullptr
			auto index = hashTable->getValueIndex(oldNode->data);

			while (!cur && ++index < hashTable->size()) {
				cur = hashTable->buckets[index];
			}
		}

		return *this;
	}

	iterators& operator++(int) {
		HashIterator temp = *this;
		++*this;
		return temp;
	}

	value_type& operator*() {
		return cur->data;
	}

	value_type* operator->() {
		return &operator*();
	}
	bool operator==(const iterators& other) const {
		return (cur == other.cur);
	}

	bool operator!=(const iterators& other) const {
		return !(*this == other);
	}

	Nodes *cur;
	HashTables* hashTable;
};


template <typename KeyType, typename ValueType, typename HashFunc,
	typename ExtractKey, typename EqualKey>
class HashTable {
public:
	typedef  ValueType value_type;
	typedef  std::size_t      size_type ;
	typedef ptrdiff_t difference_type;
	typedef KeyType key_type ;
	typedef HashIterator < KeyType, ValueType,
		HashFunc, ExtractKey, EqualKey >   iterator;
	typedef Node < value_type >  Nodes  ;

	friend struct
		HashIterator < KeyType, ValueType, HashFunc, ExtractKey, EqualKey> ;

	HashTable(size_type n) : elemSize(0) {
		initialBuckets(n);
	}

	bool empty() const {
		return (size() == 0);
	}
	
	void initialBuckets(size_type n) {
		elemSize = getNextPrime(n);
		buckets.reserve(n);
		buckets.insert(buckets.end(), elemSize, nullptr);
	}

	size_type bucket_count() const{
		return buckets.size();
	}

	size_type size() const {
		return elemSize;
	}

	size_type getValueIndex(const value_type& value) const {
		return getIndex(extractKey(value));
	}
	
	size_type getIndex(const key_type& key) const {
		return getIndex(key, buckets.size());
	}

	size_type getIndex(const key_type& key, size_type n) const {
		return key & (n - 1);
	}

	Nodes* createNode(const value_type& value) {
		return new Nodes(value);
	}
    
    size_type max_size() const {
		return 1073741824;   // 2^30
	}
	std::pair<iterator, bool> insert(const value_type& value) {
		if (elemSize + 1 > static_cast<int>(bucket_count() * loadFactor)) {
			resize(bucket_count() + 1);
		}
		return insertUnqiueNoresize(value);
	}
    
	std::pair<iterator, bool> insertUnqiueNoresize(const value_type& value) {
		key_type key = extractKey(value);
		int index = getIndex(key);
		Nodes* node = buckets[index];

		for (; node; node = node->next) {
			if (equalKey(extractKey(node->data), key)) {
				return make_pair(iterator(node, this), false);
			}
		}

		Nodes *temp = createNode(value);
		temp->next = buckets[index];
		buckets[index] = temp;
		++elemSize;

		return make_pair(iterator(temp, this), true);
	}
     iterator begin() {
		for (size_type i = 0; i != buckets.size(); i++) {
			if (buckets[i]) {
				return iterator(buckets[i], this);
			}
		}
		return end();
	}

	iterator end() {
		return iterator(nullptr, this);
	}
	void resize(size_type sz) {
	    if (sz > bucket_count()) {
			auto newBucketCount = getNextPrime(sz);

			if (newBucketCount != max_size()) {
				std::vector<Nodes*> temp(newBucketCount, nullptr);

				for (auto i = 0; i != bucket_count(); i++) {
					auto node = buckets[i];

					while (node) {
						auto key = extractKey(node->data);
						int newIndex = getIndex(key, newBucketCount);
						buckets[i] = node->next;
						node->next = temp[newIndex];
						temp[newIndex] = node;
						node = buckets[i];
					}
				}
				buckets.swap(temp);
			}
		}
	}

	iterator find(const key_type& key) {
		auto index = getIndex(key);

		for (auto node = buckets[index]; node; node = node->next) {
			if (equalKey( extractKey(node->data), key) ) {
				return iterator(node, this);
			}
		}

		return iterator(nullptr, this);
	}

	void erase(iterator position) {
		auto positonNode = position.cur;

		if (positonNode) {
			auto key = extractKey(positonNode->data);
			auto index = getIndex(key);
			auto node = buckets[index];

			if (buckets[index] == positonNode) {
				buckets[index] = node->next;
				delete node;
				--elemSize;
			}
			else {
				Nodes* preNode;
				while (node) {
					if (node == positonNode) {
						preNode->next = node->next;
						delete node;
						--elemSize;
						break;
					}

					preNode = node;
					node = node->next;
				}
			}
		}
	}

private:
	ExtractKey	extractKey;
	EqualKey	equalKey;
	HashFunc	hashFuc;

	unsigned long getNextPrime(unsigned long n) const {
		if (n < 128) {
			return 128;
		}
		else if (n > max_size()) {
			return max_size();
		} 
		else {
			int i = 128;
			while (i < n) {
				i <<= 1;
			}
			return i;
		}
	}

private:
	const float loadFactor = 0.8;
	std::vector<Nodes*> buckets;
	size_type	elemSize;
};

template <typename T>
struct Identity {
    const T& operator() (const T& val) {
        return val;
    }
};

class Solution {
public:
	vector<int> intersection(const vector<int>& nums1, const vector<int>& nums2) {
		HashTable < int, int, HashCode::hash<int>,
		Identity<int>, equal_to<int>> m(10);

		vector<int> intersectionVec;

		for (auto num : nums1) {
			m.insert(num);
		}

		intersectionVec.reserve(nums1.size());

		for (auto num : nums2) {
            auto iter = m.find(num);
			if (iter != m.end()) {
				m.erase(iter);
				intersectionVec.push_back(num);
			}
		}

		return intersectionVec;
	}
};
