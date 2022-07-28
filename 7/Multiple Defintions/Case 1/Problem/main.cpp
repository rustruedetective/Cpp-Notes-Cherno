// lets start with the quickest way to mess up
// The object codes for main and foo are both created, and there is definition
// in main and foo, as we had included it via #include


#include "foo.cpp"

int main(void){
    foo();
    return 0;
}