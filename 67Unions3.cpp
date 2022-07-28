#include <iostream>

// Scenario : We want to make the Vector4 struct compatible with Vector2
// We go on to do this by making a union inside Vector4 of two Vector2s as the Vector4 is nothing more than two Vector2s

struct Vector2{
    float x, y;
};

// Now we can achieve same results without the inner union and inner struct
// but next example shows how union adds a more fluid way to access data
// all the while having the same memory
struct Vector4{
    union{
        struct{
            Vector2 a, b;
        };
    };
};

void PrintVector2(const Vector2& vector){
    std::cout << vector.x << ", " << vector.y << "\n";
}

int main(void){
    Vector4 vector = { 1.0f, 2.0f, 3.0f, 4.0f };
    vector.a.x = 100.f;

    PrintVector2(vector.a);

    return 0;
}