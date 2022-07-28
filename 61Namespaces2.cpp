#include <iostream>
#include <string>   // for printing string
#include <algorithm>   // contains reverse


// Nested namespaces:-
namespace a{ namespace functions{
        void print(const char* str)
        {
            using namespace std;
            cout << "Error" << endl;
        }
    }
}




int main(void)
{
    print("Harry Potter");
    // using namespace apple;
    // print("Harry Potter");
    // using namespace orange;
    // print("Harry Potter");

    return 0;
}