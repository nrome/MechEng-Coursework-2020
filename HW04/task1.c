#include "structs.h"

int main() { 

  // Print sizeof -- in bytes -- stuct A
  printf("A struct size: %ld", sizeof(struct A));

  // Force line break
  printf("\n");

  // Print sizeof -- in bytes -- stuct B
  printf("B struct size: %ld", sizeof(struct B));

  // Force line break
  printf("\n");

  // Set pointer alias for struct A
  struct A *structA;
  
  // Allocate struct A in the heap w/ malloc
  structA = (struct A *)malloc(sizeof(struct A));

  // Assign struct fields a value
  structA->i = 100;
  structA->c = 'c';
  structA->d = 98.5;

  // Assign order from structs.h
  printf("Value of i: %d\n", structA->i);
  printf("Value of c: %c\n", structA->c);
  printf("Value of d: %f\n", structA->d);

  // Does this release our struct memory correctly?
  free(structA);

  return 0;

} 
