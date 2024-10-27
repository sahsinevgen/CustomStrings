#include<algorithm>
#include<cctype>
#include<iostream>
#include<vector>
#include"src/String.h"

using std::sort;
using std::tolower;
using std::cin, std::cout, std::endl;
using std::vector;
using custom_string::String;

int main() {
    int n;
    cin >> n;

    vector<String> strs(n);

    //  I don't make smart operator>> for String
    //  Create buffre with new for cin 
    char* buffer = new char[1024];
    for (int i = 0; i < n; i++) {
        cin >> buffer;
        strs[i] = buffer;
    }
    delete[] buffer;

    sort(strs.begin(), strs.end(), 
        [](const String& s1, const String& s2) {
            int n1 = s1.get_size();
            int n2 = s2.get_size();
            
            int i = 0;
            for (; i < n1 && i < n2; i++) {
                char c1 = tolower(s1[i]);
                char c2 = tolower(s2[i]);

                if (c1 == c2) {
                    continue;
                }

                return c1 > c2;
            }

            return i != n1;
        }
    );

    //  Also no operator<< for String
    for (int i = 0; i < n; i++) {
        cout << strs[i].get_data() << "\n";
    }
}