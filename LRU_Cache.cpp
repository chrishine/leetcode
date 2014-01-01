#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache{
public:
    LRUCache(const int capacity) : capacity(capacity), head(-1), tail(-1) { }

    LRUCache() = default;
    
    int get(int key) {
    	if(cache.count(key)){
    		move2head(key);
    		return cache[key].val;
    	}
    	return -1;
    }

    void set(int key, int value) {
    	if(cache.count(key)){
    		cache[key].val = value;
    		move2head(key);
    	} else {
    		Data_Link new_data = Data_Link(value);
    		if(cache.size() < capacity){
	    		cache[key] = new_data;
	    		add2head(key);
	    	} else {
	    		auto new_tail = cache[tail].prev;
	    		cache.erase(tail);
	    		tail = new_tail;
	    		cache[key] = new_data;
	    		add2head(key);
	    	}
    	}	
    }
private:
	void move2head(int key){
		if(head != key){	
			cache[cache[key].prev].next = cache[key].next;
			if(tail != key){
				cache[cache[key].next].prev = cache[key].prev;
			} else {
				tail = cache[key].prev;
			}
			cache[key].next = head;
			cache[key].prev = -1;
			cache[head].prev = key;
			head = key;
		}
	}

	void add2head(int key){
		cache[key].next = head;
		if(cache.size() > 1){
			cache[head].prev = key;
		}
		head = key;
		if(cache.size() == 1){
			tail = key;
		}
	}
	struct Data_Link{
		int val;
		int prev;
		int next;
		Data_Link() = default;
		Data_Link(const int val) : val(val) ,prev(-1), next(-1) { }
	};
	unordered_map<int, Data_Link> cache;
	int capacity;
	int head;
	int tail;
};



int main(int argc, char const *argv[])
{
	LRUCache lc(2);
	lc.set(2,1);
	lc.set(3,2);
	cout << lc.get(3) << endl;
	cout << lc.get(2) << endl;
	lc.set(4,3);
	cout << lc.get(2) << endl;
	cout << lc.get(3) << endl;
	cout << lc.get(4) << endl;

	return 0;
}