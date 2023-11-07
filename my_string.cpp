#include "my_string.hpp"

template<>
my_string<int>::my_string() {
    full_string = nullptr;
}

template<>
my_string<int>::my_string(const char* str) {
    full_string = new char[strlen(str) + 1];
    strcpy(full_string, str);
    refCount = new int(1);
}

template<>
my_string<int>::my_string(my_string const& s) {
    full_string = new char[strlen(s.full_string) + 1];
    strcpy(full_string, s.full_string);
    refCount = s.refCount;
    *refCount = *refCount + 1;
}

template<>
my_string<int>& my_string<int>::operator=(my_string const& s) {
    delete[] full_string;
    full_string = new char[strlen(s.full_string)];
    full_string = s.full_string;
}

template<>
my_string<int>::~my_string() {
    *refCount = *refCount - 1;
    if ((*refCount - 1) == 0) delete[] full_string;
} 

template<>
char my_string<int>::getChar(const int& i) const {
    for (int j = 0; j < strlen(full_string); ++j){
        if (i == j) {
            return full_string[j];
        }
    }
}

template<>
void my_string<int>::setChar(const int& i, const char& c) {
   char ch = i;

   for (int j = 0; j < strlen(full_string); ++j) {
        if (ch == j) {
            full_string[j] = c;
        }
   }
}

template<>
void my_string<int>::print() const {
    char * string_to_print = full_string;
    
    for (int i = 0; i < strlen(string_to_print); ++i){
        cout << string_to_print[i];
    }
    cout << " [" << *(refCount) << "]" << endl;
}

