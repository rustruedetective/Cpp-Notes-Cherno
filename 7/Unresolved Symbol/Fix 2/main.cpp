// we never called out wrapper function but still it gives us an error
// why?
// because the linker says even if funcWrapper is not used here in this file
// it could be used in other files


// So solution is to make the wrapper a static global function
// so linker knows this cant be called anywhere else


// hmmm it should have worked, dont know whats wrong here


int func();

static int funcWrapper(){
    func();
    return 0;
}

int main(void){
    return 0;
}