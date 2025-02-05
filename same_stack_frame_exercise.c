#include <stdio.h>

void printStackPointerDifferences(){
	static void* last_sp = NULL;
	void* curr_sp = __builtin_frame_address(0);
	long diff = (char*)last_sp - (char*)curr_sp;
	if (last_sp == NULL){
		last_sp = curr_sp;
		diff = 0;
	}
	printf("---------------------------------\n");
	printf("Stack pointer offset: %ld bytes\n", diff);
    printf("---------------------------------\n");
}

void printArgsThree(int c){
	printf("Inside printArgsThree, argument = %d\n", c);
	printStackPointerDifferences();
}

void printArgsTwo(int b){
	printf("Inside printArgsTwo, argument = %d\n", b);
	printStackPointerDifferences();
}

void printArgsOne(int a){
	printf("Inside printArgsOne, argument = %d\n", a);
	printStackPointerDifferences();
}


int main(void){
	printArgsOne(1);
	printArgsTwo(2);
	printArgsThree(3);
}