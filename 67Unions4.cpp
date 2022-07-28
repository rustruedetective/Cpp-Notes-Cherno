#include <iostream>

// Now how do we improve this?
// accessing x is a pain so lets make it better

struct Vector2{
    float x, y;
};

// with an extra inner struct we made]
// the union can now set memory for only 1 struct of vectors
// and we get benefit of directly accessing the members
// and also compatibility with the function below
struct Vector4{
    union{
        struct{
            float x, y, z, w;
        };
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
    vector.x = 100.0f;

    PrintVector2(vector.a);

    return 0;
}