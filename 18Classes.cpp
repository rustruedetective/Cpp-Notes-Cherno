#include <iostream>
#define log(x) std::cout << x << std::endl

class Player{
	public:
		int x, y;
		int speed;
		void Movement(int xIn, int yIn){
			x += xIn * speed;
			y += yIn * speed;
		}
};

int main(void){
	Player obj;
	obj.x = 10;
	obj.y = 20;
	obj.speed = 2;
	obj.Movement(1, 2);

	log(obj.x);
	log(obj.y);
	return 0;
}
