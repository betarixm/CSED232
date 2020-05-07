#include<iostream>
#include<cstring>
class String {
private:
    char *str;
    int len;
public:
    String(const char *s);
    String(const String &st); // copy constructor
    String(); // default constructor
    ~String(); // destructor
    int length() const { return len; }
    String &operator=(const String &st);
    operator char* () const; // 추가된 코드
};

String::String() { len = 0; str = new char[1]; str[0] = '\0'; }
String::String(const char *s)
{ len = std::strlen(s); str = new char[len+1]; std::strcpy(str, s); }
String::String(const String &s)
{ len = s.len; str = new char[len+1]; std::strcpy(str, s.str); }
String::~String() { delete[] str; }

String& String::operator=(const String &st) {
    delete[] str;
    len = st.len;
    str = new char[len+1];
    strcpy(str, st.str);
    return *this;
}

// 추가된 코드
String::operator char *() const {
    return str;
}

int main() {
    String pennywise("You'll float too.");
    char georgie[100];
    std::strcpy(georgie, pennywise);
    return 0;
}