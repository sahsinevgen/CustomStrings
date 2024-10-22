#include"String.h"
#include <string.h>

namespace custom_string {

String::String() {
    size = 0;
    capacity = 0;
    data = new char[1];
    data[0] = '\n';
}

bool String::isEqual(const char* str) {
    return strcmp(data, str) == 0;
}

}  // ns custom_string