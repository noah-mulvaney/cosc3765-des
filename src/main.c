// COSC3765 Final Project: DES Implementation
// Main File
// Noah Mulvaney
// 7 Apr 2024

#include <stdio.h>

#include "block.h"

int main(int argc, char** argv) {
  printf("Hello, world!\n");

  char test[] = {0xff, 0x00, 0xff};
  print_block(test, 24);
  bit(0, 8, test, test);
  print_block(test, 24);
  bit(14, 1, test, test);
  print_block(test, 24);

  return 0;
}
