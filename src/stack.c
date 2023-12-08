/*------------------------------------------------------------
  Project:
  File:
  Date:
  Author:
  Description:
*------------------------------------------------------------*/

#include "stack.h"

/**
Checks if the stack is full
@param Stack structure pointer
@return boolean expression if it's empty or not
**/
bool is_full(stack *stack_object_ptr){
  //printf("%d\n", stack_object_ptr->sp);
  //printf("%d\n", stack_object_ptr->capacity);

  if(stack_object_ptr->sp == stack_object_ptr->capacity){
    return true;
  }

  return false;
}

/**
Checks if the stack is empty
@param Stack structure pointer
@return boolean expression if it's empty or not
**/
bool is_empty(stack *stack_object_ptr){
  if(stack_object_ptr->sp <= -1){
    return false;
  }

  return true;
}

/**
Initalize data for the stack structure
@param Stack structure
**/
void initalize_data(stack *stack_object_ptr){

  if(is_empty(stack_object_ptr)){
    stack_object_ptr->capacity = 100;
    stack_object_ptr->data = (int*) malloc(stack_object_ptr->capacity * sizeof(int));
    stack_object_ptr->sp = -1;
  }
}

/**
*Pushes integer values onto the stack
*@param stack structure and data to be pushed onto the stack
**/
void push(stack *stack_object_ptr, int value){
  if(is_full(stack_object_ptr)){
    printf("Error: StackOverflow\n!");
  }

  else{
    stack_object_ptr->sp = stack_object_ptr->sp++;
    stack_object_ptr->data[stack_object_ptr->sp] = value;
  }
}
