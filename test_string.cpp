#include "my_string.cpp"

int main() {
    my_string<int> s("Hello World");
    s.print();
    
    {
        my_string<int> t = s;
        s.print();
        t.print();
        cout << s.getChar(1) << endl;
        s.print();
        t.print();
    }
    s.setChar(1, 'E');
    s.print();
}