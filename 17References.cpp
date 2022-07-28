#include <iostream>
#define log(x) std::cout << x << std::endl;

void function1(int * x){
	(*x)++;
}

void function2(int& x){
	x++;
}

int main(void){
	int a = 10;
	int * aPtr = &a;
	int& aRef = a;

	log(*aPtr);
	log(aRef);
	log("---------");

	//1. actually the reference acts like the original variable's dereferenced address
	function1(aPtr);
	function2(aRef);
	log(a);


	//2. actually a is assgined the value of b
	int b = 20;
	aRef = b;
	log(a);

	return 0;
}
