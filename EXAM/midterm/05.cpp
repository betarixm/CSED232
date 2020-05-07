class FakeNamespace
{
public:
    static void func();
    static void func2();
    static void func3();
};

int main() {
    FakeNamespace::func();
    return 0;
}