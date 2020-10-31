#include <stdio.h>
#include <limits.h>
#include "stack.h"

/**
	* E2: Let stack_ptr be a pointer to a stack'stack of integers and item be an integer variable.
	  Use the functions Push, Pop, Initialize, Empty, and Full to write functions doing
	  each of the following tasks. [You may declare additional variables in your functions
      if needed.]
 */
int ReturnTop(Stack_t *ps);
int ReturnThird(Stack_t *ps);
int ReturnButtom(Stack_t *ps);
void DeleteOccurrences(Stack_t *ps, int key);

void Display(StackEntry_t e) {
	printf("%d\t", e);
}

int main() {
	Stack_t s;
	StackInit(&s);
	
	StackPush(1, &s);
	StackPush(55, &s);
	StackPush(1, &s);
	StackPush(30, &s);
	StackPush(1, &s);
	StackPush(8, &s);
	
	TraverseStack(&s, Display);
	printf("\n");
	DeleteOccurrences(&s, 1);
	TraverseStack(&s, Display);
	printf("\n");
	return 0;
}

/**
	* a. Return the top element of the stack and leave the top element unchanged. If
	     the stack is empty, return INT.MAX.
 */
int ReturnTop(Stack_t *ps) {
	int top = 0;
	if(!StackEmpty(ps)){
		StackPop(&top, ps);
		StackPush(top, ps);
		return top;
	}
	return INT_MAX;
}

/**
	* b. Return the third element from the top of the stack, provided that the stack con-
	     tains at least three integers. If not, return INT.MAX. Leave the stack unchanged.
*/
int ReturnThird(Stack_t *ps) {
#define ELMENT_POS 3

	if(StackSize(ps) >= 3) {
		int temp[ELMENT_POS] = {0, 0, 0};
		for(int i = 0; i < ELMENT_POS; i++) {
			StackPop(&temp[i], ps);
		}
		for(int i = 0; i < ELMENT_POS; i++) {
			StackPush(temp[(ELMENT_POS - 1) - i], ps);
		}
		
		return temp[ELMENT_POS - 1];
	}
	return INT_MAX;
}


/*
	* c. Return the bottom element of stack (or INTMAX if stack is empty), and leave
	     the stack unchanged. [HinV. Use a second stack.]
*/ 
int ReturnButtom(Stack_t *ps) {
	if(!StackEmpty(ps)) {
		int temp = 0, buttom = 0;
		Stack_t s;
		StackInit(&s);
		
		while(!StackEmpty(ps)) {
			StackPop(&temp, ps);
			StackPush(temp, &s);
		}
		buttom = temp;
		while(!StackEmpty(&s)) {
			StackPop(&temp, &s);
			StackPush(temp, ps);
		}
		
		ClearStack(&s);
		return buttom;
	}
	return INT_MAX;
}

/**
	  * d. Delete all occurrences of x from the stack, leaving the other elements of the
	       stack in the same order.
*/
void DeleteOccurrences(Stack_t *ps, int key) {
	if(!StackEmpty(ps)) {
		int temp = 0;
		Stack_t s;
		StackInit(&s);
		
		while(!StackEmpty(ps)) {
			StackPop(&temp, ps);
			if(temp != key) {
				StackPush(temp, &s);
			}
		}
		while(!StackEmpty(&s)) {
			StackPop(&temp, &s);
			StackPush(temp, ps);
		}
		
		ClearStack(&s);
	}
}


