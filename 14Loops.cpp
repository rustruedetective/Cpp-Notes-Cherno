#include <iostream>

int main(void){
	int i = 0;
	for(; i < 6; i++) 1;
	std::cout << i << std::endl;

	for(int y = 0; y < 6; y++) 1;
	//std::cout << y << std::endl;   //cant be used as it s a local scope
	return 0;
}
