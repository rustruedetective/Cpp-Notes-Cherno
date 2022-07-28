#include "temp.h"

// How about a hack in class templates?
// We know templates dont get created unless called
// And we have seen that std::tuple<...> uses std::get<index>() to get value...so

// Now you know the difference in typename and class and other data types in template<here...>

// Want to make an array on stack that takes size at compile time?
template <int T>
class Array{
private:
    int arr[T];
};

int main(void){
    // Note that this is limited to compile time and not to run time
    Array<5> obj;
    return 0;
}