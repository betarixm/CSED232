#include <iostream>

class Vehicle {
public:
    Vehicle() {}
    virtual ~Vehicle() {} void show() const;
protected:
    virtual int num_wheels() const { return 0; } // (a)
};

void Vehicle::show() const
{
    const int n_wheels = num_wheels();
    std::cout << "Num wheels: " << n_wheels << std::endl;
}


class Sedan : public Vehicle
{
public:
    Sedan() {}
    ~Sedan() {} protected:
protected:
    int num_wheels() const override { return 4; } // (b)
};


class Motorcycle : public Vehicle
{
public:
    Motorcycle() {}
    ~Motorcycle() {}
protected:
    int num_wheels() const override { return 2; } // (c)
};

int main()
{
    Vehicle *v[2];
    v[0] = new Sedan();
    v[1] = new Motorcycle();
    for(int i = 0; i < 2; i++) v[i]->show();
    delete v[0];
    delete v[1];
    return 0;
}