/*------------------------------------------------------------
  Project:        TinyMachine
  File:           stack.h
  Date:           12/7/23
  Author:         akemi
  Description:
  Header of the stack data structure that allows us
  to initalize, push and pop data
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
int  pop(stack* stack_object_ptr);
    
void initalize_data(stack *stack_object_ptr);
void push(stack *stack_object_ptr, int value_ptr);
void display_stack(stack *stack_object_ptr);
void destroy_stack(stack *stack_object_ptr);
