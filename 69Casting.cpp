#include "temp.h"

// C and C++ has two different castings

// Implicit conversions - c++ does it itself and no lose of data while converting
// Explicit conversions - 

// C style cast:-
// Casting:- (datatype2)datatype1Variable
// Casting:- (datatype2)(datatype1Variable + datatype1Variable2)

int main(void){
    // C style cast:-
    int a = 5;
    double value = a;   // Implicit conversion
    double value2 = (double)a;   // Explicit conversion [CASTING]

    double a2 = 5.556;
    int value3 = a2;   // Implicit conversion
    int value4 = (int)a2;   // Explicit conversion [CASTING]
    
    // Use case:-
    double x = 5.5;
    double y = 5.5;
    double z = x+y;   // but we didnt want the decimal part of x
    z = (int)x + y;   // so instead of first truncating it ourselves, we cast it to int to auto truncate it

    return 0;
}