

// https://leetcode.com/problems/time-based-key-value-store/
// use unordered_map<map<>> and lower_bound func. you don't need a map tbh because you can use vector and
// binary search instead.

class TimeMap {
public:

    unordered_map<string, map<int, string>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][-timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = m[key].lower_bound(-timestamp);

        return it == m[key].end() ? "":it->second;

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */