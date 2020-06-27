#include <iostream>

class Base {
public:
    Base(int n=0) : m_n(n) {}
    virtual ~Base() {}
    virtual void display() const {
        std::cout << "Base: " << m_n << std::endl;
    }
private:
    int m_n;
};

class Derived1 : public Base {
public:
    Derived1(int n=0) : Base(2*n), m_n(n) {}
    ~Derived1() {}
    void display() const {
        Base::display();
        std::cout << "Derived1: " << m_n << std::endl;
    }
private:
    int m_n;
};

class Derived2 : public Base { public:
    Derived2(int n=0) : Base(3*n), m_n(n) {}
    ~Derived2() {}
    void display() const {
        Base::display();
        std::cout << "Derived2: " << m_n << std::endl;
    }
private:
    int m_n;
};

class DDerived : public Derived1, public Derived2 {
public:
    DDerived(int n, int m) : Derived1(n), Derived2(m) {}
    ~DDerived() {}
    void display() const {
        Derived1::display();
        Derived2::display();
    }
};

int main()
{
    std::unique_ptr<Derived1> pt(new DDerived(3,5));
    pt->display();
    return 0;
}