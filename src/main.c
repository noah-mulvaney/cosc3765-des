// COSC3765 Final Project: DES Implementation
// Main File
// Noah Mulvaney
// 19 Apr 2024

#include <stdio.h>

#include "block.h"

void test_block();

int main(int argc, char** argv) {
  printf("Hello, world!\n");
  test_block();

  return 0;
}

void test_block() {
  ubyte test[] = {0x80, 0x55, 0xaa};
  print_block(test, 24);
  for (int i = 0; i < 3; ++i) {
    ubyte tmp[] = {0x00, 0xff};

    for (int j = 0; j < 16; ++j)
      bit(j, i * 8 + j % 8, tmp, test);

    print_block(tmp, 16);
  }
}
