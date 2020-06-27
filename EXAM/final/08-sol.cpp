#include <iostream>
class SomeClass{
public:
    SomeClass(int _n): n(_n) {};
    ~SomeClass(){
        std::cout << n << std::endl;
    }
private:
    int n;
};
class SomeException{
public:
    std::string what() { return err;}
private:
    std::string err = "err";
};

bool b_error = false;

void foo() {
    SomeClass a(1);
    SomeClass* p = new SomeClass(2);
    // ...
    if(b_error) {
        delete p;
        throw SomeException();
    }
    // ...
    delete p;
}

void bar() {
    SomeClass a(3);
    SomeClass* p = new SomeClass(4);
    // ...
    try{
        foo();
    }
    catch(SomeException& e){
        delete p;
        throw e;
    }
    // ...
    delete p;
}

int main() {
    try {
        bar();
    }
    catch(SomeException& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}