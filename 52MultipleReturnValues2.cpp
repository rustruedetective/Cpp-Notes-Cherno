#include "temp.h"
// for tuple:-
#include <functional>
#include <utility>

// tuples and pairs are used
// using arrays and std::vector arrays... is ancient and not the best way

// python can return multiple types, but here we are limited to one type return

// Real ways:-

// 1. Tuple: it is a class that has an n number of variables and it doesnt care about the types
// std::tuple<int, float, int, std::string, char....>   // we can include as many types as we like here
std::tuple<std::string, char, int, std::string> fun(){
    std::tuple<std::string, char, int, std::string> tup = std::make_tuple<std::string, char, int, std::string>("Bing", 'x', 3, "Bing");   // the template arguments are not necessary, but can be given
    tup = std::make_tuple("Bing", 'x', 3, "Bing");
    return tup;
}

// 2. Pair
std::pair<std::string, char> func(){
    std::pair<std::string, char> tup = std::make_pair<std::string, char>("Bing", 'x');   // the template arguments are not necessary, but can be given
    tup = std::make_pair("Bing", 'x');
    return tup;
}

int main(void){
    // 1. Tuple
    auto tup = fun();
    std::tuple<std::string, char, int, std::string> tup2 = fun();

    // accessing
    std::get<0>(tup);   // <index>(tuplename)... yeah fucked up
    std::string str = std::get<0>(tup);
    int x = std::get<2>(tup);


    // 2. Pair
    auto par = func();
    std::pair<std::string, char> par2 = func();

    // accesssing
    std::string str2 = std::get<0>(par);
    char c = std::get<1>(par);
    //or
    std::string str3 = par.first;
    char c2 = par.second;
    
    return 0;
}