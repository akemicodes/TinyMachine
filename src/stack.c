/*------------------------------------------------------------
  Project:        TinyMachine
  File:           stack.c
  Date:           12/7/23
  Author:         akemi
  Description:
  Header of the stack data structure that allows us
  to initalize, push and pop data
*------------------------------------------------------------*/

#include "stack.h"

/**
Checks if the stack is full
@param Stack structure pointer
@return boolean expression if it's empty or not
**/
bool is_full(stack *stack_object_ptr){
  return stack_object_ptr->sp == stack_object_ptr->capacity - 1;
}

/**
Checks if the stack is empty
@param Stack structure pointer
@return boolean expression if it's empty or not
**/
bool is_empty(stack *stack_object_ptr){
  return stack_object_ptr->sp == -1;
}

/**
Initalize data for the stack structure
@param Stack structure
**/
void initalize_data(stack *stack_object_ptr){
    stack_object_ptr->sp = -1;
    stack_object_ptr->capacity = 100;
    stack_object_ptr->data = (int*) malloc(stack_object_ptr->capacity * sizeof(int));
    
    if(stack_object_ptr == NULL){
      fprintf(stderr, "Memory allocation failed!");
    }
}

/**
*Pushes integer values onto the stack
*@param stack structure and data to be pushed onto the stack
**/
void push(stack *stack_object_ptr, int value){
  
  //stack_object_ptr->sp = stack_object_ptr->sp++;
  stack_object_ptr->data[++stack_object_ptr->sp] = value;
  
}

/**
*Pops the value that exists at the top of the stack
@param stack structure pointer
**/
int pop(stack *stack_object_ptr){
  if(is_empty(stack_object_ptr)){
    printf("Error: StackUnderFlow");
    return -1;
  }
  
  return stack_object_ptr->data[stack_object_ptr->sp--]; 
}

/**
*Displays the stack
*@param stack structure pointer
**/
void display_stack(stack *stack_object_ptr){
  int i = 0;
  printf("------------------------------------------------------------\n");
  printf("Memory Address: \t Value: \n");
  while(!is_empty(stack_object_ptr)){
    printf("%X \t\t  %d \n", (void*) &stack_object_ptr->data[stack_object_ptr->sp], stack_object_ptr->data[stack_object_ptr->sp]);
    pop(stack_object_ptr);
  }
}

/**
* Free memory that is no longer needed
@param stack structure pointer
**/
void destroy_stack(stack *stack_object_ptr){
  free(stack_object_ptr->data);
  stack_object_ptr->data = NULL;
  stack_object_ptr->sp = -1;
  stack_object_ptr->capacity = 0;
}
