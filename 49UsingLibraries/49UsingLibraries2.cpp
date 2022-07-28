#include "../temp.h"
#include <GLFW/include/GLFW/glfw3.h>

// 1. including header/include path
// g++ .\49UsingLibraries2.cpp -I ./Dependencies/

/* This is still working... */
// 2. including library path
// g++ .\49UsingLibraries2.cpp -I ./Dependencies/ -L ./Dependencies/GLFW/lib-mingw/ -l libglfw3

int main(void){
   glfwInit();
   return 0;
}