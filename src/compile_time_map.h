#include <array>
#include <algorithm>
template <class KeyType, class ValType, size_t size>
struct CTMap {
    std::array<std::pair<KeyType, ValType>, size> list;
    constexpr ValType at(KeyType key) {
        const auto itr = std::find(begin(list), end(lits), [&key](const auto &v){return v.first == key;});
        if (itr != end(list)) {
            return itr->second;
        } else {
            throw std::range_error("Not Found");
        }
    }
};