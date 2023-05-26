#include <iostream>
#include <unordered_map>
#include <vector>

template<typename Key, typename Value>
class Cache {
private:
    std::unordered_map<Key, std::vector<Value>> data;
public:
    // 添加Key-Value对
    void Put(const Key& key, const Value& value) {
        data[key].push_back(value);
    }

    void Get(const Key& key) {
        auto it = data.find(key);
        if (it != data.end()) {
            return it->second;
        }
        return {};
    }
   
};