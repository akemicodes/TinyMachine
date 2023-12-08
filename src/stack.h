/*------------------------------------------------------------
  Project:
  File:
  Date:
  Author:
  Description:
*------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  int sp;
  int capacity;
  int *data;
} stack;

bool is_full(stack *stack_object_ptr);
bool is_empty(stack *stack_object_ptr);

void initalize_data(stack *stack_object_ptr);
void push(stack *stack_object, int value_ptr);
void pop(stack* stack_object_ptr);
