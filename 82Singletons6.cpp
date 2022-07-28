#include "temp.h"

// why are we even using classes? what happens if we just use a namespace
// well you can...there is no functional difference

// the public and private scopes can be simulated by a header file's declaration and its cpp definition

// but theres no downside of using classes
// plus you can assign its instance to your auto& pointer

namespace Random{
    static float s_randomNo = 0.5;
    static float Float(){ return s_randomNo; }
}


int main(void){
    float ran = Random::Float();
    logn( ran )

    return 0;
}