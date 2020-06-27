#include <iostream>

template<typename T>
class Vec2D {
public:
    Vec2D() {}
    Vec2D(T x_, T y_) : x(x_), y(y_) {}
    T x, y;
};

// Answer
template<typename T, typename U>
auto operator+(Vec2D<T> a, Vec2D<U> b) -> Vec2D<decltype(a.x + b.x)>
//
{
    return Vec2D<decltype(a.x+b.x)>(a.x + b.x, a.y + b.y) ;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vec2D<T>& v)
{
    os << "[" << v.x << ", " << v.y << "]";
    return os;
}

int main()
{
    using namespace std;
    Vec2D<int> a(1,2);
    Vec2D<float> b(3.1f, 2.0f);
    cout << a << " + " << b << " = " << a+b << endl;
    return 0;
}