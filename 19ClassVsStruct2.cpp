#include <iostream>
#define log(x) std::cout << x << std::endl;

// but c does not have classes
// here is a trick for backward compatibility
#define struct class

struct a{
    int x = 10;
    public:
    int getx(){
        return x;
    }
};

struct b{
    int x = 20;
    public:
    int getx(){
        return x;
    }
};

int main(void){
    a obj;
    b obj2;
    
    log(obj.getx());
    log(obj2.getx());

    return 0;
}