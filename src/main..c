#include <stdio.h>
#include "opcodes.h"
#include "stack.h"

int main(){
  stack stack_object;
  initalize_data(&stack_object);
  int program[10] = {0x10, 0x07, 0x10, 0x07, 0x60};
  int length = sizeof(program) / sizeof(program[0]);

  // Read the program
  for(int i = 0; i < length; i++){
    switch(program[i]){
      case  bipush:
        push(&stack_object, program[++i]);
        printf("%X has been pushed to the stack at memory address %p \n", program[i], (void*)&stack_object.data[i]);
        break;

      case iadd:
        break;
    }
  } 
}
