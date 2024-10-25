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

size_t String::get_capacity() const {
    return capacity - 1;
};

size_t String::get_size() const {
    return size - 1;
};

bool operator==(const String s1, const String s2) {
    if (s1.get_size() != s2.get_size()) {
        return false;
    }

    for (int i = 0; i < s1.get_size(); i++) {
        if (s1.data[i] != s2.data[i]) {
            return false;
        }
    }

    return true;
}

bool operator!=(const String s1, const String s2) {
    return !(s1 == s2);
}

bool operator<(const String s1, const String s2) {
    int i = 0;

    for (; i < s1.get_size() && i < s2.get_size(); i++) {
        if (s1.data[i] == s2.data[i]) {
            continue;
        }
        return s1.data[i] < s2.data[i];
    }

    return i != s2.get_size();
}

bool operator>(const String s1, const String s2) {
    return s2 < s1;
}

bool operator<=(const String s1, const String s2) {
    return !(s1 > s2);
}

bool operator>=(const String s1, const String s2) {
    return !(s1 < s2);
}

size_t String::get_new_capacity(size_t size) {
    return size * 2;
}

}  // ns custom_string