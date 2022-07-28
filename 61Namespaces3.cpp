#include <iostream>
#include <string>   // for printing string
#include <algorithm>   // contains reverse

// I think the reason we get errors is because
// Namespace does not work the way we think it does
//

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