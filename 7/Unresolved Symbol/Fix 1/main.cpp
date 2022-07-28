// so here we have an important lesson, if it (function) was never called
// the linker does not bother checking if some declaration was defined or not!



int func();

int main(void){
    // func();
    return 0;
}