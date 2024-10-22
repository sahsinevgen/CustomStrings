#include"String.h"
#include <string.h>

namespace custom_string {

String::String() {
    size = 1;
    capacity = 1;
    data = new char[1];
    data[0] = '\0';
}

String::String(const char* str) {
    size = strlen(str) + 1;
    capacity = get_new_capacity(size);
    data = new char[capacity];
    strcpy(data, str);
}

String::String(const String& str) {
    size = str.size;
    capacity = get_new_capacity(size);
    data = new char[capacity];
    memcpy(data, str.data, size + 1);
}

String::~String() {
    delete [] data;
}

size_t String::get_capacity() {
    return capacity - 1;
};

size_t String::get_size() {
    return size - 1;
};

size_t String::get_new_capacity(size_t size) {
    return size * 2;
}

}  // ns custom_string