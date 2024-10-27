#include"String.h"
#include <string.h>
#include <iostream>

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

String::String(String&& str) {
    size = str.size;
    capacity = str.capacity;
    data = str.data;
    str.make_consumed();
}

String::~String() {
    free_data_if_not_consumed();
}

size_t String::get_capacity() const {
    return capacity - 1;
};

size_t String::get_size() const {
    return size - 1;
};

bool operator==(const String& s1, const String& s2) {
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

bool operator!=(const String& s1, const String& s2) {
    return !(s1 == s2);
}

bool operator<(const String& s1, const String& s2) {
    int i = 0;

    for (; i < s1.get_size() && i < s2.get_size(); i++) {
        if (s1[i] == s2[i]) {
            continue;
        }
        return s1[i] < s2[i];
    }

    return i != s2.get_size();
}

bool operator>(const String& s1, const String& s2) {
    return s2 < s1;
}

bool operator<=(const String& s1, const String& s2) {
    return !(s1 > s2);
}

bool operator>=(const String& s1, const String& s2) {
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

String& String::operator+=(const String& str) {
    reserve(get_size() + str.get_size());
    memcpy(data + (size - 1), str.data, str.get_size());
    size += str.get_size();
    data[get_size()] = '\0';
    return *this;
}

String operator+(const String& s1, const String& s2) {
    String ans = s1;
    ans += s2;
    return ans;
}

String operator+(const char c, const String& s) {
    return String(c) + s;
}

String operator+(const String& s, const char c) {
    return s + String(c);
}

String operator+(const char* s1, const String& s2) {
    return String(s1) + s2;
}

String operator+(const String& s1, const char* s2) {
    return s1 + String(s2);
}

String& String::operator=(const String& str) {
    reserve(str.get_size(), false);
    memcpy(data, str.data, str.get_size());
    data[str.get_size()] = '\0';
    size = str.size;
    return *this;
}

String& String::operator=(String&& str) {
    size = str.size;
    capacity = str.capacity;
    data = str.data;
    str.make_consumed();
    return *this;
}

String& String::operator=(const char* c_str) {
    size_t n = strlen(c_str);
    reserve(n, false);
    std::cout << data << std::endl;
    std::cout << c_str << std::endl;
    memcpy(data, c_str, n);
    data[n] = '\0';

    std::cout << data << std::endl;
    std::cout << c_str << std::endl;
    size = n + 1;
    return *this;
}

void String::reserve(size_t new_size, bool need_copy) {
    new_size += 1;

    if (new_size > capacity) {
        capacity = get_new_capacity(new_size);
        char* new_data = new char[capacity];
        if (need_copy) {
            memcpy(new_data, data, size);
        }
        free_data_if_not_consumed();
        data = new_data;
    }
}

void String::free_data_if_not_consumed() {
    if (!is_consumed()) {
        delete[] data;
    }
}

void String::make_consumed() {
    size = capacity = 0;
    data = nullptr;
}

size_t String::get_new_capacity(size_t size) {
    return size * 2;
}

bool String::is_consumed() const {
    return capacity == 0;
}

}  // ns custom_string