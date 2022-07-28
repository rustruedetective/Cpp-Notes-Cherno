#include <iostream>
#include <string>   // for printing string
#include <algorithm>   // contains reverse

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
        std::reverse(temp.begin(), temp.end());   // here again we wouldnt know if reverse is from std or some other place...unless
        cout << temp << endl;
    }
}

int main(void)
{
    print("Harry Potter");
    using namespace apple;
    apple::print("Harry Potter");   // we get an error even when we said using namespace apple; so using apple::
    using namespace orange;
    orange::print("Harry Potter");

    return 0;
}