struct CacheNode {
	int key;
	int value;
	CacheNode(int k, int v): key(k), value(v) {}
};

class LRUCache {
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if(cachemap.find(key) == cachemap.end())
			return -1;
		cachelist.splice(cachelist.begin(), cachelist, cachemap[key]);
		return cachemap[key]->value;
	}
	
	void set(int key, int value) {
		if(cachemap.find(key) != cachemap.end()) {
			cachelist.splice(cachelist.begin(), cachelist, cachemap[key]);
			cachemap[key]->value = value;
		} else {
			if(capacity == cachelist.size()) {
				cachemap.erase(cachelist.back().key);
				cachelist.pop_back();
			}
			cachelist.push_front(CacheNode(key, value));
			cachemap[key] = cachelist.begin();
		}
	}
private:
	int capacity;
	list<CacheNode> cachelist;
	unordered_map<key, list<CacheNode>::iterator> cachemap;
};
