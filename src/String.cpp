#include"String.h"
#include <string.h>

namespace custom_string {

String::String() {
    size = 1;
    capacity = 1;
    data = new char[1];
    data[0] = '\0';
}

String::String(const char c) {
    size = 2;
    capacity = 2;
    data = new char[2];
    data[0] = c;
    data[1] = '\0';
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
    memcpy(data, str.data, size);
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
        if (s1[i] != s2[i]) {
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
        if (s1[i] == s2[i]) {
            continue;
        }
        return s1[i] < s2[i];
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

char String::operator[](int i) const {
    return data[i];
}

char& String::operator[](int i) {
    return data[i];
}

String& String::operator+=(const char c) {
    reserve(get_size() + 1);
    data[size - 1] = c;
    data[size] = '\0';
    size += 1;
    return *this;
}

String& String::operator+=(const char* c_str) {
    int c_str_len = strlen(c_str);
    reserve(get_size() + c_str_len);
    memcpy(data + (size - 1), c_str, c_str_len);
    size += c_str_len;
    data[get_size()] = '\0';
    return *this;
}

String& String::operator+=(const String str) {
    reserve(get_size() + str.get_size());
    memcpy(data + (size - 1), str.data, str.get_size());
    size += str.get_size();
    data[get_size()] = '\0';
    return *this;
}

String operator+(const String s1, const String s2) {
    String ans = s1;
    ans += s2;
    return ans;
}

String operator+(const char c, const String s) {
    return String(c) + s;
}

String operator+(const String s, const char c) {
    return s + String(c);
}

String operator+(const char* s1, const String s2) {
    return String(s1) + s2;
}

String operator+(const String s1, const char* s2) {
    return s1 + String(s2);
}

void String::reserve(size_t new_size) {
    new_size += 1;

    if (new_size > capacity) {
        capacity = get_new_capacity(new_size);
        char* new_data = new char[capacity];
        memcpy(new_data, data, size);
        delete[] data;
        data = new_data;
    }
}

size_t String::get_new_capacity(size_t size) {
    return size * 2;
}

}  // ns custom_string