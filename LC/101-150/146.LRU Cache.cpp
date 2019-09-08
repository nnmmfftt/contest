/*--------------------1st--------------------*/
class LRUCache {
public:
	LRUCache(int capacity):cap(capacity) {}
	int get(int key) {
		// if only store the necessary value
		// not use the Linkedlist pre node
		auto i = mp.find(key);
		if (i == mp.end()) {
			return -1;
		}
		int val = (*i).second;
        l.erase(find(l.begin(),l.end(),key));
		l.push_front(key);
		mp[key] = val;
		return val;
	}

	void put(int key, int value) {
		auto i = mp.find(key);
		if (i != mp.end()) {
            l.erase(find(l.begin(),l.end(),key));
        }
		l.push_front(key);
		mp[key] = value;
		if (l.size() > cap) {
			int key = l.back();
			mp.erase(key);
			l.pop_back();
		
        }
	}
private:
	unordered_map<int, int> mp;
	list<int> l;
	int cap;
};

/*--------------------2nd--------------------*/
class LRUCache {
public:
	LRUCache(int capacity):cap(capacity) {}
	int get(int key) {
		// using STL linkedlist to simplify the operation
		// store the position in linkedlist and save the fetch time
		auto i = mp.find(key);
		if (i == mp.end()) {
			return -1;
		}
		int val = i ->second -> second;
		l.erase(i->second);
		l.push_front(make_pair(key, val));
		mp[key] = l.begin();
		return i->second->second;
	}

	void put(int key, int value) {
		auto i = mp.find(key);
		if (i != mp.end()) {
			l.erase(i->second);
		}
		l.push_front(make_pair(key, value));
		mp[key] = l.begin();
		if (l.size() > cap) {
			int key = l.back().first;
			mp.erase(key);
			l.pop_back();
		}
	}
private:
	unordered_map<int, list<pair<int, int>>::iterator> mp;
	list<pair<int, int>> l;
	int cap;
};
