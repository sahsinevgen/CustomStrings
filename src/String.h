#ifndef STRING
#define STRING

#include <gtest/gtest_prod.h>
#include <cstddef>

namespace custom_string {

class String {
public:
    String();
    String(const char str);
    String(const char* str);
    String(const String& str);
    ~String();

    size_t get_capacity() const;
    size_t get_size() const;

    friend bool operator==(const String& s1, const String& s2);
    friend bool operator!=(const String& s1, const String& s2);
    friend bool operator<(const String& s1, const String& s2);
    friend bool operator>(const String& s1, const String& s2);
    friend bool operator<=(const String& s1, const String& s2);
    friend bool operator>=(const String& s1, const String& s2);

    char operator[](int i) const;
    char& operator[](int i);

    String& operator+=(const char c);
    String& operator+=(const char* c_str);
    String& operator+=(const String& str);

    friend String operator+(const String& s1, const String& s2);
    friend String operator+(const char c, const String& s);
    friend String operator+(const String& s, const char c);
    friend String operator+(const char* s1, const String& s2);
    friend String operator+(const String& s1, const char* s2);

    String& operator=(const String& str);
    String& operator=(const char* c_str);
private:
    void reserve(size_t new_size, bool need_copy = true);
    static size_t get_new_capacity(size_t size);

    size_t capacity;
    size_t size;
    char* data;

private:
    FRIEND_TEST(ConstructorTests, EmptyString);
    FRIEND_TEST(ConstructorTests, FromChar);
    FRIEND_TEST(ConstructorTests, FromCStr);
    FRIEND_TEST(ConstructorTests, FromString);
};

}  // ns custom_string

#endif  //  STRING