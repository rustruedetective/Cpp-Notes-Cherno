#include "temp.h"

struct Vector2
{
    float x, y;

    Vector2(float x, float y) : x(x), y(y) {}

    // This wont work
    // Why?
    // Because, we need the ostream's operator to take in our object
    // Not ourselves take in a stream object
    // std::ostream operator<<(std::ostream obj){
    //     obj << "X:" << this->x << " Y: " << this->y;
    //     return obj;
    // }

    bool operator==(const Vector2& obj){
        return (this->x == obj.x) && (this->y == obj.y);
    }
};

std::ostream &operator<<(std::ostream &stream, const Vector2 &obj)
{
    stream << "X:" << obj.x << " Y: " << obj.y;
    return stream;
}

int main(void)
{
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.2f, 1.2f);

    logn(position)
    logn(speed)
    logn(powerup)

    logn( (position == speed) )
    logn( (powerup == powerup) )

    return 0;
}