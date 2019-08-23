/*--------------------1st--------------------*/
class LRUCache {
public:
	LRUCache(int capacity):cap(capacity) {}
	int get(int key) {
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

class LRUCache {
public:
    LRUCache(int capacity) {
        
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        
    }
};