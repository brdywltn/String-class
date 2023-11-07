#include "my_string.hpp"

my_string::my_string() {
    full_string = nullptr;
}

my_string::my_string(const char* str) {
    full_string = new char[strlen(str) + 1];
    strcpy(full_string, str);
    refCount = new int(1);
}


my_string::my_string(my_string const& s) {
    full_string = new char[strlen(s.full_string) + 1];
    strcpy(full_string, s.full_string);
    refCount = s.refCount;
    *refCount = *refCount + 1;
}

my_string& my_string::operator=(my_string const& s) {
    delete[] full_string;
    full_string = new char[strlen(s.full_string)];
    full_string = s.full_string;
}

my_string::~my_string() {
    *refCount = *refCount - 1;
    if ((*refCount - 1) == 0) delete[] full_string;
} 

char my_string::getChar(const int& i) const {
    for (int j = 0; j < strlen(full_string); ++j){
        if (i == j) {
            return full_string[j];
        }
    }
}

void my_string::setChar(const int& i, const char& c) {
   char ch = i;

   for (int j = 0; j < strlen(full_string); ++j) {
        if (ch == j) {
            full_string[j] = c;
        }
   }
}

void my_string::print() const {
    char * string_to_print = full_string;
    
    for (int i = 0; i < strlen(string_to_print); ++i){
        cout << string_to_print[i];
    }
    cout << " [" << *(refCount) << "]" << endl;
}

