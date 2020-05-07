#include <iostream>

class Base {
private:
    int v;
public:
    Base(int v_) { v = v_; }
    ~Base() {}
};

class Derived : public Base {
private:
    int vv;
public:
    Derived(int v_, int vv_);
    ~Derived() {}
};
Derived::Derived(int v_, int vv_)
///////////// (a) //////////////
: Base(v_)
{
    vv = vv_;
}
////////////////////////////////