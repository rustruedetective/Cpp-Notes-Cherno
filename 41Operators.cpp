#include "temp.h"

// even a comma ',' is an operator
// operators are just functions, which can be overloaded

struct Vector2{
    float x, y;

    Vector2(float x, float y) : x(x), y(y) {}

    // Vector2 operator+(Vector2 obj)   // normies use this
    Vector2 operator+(const Vector2 &obj){   // pros use this
        Vector2 result(this->x + obj.x,  this->y + obj.y);
        return result;
    }

    Vector2 operator*(const Vector2 &obj){
        Vector2 result(this->x * obj.x,  this->y * obj.y);
        return result;
    }
    Vector2 operator*(float powerup){
        Vector2 result(this->x * powerup,  this->y * powerup);
        return result;
    }
};

int main(void){
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.2f ,1.2f);

    Vector2 result = position + speed;
    std::cout << result.x << " " << result.y << std::endl;

    result = position + (speed*powerup);
    std::cout << result.x << " " << result.y << std::endl;

    result = position + (speed*1.2f);
    std::cout << result.x << " " << result.y << std::endl;

    return 0;
}