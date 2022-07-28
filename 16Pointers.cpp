#include <iostream>
#include <cstring>   //this includes memset
#define log(x) std::cout << x << std::endl;

int main(void){
	//1. initializing pointers to no memory:-
	void * ptrNoMem = 0;
	void * ptrNoMem2 = NULL;
	void * ptrNoMem3 = nullptr;



	//2. but in reality there is no such thing as types
	//they are only there to tell how much the size of the variable should be
	//we can easily bypass this restriction of compiler to use them in their raw form by type casting
	
	int a = 10;
	double * aPtr = (double*)&a;   //thats how simple it is



	//3. now lets check deep referencing
	//we know we can dereference same data type pointers

	void * aPtr2 = &a;
	//*aPtr2 = 11;   //this gives error as the Pointer does not know if the entered value is char(1 byte) short(2 bytes) int(4 bytes)
	//if we had given pointer a type it would have assumed 11 of that type but here it is confused
	


	//4. now lets see how to declared data in the heap
	//the bytes mean that in each byte we will put the same data
	int * heapVar = new int;
	int data = 46;
	int bytes = 1;
	memset(heapVar, data, bytes);   //in memory: 00000000 00000000 00000000 00101110
	log(*heapVar);   //here we put 46 in the first byte of the int variable, we could also do this:-

	memset(heapVar, 1, 4);   //here we put 1 bit in each of four bytes of the int variable so in memory its:-
	//00000001 00000001 00000001 00000001 -> 16843009 in decimal
	log(*heapVar);

	char * heapStr = new char[8];
	data = 65;
	bytes = 8;
	memset(heapStr, data, bytes);   //8*1byte = 8bytes // memory: 01000001 01000001 01000001 01000001 01000001 01000001 01000001 01000001
	log(heapStr);

	//ofcourse we must delete at end the heap memory
	delete heapVar;
	delete[] heapStr;


	//5. pointer to a pointer
	char** doublePointer = &heapStr;
	return 0;
}
