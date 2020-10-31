#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "stack.h"

int main()
{ 
	int num = 40;
	Stack_t stack;
	int top = -1;
	StackInit(&stack);
	
	for(int i = 2; num != 1; i++) {
		while(num % i == 0) {
			StackPush(i, &stack);
			num = num / i;
		}
	}
	
	while(!StackEmpty(&stack)) {
		StackPop(&top, &stack);
		printf("%d ", top);
	}
	printf("\n");
	return 0;
}
