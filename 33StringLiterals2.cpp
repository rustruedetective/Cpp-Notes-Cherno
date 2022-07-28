#include "temp.h"
#include <string>
#include <cstring>

// wide characters need L in front of the string literal, its specifies that characters in string literal are wide
// rest remain same as normal string/array of chars

// wchar_t is a wide character of 2 bytes
// char16_t is of 2 bytes
// char32_t is of 4 bytes

// windows uses 2 bytes for character, linux uses 4 bytes for character

int main(void){
    const wchar_t * ptr = L"hi im billy";

    const char16_t * ptr2 = u"hi im billy";   // utf-16 ,-std=c++11
    const char32_t * ptr3 = U"hi im billy";   // utf-32

    const char * ptr4 = u8"hi im billy";   // utf-8

    return 0;
}