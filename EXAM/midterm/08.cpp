#include <iostream>
using namespace std;

class IntVector {
private:
    int *arr;
    int len;
public:
    IntVector(int len_) : len(len_), arr(new int[len]) { }
    IntVector(const IntVector &v) : len(v.len), arr(new int[len])
    { memcpy(arr, v.arr, sizeof(int) * len); }
    IntVector() : len(0), arr(nullptr) { }
    ~IntVector() { delete[] arr; }
    int length() const { return len; }

    int &operator[](int i)
    {
        return arr[i];
    }

    /////////// (a) ////////////
    int &operator[](int i) const
    {
        return arr[i];
    }
    ////////////////////////////
};

ostream& operator<<(ostream& os, const IntVector& v)
{
    for(int i = 0; i < v.length(); i++)
        os << v[i] << " ";
    return os;
}