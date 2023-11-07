#include <iostream>
#include <cstring>

using namespace std;

// Either take out all of the string stuff below and leave the reference counting,
// or take the reference counting stuff out and leave the string stuff


// template <typename T>
// class RC {
// private:
//     T*      pointerData;
//     int*    referenceCount;
 
// public:
//     RC(T* data) : pointerData(data), referenceCount(new int(1)) {}

//     void addRef(){
//         (*referenceCount)++;
//     }
    
//     int* get() const {
//         return *referenceCount;
//     }

//     int release(){
//         return --(*referenceCount);
//     }

//     ~RC() {
//         if (*referenceCount == 0) {
//             delete pointerData;
//             delete referenceCount;
//         }
//     }
// };

// template <class T>
class my_string {
private:
    char*   full_string;
    //RC<T>*  refCount;
    int* refCount;

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