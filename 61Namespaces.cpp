#include <iostream>
#include <string>   // for printing string
#include <algorithm>   // contains reverse

// When we have same symbols (e.g same functions with same parameters trying to be overloaded which is an error)
// and we dont want to change them, we can put them inside namespaces
// C does not have namespaces
// e.g they have functions glfwinit() instead of some glfw::init()

// Same symbol errors:
// classes, functions, variables all their identifiers

// This is the only purpose of namespace... to resolve naming errors

void print(const char* str)
{
    using namespace std;
    cout << "Error" << endl;
}

namespace apple
{
    void print(const char* str)
    {
        using namespace std;
        cout << str << endl;
    }
}

namespace orange
{
    void print(const char* str)
    {
        using namespace std;
        string temp = str;
        std::reverse(temp.begin(), temp.end());
        cout << temp << endl;
    }
}

int main(void)
{
    print("Harry Potter");
    // using namespace apple;
    // print("Harry Potter");   // ERROR: more than one instance of overloaded function "print" matches the argument list:
    // using namespace orange;
    // print("Harry Potter");

    return 0;
}