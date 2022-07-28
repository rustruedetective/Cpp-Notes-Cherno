#include <iostream>

int main(void){
	bool x = true;
	if(x == true) 1;   //compare this to the bottom one which is better as x will result in true after all
	if(x) 1;

	int y = 20;
	int *yPtr = NULL;
	if(!yPtr) std::cout << "Pointer set to Null." << std::endl;
	yPtr = &y;
	if(yPtr) std::cout << "Pointer set to value." << std::endl;
	return 0;
}
