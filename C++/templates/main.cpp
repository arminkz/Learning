#include "vec.hpp"
#include <string>
#include <iostream>

int main() {
    Vec<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i * i);
    std::cout << "size=" << v.size() << " cap=" << v.capacity() << "\n";
    for (int i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
    std::cout << "\n";

    Vec<int> copy = v;        // copy ctor
    copy[0] = 999;
    std::cout << "orig[0]=" << v[0] << " copy[0]=" << copy[0] << "\n"; // independent?

    Vec<int> moved = std::move(v);  // move ctor
    std::cout << "moved size=" << moved.size() << " src size=" << v.size() << "\n";

    Vec<std::string> s;
    s.push_back("hello");
    s.push_back("world");
    std::cout << s[0] << " " << s[1] << "\n";
    return 0;
}
