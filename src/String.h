#ifndef STRING
#define STRING

#include <gtest/gtest_prod.h>
#include <cstddef>

namespace custom_string {

class String {
public:
    String();
    String(const char* str);
    String(const String& str);
    ~String();

    size_t get_capacity();
    size_t get_size();
private:
    static size_t get_new_capacity(size_t size);
    size_t capacity;
    size_t size;
    char* data;

private:
    FRIEND_TEST(ConstructorTests, EmptyString);
    FRIEND_TEST(ConstructorTests, FromCStr);
    FRIEND_TEST(ConstructorTests, FromString);
};

}  // ns custom_string

#endif  //  STRING