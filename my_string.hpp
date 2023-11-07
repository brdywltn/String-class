#include <iostream>
#include <cstring>

using namespace std;

// Either take out all of the string stuff below and leave the reference counting,
// or take the reference counting stuff out and leave the string stuff


template <typename T>
class RC {
private:
    T*    referenceCount;
 
public:
    RC() : referenceCount(new T(1)) {}

    template<>
    void addRef(){
        (*referenceCount)++;
    }
    
    template<>
    T get() const {
        return *referenceCount;
    }

    int release(){
        return --(*referenceCount);
    }

    ~RC() {
        if (*referenceCount == 0) {
            delete referenceCount;
        }
    }
};

template <typename T>
class my_string {
private:
    T*      refCount;
    char*   full_string;

public:
    my_string();
    my_string(const char*);

    my_string(my_string const& s);
    my_string& operator= (my_string const& s);
    ~my_string();

    char getChar(const int& i) const;
    void setChar(const int& i, const char& c);
    void print() const;
};