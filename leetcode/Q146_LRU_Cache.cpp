#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

class LRUCache {
public:
	int cap;
	int size;
	unordered_map<int, int> valuemap;
	map<int, int> keytime;
	map<int, int> timekey;
	int count; // count the time

	LRUCache(int capacity) {

		cap = capacity;
		size = 0;
		count = 0;
	}

	int get(int key) {
		count++;
		if (valuemap.find(key) != valuemap.end())
		{
			int time = keytime[key];
			timekey.erase(time);
			timekey.insert(pair<int, int>(count, key));
			keytime[key] = count;
			return valuemap[key];
		}
		else
			return -1;
	}

	void set(int key, int value) {
		count++;
		if (valuemap.find(key) == valuemap.end())
		{
			// not find key in the cache

			if (size == cap)
			{
				// cache full, need deletion
				map<int, int>::iterator it = timekey.begin();
				int keytodelete = it->second;
				timekey.erase(it);
				keytime.erase(keytodelete);
				valuemap.erase(keytodelete);
				size--;
			}

			valuemap.insert(pair<int, int>(key, value));
			keytime.insert(pair<int, int>(key, count));
			timekey.insert(pair<int, int>(count, key));
			size++;

		}
		else
		{
			// find key in cache
			int time = keytime[key];
			timekey.erase(time);
			timekey.insert(pair<int, int>(count, key));
			keytime[key] = count;
			valuemap[key] = value;
		}
	}
};