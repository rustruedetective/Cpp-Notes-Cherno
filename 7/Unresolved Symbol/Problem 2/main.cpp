// we never called out wrapper function but still it gives us an error
// why?
//because the linker says even if funcWrapper is not used here in this file
//it could be used in other files



int func();

int funcWrapper(){
    func();
}

int main(void){
    return 0;
}