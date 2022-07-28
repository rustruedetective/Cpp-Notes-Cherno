#include <iostream>
#include <string>   // for printing string
#include <algorithm>   // contains reverse

// Alias:
// useful in nested namespaces

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

namespace outer{ namespace inner{

        void print(const char* str)
        {
            using namespace std;
            cout << str << endl;
        }
    }
}

int main(void)
{
    namespace a = apple;
    namespace o = orange;

    // Aliases
    print("Harry Potter");
    a::print("Harry Potter");
    o::print("Harry Potter");

    // Aliases for scoped namespaces
    namespace scopyguy = outer::inner;
    scopyguy::print("Not Harry Potter");
    return 0;
}