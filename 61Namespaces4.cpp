#include <iostream>
#include <string>   // for printing string
#include <algorithm>   // contains reverse

// Possible workaround for 3:

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
    using apple::print;
    print("Harry Potter");
    // using orange::print;
    // print("Harry Potter");   // nope, not for second time

    return 0;
}