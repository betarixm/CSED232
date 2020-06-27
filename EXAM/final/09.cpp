class Base {
    // ...
};

class Derived : public Base {
    // ...
};

int main() {
    int a = 5;
    double b;
    const int* c = &a;

    b = static_cast<double>(a);
    int* d = const_cast<int*>(c);
    int f = 0xA0000000;
    unsigned char* e = reinterpret_cast<unsigned char*>(f);
    Base* p = new Derived;
    Derived* p2 = dynamic_cast<Derived*>(p);

    return 0;
}