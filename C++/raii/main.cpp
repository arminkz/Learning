#include "SharedPtr.hpp"
#include <iostream>
#include <utility>

struct W {
    int x;
    ~W() { std::cout << "~W(" << x << ")\n"; }
};

int main() {
    SharedPtr<W> a(new W{1});
    { SharedPtr<W> b = a; }            // copy ctor + dtor (W{1} must survive)

    SharedPtr<W> c(new W{2});
    c = a;                             // copy-assign: W{2} should die here

    SharedPtr<W> d = std::move(a);     // move ctor: a now empty
    std::cout << "a empty? " << (a.get() == nullptr) << "\n";

    SharedPtr<W> e(new W{3});
    e = std::move(d);                  // move-assign: W{3} should die here

    std::cout << "end main\n";         // W{1} dies after this
}
