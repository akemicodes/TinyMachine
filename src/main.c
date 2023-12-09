/*------------------------------------------------------------
  Project:        TinyMachine
  File:           main.c
  Date:           12/7/23
  Author:         akemi
  Description:
  Main file that contains the core of our program
*------------------------------------------------------------*/

#include <stdio.h>
#include "opcodes.h"
#include "stack.h"

int main(){
  stack stack_object;
  initalize_data(&stack_object);
  int program[10] = {0x10, 0x05, 0x10, 0x05, 0x10, 0xF, 0x60};
  int length = sizeof(program) / sizeof(program[0]);

  // Read the program
  for(int i = 0; i < length; i++){
    switch(program[i]){
      case  bipush:
        push(&stack_object, program[++i]);
        printf("%X has been pushed to the stack at memory address %p \n", program[i], (void*)&stack_object.data[i]);
        break;

      case iadd:
        int a = pop(&stack_object);
        int b = pop(&stack_object);
        int sum = a + b;
        push(&stack_object, sum);
        break;
    }
  }
  
  display_stack(&stack_object);
  destroy_stack(&stack_object);
}
