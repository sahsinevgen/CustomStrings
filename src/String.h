#ifndef STRING
#define STRING

#include <cstddef>

namespace custom_string {

class String {
public:
    String();

    bool isEqual(const char* str);

    size_t get_capacity() {
        return capacity;
    };
    size_t get_size() {
        return size;
    };
private:
    size_t capacity;
    size_t size;
    char* data;
};

}  // ns custom_string

#endif  //  STRING